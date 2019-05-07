add_executable(shacl.trait.Quotient.test Quotient.test.cpp)

target_link_libraries(shacl.trait.Quotient.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Quotient.test
  COMMAND shacl.trait.Quotient.test)
