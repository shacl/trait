#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Has {
  bool operator*() { return true; }
};

struct HasNot {};

SCENARIO("DereferenceDefined"){
  GIVEN("a dereferenceable type"){
    bool has_dereference = shacl::trait::DereferenceDefined_v<Has>;
    REQUIRE( has_dereference );
  }
  GIVEN("a non-dereferenceable type"){
    bool has_dereference = shacl::trait::DereferenceDefined_v<HasNot>;
    REQUIRE(not has_dereference );
  }
}
