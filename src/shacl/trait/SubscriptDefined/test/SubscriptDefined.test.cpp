#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Yes {
  bool operator[](int) { return true; }
};

struct No {};

SCENARIO("SubscriptDefined"){
  GIVEN("a subscript-able type"){
    THEN("SubscriptDefined has a nested boolean name 'value' equal to true"){
      REQUIRE(shacl::trait::SubscriptDefined<Yes>::value);
      REQUIRE(shacl::trait::SubscriptDefined_v<Yes>);
    }
  }

  GIVEN("a subscript-able type"){
    THEN("SubscriptDefined has a nested boolean name 'value' equal to false"){
      REQUIRE_FALSE(shacl::trait::SubscriptDefined<No>::value);
      REQUIRE_FALSE(shacl::trait::SubscriptDefined_v<No>);
    }
  }
}
