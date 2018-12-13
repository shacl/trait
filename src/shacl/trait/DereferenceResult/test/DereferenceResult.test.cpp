#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Dereferenceable {
  bool operator*() { return true; }
};

struct NotDereferenceable {};

SCENARIO("DereferenceResult"){
  GIVEN("a dereferenceable type"){
    using result_t = shacl::trait::Dereferenced_t<Dereferenceable>;
    constexpr bool affirmative = std::is_same<bool, result_t>::value;
    REQUIRE(affirmative);
  }

  GIVEN("a dereferenceable type"){
    using result_t = shacl::trait::DereferenceResult_t<Dereferenceable>;
    constexpr bool affirmative = std::is_same<bool, result_t>::value;
    REQUIRE(affirmative);
  }

  GIVEN("a non-dereferenceable type"){
    constexpr bool negative =
      shacl::trait::HasType_v<shacl::trait::Dereferenced<NotDereferenceable>>;
    REQUIRE_FALSE(negative);
  }

  GIVEN("a non-dereferenceable type"){
    constexpr bool negative =
      shacl::trait::HasType_v
      <shacl::trait::DereferenceResult<NotDereferenceable>>;
    REQUIRE_FALSE(negative);
  }
}
