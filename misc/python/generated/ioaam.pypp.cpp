// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generated/generated_header.h"
#include "ioaam.pypp.hpp"

namespace bp = boost::python;

struct ioaam_wrapper : Faunus::ioaam, bp::wrapper< Faunus::ioaam > {

    ioaam_wrapper(::Faunus::atoms & arg0 )
    : Faunus::ioaam( boost::ref(arg0) )
      , bp::wrapper< Faunus::ioaam >(){
        // constructor
    
    }

    virtual ::std::vector< Faunus::particle > load( ::std::string arg0 ) {
        if( bp::override func_load = this->get_override( "load" ) )
            return func_load( arg0 );
        else
            return this->Faunus::ioaam::load( arg0 );
    }
    
    
    ::std::vector< Faunus::particle > default_load( ::std::string arg0 ) {
        return Faunus::ioaam::load( arg0 );
    }

    virtual bool save( ::std::string arg0, ::std::vector< Faunus::particle > & arg1 ) {
        if( bp::override func_save = this->get_override( "save" ) )
            return func_save( arg0, boost::ref(arg1) );
        else
            return this->Faunus::ioaam::save( arg0, boost::ref(arg1) );
    }
    
    
    bool default_save( ::std::string arg0, ::std::vector< Faunus::particle > & arg1 ) {
        return Faunus::ioaam::save( arg0, boost::ref(arg1) );
    }

};

void register_ioaam_class(){

    { //::Faunus::ioaam
        typedef bp::class_< ioaam_wrapper, boost::noncopyable > ioaam_exposer_t;
        ioaam_exposer_t ioaam_exposer = ioaam_exposer_t( "ioaam", bp::init< Faunus::atoms & >(( bp::arg("arg0") )) );
        bp::scope ioaam_scope( ioaam_exposer );
        bp::implicitly_convertible< Faunus::atoms &, Faunus::ioaam >();
        { //::Faunus::ioaam::load
        
            typedef ::std::vector< Faunus::particle > ( ::Faunus::ioaam::*load_function_type )( ::std::string ) ;
            typedef ::std::vector< Faunus::particle > ( ioaam_wrapper::*default_load_function_type )( ::std::string ) ;
            
            ioaam_exposer.def( 
                "load"
                , load_function_type(&::Faunus::ioaam::load)
                , default_load_function_type(&ioaam_wrapper::default_load)
                , ( bp::arg("arg0") ) );
        
        }
        { //::Faunus::ioaam::load
        
            typedef void ( ::Faunus::ioaam::*load_function_type )( ::Faunus::container &,::Faunus::inputfile &,::std::vector< Faunus::macromolecule > & ) ;
            
            ioaam_exposer.def( 
                "load"
                , load_function_type( &::Faunus::ioaam::load )
                , ( bp::arg("arg0"), bp::arg("arg1"), bp::arg("arg2") ) );
        
        }
        { //::Faunus::ioaam::load
        
            typedef bool ( ::Faunus::ioaam::*load_function_type )( ::Faunus::container &,::std::string ) ;
            
            ioaam_exposer.def( 
                "load"
                , load_function_type( &::Faunus::ioaam::load )
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        { //::Faunus::ioaam::loadlattice
        
            typedef void ( ::Faunus::ioaam::*loadlattice_function_type )( ::Faunus::container &,::Faunus::inputfile &,::std::vector< Faunus::macromolecule > & ) ;
            
            ioaam_exposer.def( 
                "loadlattice"
                , loadlattice_function_type( &::Faunus::ioaam::loadlattice )
                , ( bp::arg("arg0"), bp::arg("arg1"), bp::arg("arg2") ) );
        
        }
        { //::Faunus::ioaam::save
        
            typedef bool ( ::Faunus::ioaam::*save_function_type )( ::std::string,::std::vector< Faunus::particle > & ) ;
            typedef bool ( ioaam_wrapper::*default_save_function_type )( ::std::string,::std::vector< Faunus::particle > & ) ;
            
            ioaam_exposer.def( 
                "save"
                , save_function_type(&::Faunus::ioaam::save)
                , default_save_function_type(&ioaam_wrapper::default_save)
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
    }

}
