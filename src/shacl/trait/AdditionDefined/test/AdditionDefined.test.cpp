#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  bool operator+(const Does&) const {
    return false;
  }
};

struct Doesnt {};

struct Right {};

struct Left {
  bool operator+(Right);
};

SCENARIO("Is + operator defined between two instances of a given type"){ 
  GIVEN("a type with a defined addition operator"){
    constexpr bool hasAddition = shacl::trait::AdditionDefined_v<Does>;
    REQUIRE(hasAddition);
  }
  GIVEN("a type without a defined addition operator"){
    constexpr bool hasAddition = shacl::trait::AdditionDefined_v<Doesnt>;
    REQUIRE(not hasAddition);
  }
}

SCENARIO("Is + operator defined between two instances of two distinct types"){   
  GIVEN("a pair of types with a defined addition operator - a + b is defined"){
    constexpr bool hasAddition =
      shacl::trait::AdditionDefined_v<Left, Right>;
    REQUIRE(hasAddition);
  }
  GIVEN("a pair of types without a defined addition operator"){
    constexpr bool hasAddition =
      shacl::trait::AdditionDefined_v<Right, Left>;
    REQUIRE(not hasAddition);
  }
}
