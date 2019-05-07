add_executable(shacl.trait.SubscriptResult.test SubscriptResult.test.cpp)

target_link_libraries(shacl.trait.SubscriptResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.SubscriptResult.test
  COMMAND shacl.trait.SubscriptResult.test)
