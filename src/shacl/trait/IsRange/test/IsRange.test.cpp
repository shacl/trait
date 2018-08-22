#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

#include <vector>
#include <string>

SCENARIO("IsRange"){
  GIVEN("a type with a defined iteration"){
    SECTION("std::string"){
      constexpr bool isRange = shacl::trait::IsRange_v<std::string>;
      REQUIRE(isRange);
    }
    SECTION("std::vector"){
      constexpr bool isRange = shacl::trait::IsRange_v<std::vector<int>>;
      REQUIRE(isRange);
    }
  }
  GIVEN("a type without defined iteration"){
    constexpr bool isRange = shacl::trait::IsRange_v<int>;
    REQUIRE(not isRange);
  }
}
