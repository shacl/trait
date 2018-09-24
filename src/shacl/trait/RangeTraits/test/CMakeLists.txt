add_executable(shacl.trait.RangeTraits.test RangeTraits.test.cpp)

target_link_libraries(shacl.trait.RangeTraits.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.RangeTraits.test
  COMMAND shacl.trait.RangeTraits.test)
