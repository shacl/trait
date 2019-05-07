#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Dereferenceable {
  bool operator*() { return true; }
};

struct NotDereferenceable {};

SCENARIO("DereferenceResult"){
  GIVEN("a dereferenceable type"){
    THEN("the Dereferenced trait will have a nested type alias"){
      constexpr bool affirmative =
        shacl::trait::HasType_v<shacl::trait::Dereferenced<Dereferenceable>>;
      REQUIRE(affirmative);
    }

    THEN("the Derefenced trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::Dereferenced<Dereferenceable>::type, bool>::value);
    }

    THEN("the Dereferenced_t alias will refer to the correct type"){
      using result_t = shacl::trait::Dereferenced_t<Dereferenceable>;
      constexpr bool affirmative = std::is_same<bool, result_t>::value;
      REQUIRE(affirmative);
    }

    THEN("the DereferenceResult trait will have a nested type alias"){
      constexpr bool affirmative =
        shacl::trait::HasType_v
        <shacl::trait::DereferenceResult<Dereferenceable>>;
      REQUIRE(affirmative);
    }

    THEN("the Derefenced trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::DereferenceResult
               <Dereferenceable>::type, bool>::value);
    }

    THEN("the DereferenceResult_t alias will refer to the correct type"){
      using result_t = shacl::trait::DereferenceResult_t<Dereferenceable>;
      constexpr bool affirmative = std::is_same<bool, result_t>::value;
      REQUIRE(affirmative);
    }
  }

  GIVEN("a non-dereferenceable type"){
    THEN("the Dereferenced trait will NOT have a nested type alias"){
      constexpr bool negative =
        shacl::trait::HasType_v<shacl::trait::Dereferenced<NotDereferenceable>>;
      REQUIRE_FALSE(negative);
    }

    THEN("the DereferenceResult trait will NOT have a nested type alias"){
      constexpr bool negative =
        shacl::trait::HasType_v
        <shacl::trait::DereferenceResult<NotDereferenceable>>;
      REQUIRE_FALSE(negative);
    }
  }
}
