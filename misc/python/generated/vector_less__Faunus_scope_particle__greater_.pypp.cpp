// This file has been generated by Py++.

#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
#include "generated/generated_header.h"
#include "vector_less__Faunus_scope_particle__greater_.pypp.hpp"

namespace bp = boost::python;

void register_vector_less__Faunus_scope_particle__greater__class(){

    { //::std::vector< Faunus::particle >
        typedef bp::class_< std::vector< Faunus::particle > > vector_less__Faunus_scope_particle__greater__exposer_t;
        vector_less__Faunus_scope_particle__greater__exposer_t vector_less__Faunus_scope_particle__greater__exposer = vector_less__Faunus_scope_particle__greater__exposer_t( "vector_less__Faunus_scope_particle__greater_" );
        bp::scope vector_less__Faunus_scope_particle__greater__scope( vector_less__Faunus_scope_particle__greater__exposer );
        vector_less__Faunus_scope_particle__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< Faunus::particle > >() );
    }

}
