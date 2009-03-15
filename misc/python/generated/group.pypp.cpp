// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generated/generated_header.h"
#include "group.pypp.hpp"

namespace bp = boost::python;

struct group_wrapper : Faunus::group, bp::wrapper< Faunus::group > {

    group_wrapper(int arg0=0 )
    : Faunus::group( arg0 )
      , bp::wrapper< Faunus::group >(){
        // constructor
    
    }

    virtual double charge( ::std::vector< Faunus::particle > const & arg0 ) {
        if( bp::override func_charge = this->get_override( "charge" ) )
            return func_charge( boost::ref(arg0) );
        else
            return this->Faunus::group::charge( boost::ref(arg0) );
    }
    
    
    double default_charge( ::std::vector< Faunus::particle > const & arg0 ) {
        return Faunus::group::charge( boost::ref(arg0) );
    }

    virtual short unsigned int displace( ::Faunus::container & arg0, double arg1 ) {
        if( bp::override func_displace = this->get_override( "displace" ) )
            return func_displace( boost::ref(arg0), arg1 );
        else
            return this->Faunus::group::displace( boost::ref(arg0), arg1 );
    }
    
    
    short unsigned int default_displace( ::Faunus::container & arg0, double arg1 ) {
        return Faunus::group::displace( boost::ref(arg0), arg1 );
    }

    virtual ::std::string info(  ) {
        if( bp::override func_info = this->get_override( "info" ) )
            return func_info(  );
        else
            return this->Faunus::group::info(  );
    }
    
    
    ::std::string default_info(  ) {
        return Faunus::group::info( );
    }

    virtual void isobaricmove( ::Faunus::container & arg0, double arg1 ) {
        if( bp::override func_isobaricmove = this->get_override( "isobaricmove" ) )
            func_isobaricmove( boost::ref(arg0), arg1 );
        else
            this->Faunus::group::isobaricmove( boost::ref(arg0), arg1 );
    }
    
    
    void default_isobaricmove( ::Faunus::container & arg0, double arg1 ) {
        Faunus::group::isobaricmove( boost::ref(arg0), arg1 );
    }

    virtual short unsigned int nummolecules(  ) {
        if( bp::override func_nummolecules = this->get_override( "nummolecules" ) )
            return func_nummolecules(  );
        else
            return this->Faunus::group::nummolecules(  );
    }
    
    
    short unsigned int default_nummolecules(  ) {
        return Faunus::group::nummolecules( );
    }

    virtual short int random(  ) {
        if( bp::override func_random = this->get_override( "random" ) )
            return func_random(  );
        else
            return this->Faunus::group::random(  );
    }
    
    
    short int default_random(  ) {
        return Faunus::group::random( );
    }

};

