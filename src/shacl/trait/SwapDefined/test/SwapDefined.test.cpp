#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

namespace useStd {
struct Yes {};

namespace no {
struct Ctor {
  Ctor(Ctor&&) = delete;
  Ctor& operator=(Ctor&&){ return *this; }
};

struct Assignment {
  Assignment(Assignment&&) = delete;
  Assignment& operator=(Assignment&&){ return *this; };
};
}
}

namespace useAdl {
struct Yes {
  Yes(int x) : x(x) {}
  ~Yes() {}

  Yes(const Yes&) = delete;
  Yes(Yes&&) = delete;

  friend void swap(Yes& rhs, Yes& lhs) { std::swap(rhs.x, lhs.x); }
  int x;
};

struct No {
  friend void swap(No& rhs, No& lhs) = delete;
};
}

SCENARIO("SwapDefined"){
  GIVEN("a class with a default swap"){
    THEN("the swap-detection trait will return true"){
      REQUIRE(shacl::trait::SwapDefined_v<useStd::Yes>);
    }

    GIVEN("an array"){
      THEN("the swap-detection trait will return true"){
        REQUIRE(shacl::trait::SwapDefined_v<useStd::Yes[10]>);
      }
    }
  }

  GIVEN("a class with deleted move construction"){
    THEN("the default swap is not defined"){
      AND_THEN("the swap-detection trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapDefined_v<useStd::no::Ctor>);
      }

      GIVEN("an array"){
        THEN("the swap-detection trait will return false"){
          REQUIRE_FALSE(shacl::trait::SwapDefined_v<useStd::no::Ctor[10]>);
        }
      }
    }
  }

  GIVEN("a class with deleted move assignment"){
    THEN("the default swap is not defined"){
      AND_THEN("the swap-detection trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapDefined_v<useStd::no::Assignment>);
      }

      GIVEN("an array"){
        THEN("the swap-detection trait will return false"){
          REQUIRE_FALSE(shacl::trait::SwapDefined_v<useStd::no::Assignment[10]>);
        }
      }
    }
  }

  GIVEN("a class with deleted move assignment and move constructor"){
    GIVEN("an explicit definition for swap is available"
          " via argument-dependent lookup"){
      THEN("the swap-detection trait will return true"){
        REQUIRE(shacl::trait::SwapDefined_v<useAdl::Yes>);
      }

      GIVEN("an array"){
        THEN("the swap-detection trait will return true"){
          REQUIRE(shacl::trait::SwapDefined_v<useAdl::Yes[10]>);
        }
      }
    }
  }

  GIVEN("a class with an explicitly deleted adl swap"){
    THEN("the swap-detection trait will return false"){
      REQUIRE_FALSE(shacl::trait::SwapDefined_v<useAdl::No>);
    }

    GIVEN("an array"){
      THEN("the swap-detection trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapDefined_v<useAdl::No[10]>);
      }
    }
  }
}
