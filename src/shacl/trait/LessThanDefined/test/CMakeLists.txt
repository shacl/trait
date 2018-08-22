add_executable(shacl.trait.LessThanDefined.test LessThanDefined.test.cpp)

target_link_libraries(shacl.trait.LessThanDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.LessThanDefined.test
  COMMAND shacl.trait.LessThanDefined.test)
