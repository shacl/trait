#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

#include <string>

struct Yes {
  std::integral_constant<int, 0> operator[](int) { return {}; }
  std::integral_constant<int, 1> operator[](const std::string&) { return {}; }
};

struct No {};

SCENARIO("SubscriptDefined"){
  GIVEN("a subscript-able type"){
    THEN("SubscriptDefined has a nested boolean name 'value' equal to true"){
      REQUIRE(shacl::trait::SubscriptDefined<Yes>::value);
      REQUIRE(shacl::trait::SubscriptDefined_v<Yes>);
      REQUIRE(shacl::trait::SubscriptDefined<Yes, std::string>::value);
      REQUIRE(shacl::trait::SubscriptDefined_v<Yes, std::string>);
    }
  }

  GIVEN("a non-subscript-able type"){
    THEN("SubscriptDefined has a nested boolean name 'value' equal to false"){
      REQUIRE_FALSE(shacl::trait::SubscriptDefined<No>::value);
      REQUIRE_FALSE(shacl::trait::SubscriptDefined_v<No>);
    }
  }
}
