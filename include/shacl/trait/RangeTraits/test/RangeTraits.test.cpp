#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

SCENARIO("RangeTraits"){
  GIVEN("a range"){
    const int range[5] = {1,2,3,4,5};
    
    using iterator_type = typename shacl::trait::RangeTraits< decltype(range) >::iterator_type;
    using sentinel_type = typename shacl::trait::RangeTraits< decltype(range) >::sentinel_type;

    using value_type = typename shacl::trait::RangeTraits< decltype(range) >::value_type;

    constexpr bool iterator_is_const_int_ptr = std::is_same<const int*, iterator_type>::value;
    REQUIRE( iterator_is_const_int_ptr );

    constexpr bool sentinel_is_const_int_ptr = std::is_same<const int*, sentinel_type>::value;
    REQUIRE( sentinel_is_const_int_ptr );

    constexpr bool value_is_int = std::is_same<int, value_type>::value;
    REQUIRE( value_is_int );
  }
}
