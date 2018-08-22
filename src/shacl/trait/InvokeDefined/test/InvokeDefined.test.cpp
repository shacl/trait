#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

#include <string>

struct Fn {
  void operator()(int){}
};

SCENARIO("InvokeDefined"){
  GIVEN("a callable and a compatible argument"){
    constexpr bool invocable = shacl::trait::InvokeDefined_v<Fn, int>;
    REQUIRE(invocable);
  }
  GIVEN("a callable and a incompatible argument"){
    constexpr bool invocable = shacl::trait::InvokeDefined_v<Fn, std::string>;
    REQUIRE(not invocable);
  }
}
