add_executable(shacl.trait.LessThanResult.test LessThanResult.test.cpp)

target_link_libraries(shacl.trait.LessThanResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.LessThanResult.test
  COMMAND shacl.trait.LessThanResult.test)
