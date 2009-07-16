#ifndef FAU_POT_DEBYEHUCKELP3_H
#define FAU_POT_DEBYEHUCKELP3_H
#include "faunus/potentials/base.h"
#include "faunus/fortran.h"

namespace Faunus {
  /*! \brief Debye-Huckel potential for periodic boundry 
   *         conditions in 3D, it is extended to preform 
   *         under conditions of constant pressure.
   *         See class isobaric->markovmove.h
   *  \author Mikael Lund/Bjoern Persson
   *  \date Lund/Prag 2008
   *  \todo Remove pot_setop dependency
   */
  class pot_debyehuckelP3 : public pot_lj {
    protected:
      double I,k;
    public:
      double box, halfbox;
      pot_debyehuckelP3( inputfile &in ) : pot_lj(in) {
        f=in.getflt("bjerrum",7.1);
        k=1/in.getflt("debyelen",1.1e6);
        if ( 1/k>=1e6) {
          I=in.getflt("ionicstr",0);
          k=sqrt( 4*std::acos(-1)*f*6.022e23/1e27*2*I );
        }
        box=in.getflt("boxlen");
        halfbox=box/2;
        eps=eps/f;
        name+="/Debye-Huckel w. minimum image";
      }

      double inline f_exp(double x) {
        static double e=2.718281828;
        int tmp = (*(1 + (int *) &e));
        int tmp2 = (int)(x * (tmp - 1072632447) + 1072632447);
        double p = 0.0;
        *(1 + (int * ) &p) = tmp2;
        return p;
      }

      //! \f$ \beta u/f = \frac{z_1z_2}{r}\exp(-\kappa r) + u_{lj}/f \f$
      //! \return Energy in units of kT/lB
      inline double pairpot( const particle &p1, const particle &p2 ) {
        double r2=p1.sqdist(p2,box,halfbox),
               x=p1.radius+p2.radius, u=x*x/r2,
               r=sqrt(r2);
        x=u*u*u;
        return (x*x-x)*eps + p1.charge * p2.charge / r * f_exp(-k*r);
      }

      inline double sqdist(const point &p1, const point &p2) {
        return p1.sqdist(p2,box,halfbox);
      }

      void setvolume(double vol) {
        box=pow(vol, 1./3.);
        halfbox=box/2.;
      }

      virtual double VectorEnergy( double *r2, double *qq, int *len) {
        int n=*len;
        //std::cout << len << " ";
        double u=0;
        for (int i=1; i<n; i++) {
          double r = sqrt(r2[i]);
          double w = 4.0/r2[i];
          w = w*w*w; //6
          u += qq[i] / r * exp(-k*r) + eps*(w*w-w);
        }
        return f*u;
      }

      string info() {
        std::ostringstream o;
        o << pot_lj::info()
          << "#   Bjerrum length    = " << f     << endl
          << "#   Debye length      = " << 1./k  << endl
          << "#   Ionic strength (M)= " << k*k*1e27/(8*std::acos(-1)*f*6.022e23) << endl;
        return o.str();
      }
  };

  class pot_debyehuckelP3Fast : public pot_debyehuckelP3 {
    private:
      double r[4000];
    public:
      pot_debyehuckelP3Fast( inputfile &in ) : pot_debyehuckelP3(in) {
        gentab_();
        name+=" (FAST APPROX.!)";
      }
      double VectorEnergy( double *r2, double *qq, int *len) {
        int n=*len;
        double u=0, ik2=1/(k*k);
        // LJ Part
        //for (int i=1; i<n; i++) {
        //  double w = 4.0/r2[i];
        //  w = w*w*w; //6
        //  u+=eps*(w*w-w);
        //  r2[i] = r2[i]*ik2;
        //}
        // DH part
        vscoul_(r2,r,r2,len);
        for (int i=1; i<n; i++) {
          u += qq[i] * r[i] * k;
        }
        return f*u;
      }
  };

  class pot_debyehuckelP3trunk : public pot_lj_trunk {
    private:
      double I,k;
    public:
      double box, halfbox;
      pot_debyehuckelP3trunk( inputfile &in ) : pot_lj_trunk(in) {
        f=in.getflt("bjerrum",7.1);
        k=1/in.getflt("debyelen",1.1e6);
        if ( 1/k>=1e6) {
          I=in.getflt("ionicstr",0);
          k=sqrt( 4*std::acos(-1)*f*6.022e23/1e27*2*I );
        }
        box=in.getflt("boxlen");
        halfbox=box/2;
        eps=eps/f;
        name+="/Debye-Huckel w. minimum image, augmented with truncated LJ";
      }

      //! \f$ \beta u/f = \frac{z_1z_2}{r}\exp(-\kappa r) + u_{lj}/f \f$
      //! \return Energy in units of kT/lB
      inline double pairpot( const particle &p1, const particle &p2 ) const {
        double r2=p1.sqdist(p2,box,halfbox), r=sqrt(r2);
        return lj(p1,p2,r2) + p1.charge*p2.charge/r*exp(-k*r);
      }

      inline double sqdist(const point &p1, const point &p2) {
        return p1.sqdist(p2,box,halfbox);
      }

      void setvolume(double vol) {
        box=pow(vol, 1./3);
        halfbox=box/2.;
      }

      string info() {
        std::ostringstream o;
        o << pot_lj_trunk::info()
          << "#   Bjerrum length    = " << f     << endl
          << "#   Debye length      = " << 1./k  << endl
          << "#   Ionic strength (M)= " << k*k*1e27/(8*std::acos(-1)*f*6.022e23) << endl;
        return o.str();
      }
  };
}
#endif
