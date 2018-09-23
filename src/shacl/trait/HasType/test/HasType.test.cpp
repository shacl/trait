#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  using type = int;
};

struct Doesnt {};

SCENARIO("HasType"){
  GIVEN("a type with a defined nested 'test'"){
    THEN("the nested value is true"){
      constexpr bool hasType = shacl::trait::HasType_v<Does>;
      REQUIRE(hasType);
    }
  }

  GIVEN("a type without a defined nested 'test'"){
    THEN("the nested value is false"){
      constexpr bool hasType = shacl::trait::HasType_v<Doesnt>;
      REQUIRE(not hasType);
    }
  }
}