void register_group_class(){

    { //::Faunus::group
        typedef bp::class_< group_wrapper, boost::noncopyable > group_exposer_t;
        group_exposer_t group_exposer = group_exposer_t( "group", bp::init< bp::optional< int > >(( bp::arg("arg0")=(int)(0) )) );
        bp::scope group_scope( group_exposer );
        bp::implicitly_convertible< int, Faunus::group >();
        { //::Faunus::group::accept
        
            typedef void ( ::Faunus::group::*accept_function_type )( ::Faunus::particles & ) ;
            
            group_exposer.def( 
                "accept"
                , accept_function_type( &::Faunus::group::accept )
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::group::add
        
            typedef void ( ::Faunus::group::*add_function_type )( ::Faunus::container &,::std::vector< Faunus::particle >,bool ) ;
            
            group_exposer.def( 
                "add"
                , add_function_type( &::Faunus::group::add )
                , ( bp::arg("arg0"), bp::arg("arg1"), bp::arg("arg2")=(bool)(false) ) );
        
        }
        { //::Faunus::group::add
        
            typedef void ( ::Faunus::group::*add_function_type )( ::Faunus::container &,::Faunus::particle::type,short int ) ;
            
            group_exposer.def( 
                "add"
                , add_function_type( &::Faunus::group::add )
                , ( bp::arg("arg0"), bp::arg("arg1"), bp::arg("arg2") ) );
        
        }
        { //::Faunus::group::charge
        
            typedef double ( ::Faunus::group::*charge_function_type )( ::std::vector< Faunus::particle > const & ) ;
            typedef double ( group_wrapper::*default_charge_function_type )( ::std::vector< Faunus::particle > const & ) ;
            
            group_exposer.def( 
                "charge"
                , charge_function_type(&::Faunus::group::charge)
                , default_charge_function_type(&group_wrapper::default_charge)
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::group::count
        
            typedef short int ( ::Faunus::group::*count_function_type )( ::std::vector< Faunus::particle > &,::Faunus::particle::type ) ;
            
            group_exposer.def( 
                "count"
                , count_function_type( &::Faunus::group::count )
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        { //::Faunus::group::displace
        
            typedef short unsigned int ( ::Faunus::group::*displace_function_type )( ::Faunus::container &,double ) ;
            typedef short unsigned int ( group_wrapper::*default_displace_function_type )( ::Faunus::container &,double ) ;
            
            group_exposer.def( 
                "displace"
                , displace_function_type(&::Faunus::group::displace)
                , default_displace_function_type(&group_wrapper::default_displace)
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        { //::Faunus::group::find
        
            typedef bool ( ::Faunus::group::*find_function_type )( unsigned int ) const;
            
            group_exposer.def( 
                "find"
                , find_function_type( &::Faunus::group::find )
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::group::info
        
            typedef ::std::string ( ::Faunus::group::*info_function_type )(  ) ;
            typedef ::std::string ( group_wrapper::*default_info_function_type )(  ) ;
            
            group_exposer.def( 
                "info"
                , info_function_type(&::Faunus::group::info)
                , default_info_function_type(&group_wrapper::default_info) );
        
        }
        { //::Faunus::group::isobaricmove
        
            typedef void ( ::Faunus::group::*isobaricmove_function_type )( ::Faunus::container &,double ) ;
            typedef void ( group_wrapper::*default_isobaricmove_function_type )( ::Faunus::container &,double ) ;
            
            group_exposer.def( 
                "isobaricmove"
                , isobaricmove_function_type(&::Faunus::group::isobaricmove)
                , default_isobaricmove_function_type(&group_wrapper::default_isobaricmove)
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        { //::Faunus::group::masscenter
        
            typedef ::Faunus::point ( ::Faunus::group::*masscenter_function_type )( ::std::vector< Faunus::particle > const & ) ;
            
            group_exposer.def( 
                "masscenter"
                , masscenter_function_type( &::Faunus::group::masscenter )
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::group::masscenter
        
            typedef ::Faunus::point ( ::Faunus::group::*masscenter_function_type )( ::Faunus::container & ) ;
            
            group_exposer.def( 
                "masscenter"
                , masscenter_function_type( &::Faunus::group::masscenter )
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::group::move
        
            typedef void ( ::Faunus::group::*move_function_type )( ::Faunus::container &,::Faunus::point ) ;
            
            group_exposer.def( 
                "move"
                , move_function_type( &::Faunus::group::move )
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        { //::Faunus::group::numhydrophobic
        
            typedef short unsigned int ( ::Faunus::group::*numhydrophobic_function_type )( ::std::vector< Faunus::particle > & ) ;
            
            group_exposer.def( 
                "numhydrophobic"
                , numhydrophobic_function_type( &::Faunus::group::numhydrophobic )
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::group::nummolecules
        
            typedef short unsigned int ( ::Faunus::group::*nummolecules_function_type )(  ) ;
            typedef short unsigned int ( group_wrapper::*default_nummolecules_function_type )(  ) ;
            
            group_exposer.def( 
                "nummolecules"
                , nummolecules_function_type(&::Faunus::group::nummolecules)
                , default_nummolecules_function_type(&group_wrapper::default_nummolecules) );
        
        }
        group_exposer.def( bp::self + bp::self );
        group_exposer.def( bp::self += bp::self );
        group_exposer.def( bp::self == bp::self );
        { //::Faunus::group::overlap
        
            typedef bool ( ::Faunus::group::*overlap_function_type )( ::Faunus::container & ) ;
            
            group_exposer.def( 
                "overlap"
                , overlap_function_type( &::Faunus::group::overlap )
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::group::random
        
            typedef short int ( ::Faunus::group::*random_function_type )(  ) ;
            typedef short int ( group_wrapper::*default_random_function_type )(  ) ;
            
            group_exposer.def( 
                "random"
                , random_function_type(&::Faunus::group::random)
                , default_random_function_type(&group_wrapper::default_random) );
        
        }
        { //::Faunus::group::set
        
            typedef void ( ::Faunus::group::*set_function_type )( short int,short int ) ;
            
            group_exposer.def( 
                "set"
                , set_function_type( &::Faunus::group::set )
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        { //::Faunus::group::size
        
            typedef short int ( ::Faunus::group::*size_function_type )(  ) const;
            
            group_exposer.def( 
                "size"
                , size_function_type( &::Faunus::group::size ) );
        
        }
        { //::Faunus::group::swap
        
            typedef bool ( ::Faunus::group::*swap_function_type )( ::Faunus::container &,::Faunus::group & ) ;
            
            group_exposer.def( 
                "swap"
                , swap_function_type( &::Faunus::group::swap )
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        { //::Faunus::group::undo
        
            typedef void ( ::Faunus::group::*undo_function_type )( ::Faunus::particles & ) ;
            
            group_exposer.def( 
                "undo"
                , undo_function_type( &::Faunus::group::undo )
                , ( bp::arg("arg0") ) );
        
        }
        group_exposer.def_readwrite( "beg", &Faunus::group::beg );
        group_exposer.def_readwrite( "cm", &Faunus::group::cm );
        group_exposer.def_readwrite( "cm_trial", &Faunus::group::cm_trial );
        group_exposer.def_readwrite( "end", &Faunus::group::end );
        group_exposer.def_readwrite( "name", &Faunus::group::name );
    }

}
