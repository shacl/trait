add_executable(shacl.trait.MultiplicationDefined.test MultiplicationDefined.test.cpp)

target_link_libraries(shacl.trait.MultiplicationDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.MultiplicationDefined.test
  COMMAND shacl.trait.MultiplicationDefined.test)
