#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  using type = int;
};

struct Protected : protected Does{};

struct Doesnt {};

SCENARIO("HasType"){
  GIVEN("a type with a defined nested 'type'"){
    THEN("the nested value is true"){
      constexpr bool hasType = shacl::trait::HasType_v<Does>;
      REQUIRE(hasType);
    }
  }

  GIVEN("a type without a defined nested 'type'"){
    THEN("the nested value is false"){
      constexpr bool hasType = shacl::trait::HasType_v<Doesnt>;
      REQUIRE(not hasType);
    }
  }

  /**
   * This test fails to compile under gcc-6.4 and gcc-7.1. Rather than fail
   * in an SFINAE-friendly fashion, gcc emits a hard error with a diagnostic.
   * It is unknown at this time, whether this behavior is standard conformant
   */
  // GIVEN("a type with a defined protected nested 'type'"){
  //   THEN("the nested value is false"){
  //     constexpr bool hasType = shacl::trait::HasType_v<Protected>;
  //     REQUIRE(not hasType);
  //   }
  // }
}
