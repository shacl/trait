#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Yes {
  bool operator[](int) { return true; }
};

struct No {};

SCENARIO("SubscriptResult"){
  GIVEN("a subscript-able type"){
    THEN(
      "SubscriptResult has a nested alias named 'type' referring"
      " to the result of dereferencing an instance of the type"){
      REQUIRE(std::is_same
              <bool, typename shacl::trait::SubscriptResult<Yes>::type>::value);
      REQUIRE(std::is_same
              <bool, shacl::trait::SubscriptResult_t<Yes>>::value);
    }
  }

  GIVEN("a subscript-able type"){
    THEN("SubscriptResult has a no nested alias named 'type'"){
      REQUIRE_FALSE(shacl::trait::HasType_v<shacl::trait::SubscriptResult<No>>);
    }
  }
}
