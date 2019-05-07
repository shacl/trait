add_executable(shacl.trait.SubscriptDefined.test SubscriptDefined.test.cpp)

target_link_libraries(shacl.trait.SubscriptDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.SubscriptDefined.test
  COMMAND shacl.trait.SubscriptDefined.test)
