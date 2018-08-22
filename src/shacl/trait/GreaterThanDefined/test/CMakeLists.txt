add_executable(shacl.trait.GreaterThanDefined.test GreaterThanDefined.test.cpp)

target_link_libraries(shacl.trait.GreaterThanDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.GreaterThanDefined.test
  COMMAND shacl.trait.GreaterThanDefined.test)
