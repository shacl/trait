add_executable(shacl.trait.SubtractionDefined.test SubtractionDefined.test.cpp)

target_link_libraries(shacl.trait.SubtractionDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.SubtractionDefined.test
  COMMAND shacl.trait.SubtractionDefined.test)
