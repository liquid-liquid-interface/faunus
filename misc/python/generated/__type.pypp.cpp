// This file has been generated by Py++.

#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
#include "generated/generated_header.h"
#include "__type.pypp.hpp"

namespace bp = boost::python;

void register___type_class(){

    { //::std::vector< Faunus::particle::type >
        typedef bp::class_< std::vector< Faunus::particle::type > > __type_exposer_t;
        __type_exposer_t __type_exposer = __type_exposer_t( "__type" );
        bp::scope __type_scope( __type_exposer );
        __type_exposer.def( bp::vector_indexing_suite< ::std::vector< Faunus::particle::type >, true >() );
    }

}
