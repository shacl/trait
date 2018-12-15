#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

#include <string>

struct Yes {
  std::integral_constant<int, 0> operator[](int) { return {}; }
  std::integral_constant<int, 1> operator[](const std::string&) { return {}; }
};

struct No {};

SCENARIO("SubscriptResult"){
  GIVEN("a subscript-able type"){
    THEN(
      "SubscriptResult has a nested alias named 'type' referring"
      " to the result of dereferencing an instance of the type"){
      REQUIRE(0 == shacl::trait::SubscriptResult<Yes>::typename type::value);
      REQUIRE(0 == shacl::trait::SubscriptResult_t<Yes>::value);
      REQUIRE(1 == shacl::trait::SubscriptResult
                   <Yes, std::string>::typename type::value);
      REQUIRE(1 == shacl::trait::SubscriptResult_t
                   <Yes, std::string>::value);
    }
  }

  GIVEN("a non-subscript-able type"){
    THEN("SubscriptResult has a no nested alias named 'type'"){
      REQUIRE_FALSE(shacl::trait::HasType_v<shacl::trait::SubscriptResult<No>>);
    }
  }
}
