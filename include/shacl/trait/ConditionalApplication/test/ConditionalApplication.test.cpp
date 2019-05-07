#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

template<typename... Ts>
struct Yes {};

template<typename... Ts>
struct No {};

SCENARIO("ConditionalApplication"){
  SECTION("'true' branch"){
    using Result =
      typename shacl::trait::ConditionalApplication
      <true, Yes, No, int, double, char>::type;

    REQUIRE(std::is_same<Result, Yes<int, double, char>>::value);

    using Result_t =
      shacl::trait::ConditionalApplication_t<true, Yes, No, int, double, char>;

    REQUIRE(std::is_same<Result_t, Result>::value);
  }

  SECTION("'false' branch"){
    using Result =
      typename shacl::trait::ConditionalApplication
      <false, Yes, No, int, double, char>::type;

    REQUIRE(std::is_same<Result, No<int, double, char>>::value);

    using Result_t =
      shacl::trait::ConditionalApplication_t<false, Yes, No, int, double, char>;

    REQUIRE(std::is_same<Result_t, Result>::value);
  }
}
