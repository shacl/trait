#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

template<int>
struct Result{};

struct Other{};

struct EqualityComparable {
  Result<0> operator==(const EqualityComparable&) { return {}; }
  Result<1> operator==(const Other&) { return {}; }
};

SCENARIO("EqualityResult"){
  GIVEN("a equality comparable type"){
    THEN("the EqualityResult trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::EqualityResult<EqualityComparable>::type,
              Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::EqualityResult<EqualityComparable, Other>::type,
              Result<1>>::value);
    }

    THEN("the EqualityResult_t alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::EqualityResult_t<EqualityComparable>,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::EqualityResult_t<EqualityComparable, Other>,
               Result<1>>::value);
    }
  }

  GIVEN("a type not subject to equality comparison"){
    THEN("the EqualityResult trait will NOT have a nested type alias"){
      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::EqualityResult<Other>>);

      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::EqualityResult
                     <Other, EqualityComparable>>);
    }
  }
}
