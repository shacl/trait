add_executable(shacl.trait.DivisionDefined.test DivisionDefined.test.cpp)

target_link_libraries(shacl.trait.DivisionDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.DivisionDefined.test
  COMMAND shacl.trait.DivisionDefined.test)
