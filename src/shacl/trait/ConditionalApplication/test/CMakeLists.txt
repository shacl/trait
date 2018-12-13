add_executable(shacl.trait.ConditionalApplication.test
  ConditionalApplication.test.cpp)

target_link_libraries(shacl.trait.ConditionalApplication.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.ConditionalApplication.test
  COMMAND shacl.trait.ConditionalApplication.test)
