#define CATCH_CONFIG_MAIN
#include "shacl/trait.hpp"
#include "catch2/catch.hpp"

SCENARIO("Compound"){
  GIVEN("a homogeneous collection of types"){
    using Result = shacl::trait::Compound<int, int, int>;
    REQUIRE(std::is_same<typename Result::type,
                         std::array<int, 3>>::value);

    using Result_t = shacl::trait::Compound_t<int, int, int>;
    REQUIRE(std::is_same<typename Result::type, Result_t>::value);
  }

  GIVEN("a heterogeneous collection of types"){
    using Result = shacl::trait::Compound<double, float>;
    REQUIRE(std::is_same<typename Result::type,
                         std::tuple<double, float>>::value);

    using Result_t = shacl::trait::Compound_t<double, float>;
    REQUIRE(std::is_same<typename Result::type, Result_t>::value);
  }
}
