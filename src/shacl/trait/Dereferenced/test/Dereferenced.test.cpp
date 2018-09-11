#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Dereferenceable {
  bool operator*() { return true; }
};

struct NotDereferenceable {};

template<typename T, typename = shacl::trait::void_t<typename T::type> >
bool has_nested_type(T) { return true; }

template<typename... T>
bool has_nested_type(T...) { return false; }

SCENARIO("Dereferenced"){
  GIVEN("a dereferenceable type"){
    using result_t = shacl::trait::Dereferenced_t<Dereferenceable>;
    constexpr bool affirmative = std::is_same<bool, result_t>::value;
    REQUIRE( affirmative );
  }
  GIVEN("a non-dereferenceable type"){
    bool negative = has_nested_type( shacl::trait::Dereferenced<NotDereferenceable>{} );
    REQUIRE(not negative );
  }
}
