add_executable(shacl.trait.EqualityDefined.test EqualityDefined.test.cpp)

target_link_libraries(shacl.trait.EqualityDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.EqualityDefined.test
  COMMAND shacl.trait.EqualityDefined.test)
