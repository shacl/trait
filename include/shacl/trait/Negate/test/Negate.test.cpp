#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

SCENARIO("Negate"){
  GIVEN("a single argument"){
    WHEN("true"){ REQUIRE(shacl::trait::Negate_v<std::false_type>); }
    WHEN("false"){ REQUIRE_FALSE(shacl::trait::Negate_v<std::true_type>); }
  }
}
