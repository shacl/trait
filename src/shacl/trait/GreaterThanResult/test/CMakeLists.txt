add_executable(shacl.trait.GreaterThanResult.test
  GreaterThanResult.test.cpp)

target_link_libraries(shacl.trait.GreaterThanResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.GreaterThanResult.test
  COMMAND shacl.trait.GreaterThanResult.test)
