add_executable(shacl.trait.IsInteger.test IsInteger.test.cpp)

target_link_libraries(shacl.trait.IsInteger.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.IsInteger.test
  COMMAND shacl.trait.IsInteger.test)
