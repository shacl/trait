add_executable(shacl.trait.Comparable.test
  Comparable.test.cpp)

target_link_libraries(shacl.trait.Comparable.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Comparable.test
  COMMAND shacl.trait.Comparable.test)
