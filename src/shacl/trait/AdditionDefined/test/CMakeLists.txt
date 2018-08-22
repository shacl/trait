add_executable(shacl.trait.AdditionDefined.test AdditionDefined.test.cpp)

target_link_libraries(shacl.trait.AdditionDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.AdditionDefined.test
  COMMAND shacl.trait.AdditionDefined.test)
