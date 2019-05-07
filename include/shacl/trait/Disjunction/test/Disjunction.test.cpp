#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

SCENARIO("Disjunction"){
  GIVEN("a no arguments"){
    THEN("disjunction returns the identity element (false)"){
      REQUIRE_FALSE(shacl::trait::Disjunction_v<>);
    }
  }

  GIVEN("a single argument"){
    WHEN("true"){
      REQUIRE(shacl::trait::Disjunction_v<std::true_type>);
    }

    WHEN("false"){
      REQUIRE_FALSE(shacl::trait::Disjunction_v<std::false_type>);
    }
  }

  GIVEN("a multiple arguments"){
    WHEN("true true"){
      REQUIRE(shacl::trait::Disjunction_v<std::true_type, std::true_type>);
    }

    WHEN("true false"){
      REQUIRE(shacl::trait::Disjunction_v<std::true_type, std::false_type>);
    }

    WHEN("false true"){
      REQUIRE(shacl::trait::Disjunction_v<std::false_type, std::true_type>);
    }

    WHEN("false false"){
      REQUIRE_FALSE(shacl::trait::Disjunction_v<std::false_type, std::false_type>);
    }
  }
}
