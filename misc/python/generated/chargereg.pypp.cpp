// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generated/generated_header.h"
#include "chargereg.pypp.hpp"

namespace bp = boost::python;

struct chargereg_wrapper : Faunus::chargereg, bp::wrapper< Faunus::chargereg > {

    chargereg_wrapper(Faunus::chargereg const & arg )
    : Faunus::chargereg( arg )
      , bp::wrapper< Faunus::chargereg >(){
        // copy constructor
        
    }

    chargereg_wrapper(::Faunus::ensemble & arg0, ::Faunus::container & arg1, ::Faunus::energybase & arg2, ::Faunus::group & arg3, float arg4 )
    : Faunus::chargereg( boost::ref(arg0), boost::ref(arg1), boost::ref(arg2), boost::ref(arg3), arg4 )
      , bp::wrapper< Faunus::chargereg >(){
        // constructor
    
    }

    virtual ::std::string info(  ) {
        if( bp::override func_info = this->get_override( "info" ) )
            return func_info(  );
        else
            return this->Faunus::chargereg::info(  );
    }
    
    
    ::std::string default_info(  ) {
        return Faunus::chargereg::info( );
    }

};

void register_chargereg_class(){

    bp::class_< chargereg_wrapper, bp::bases< Faunus::markovmove, Faunus::titrate > >( "chargereg", bp::init< Faunus::ensemble &, Faunus::container &, Faunus::energybase &, Faunus::group &, float >(( bp::arg("arg0"), bp::arg("arg1"), bp::arg("arg2"), bp::arg("arg3"), bp::arg("arg4") )) )    
        .def( 
            "info"
            , (::std::string ( ::Faunus::chargereg::* )(  ) )(&::Faunus::chargereg::info)
            , (::std::string ( chargereg_wrapper::* )(  ) )(&chargereg_wrapper::default_info) )    
        .def( 
            "titrateall"
            , (double ( ::Faunus::chargereg::* )(  ) )( &::Faunus::chargereg::titrateall ) );

}