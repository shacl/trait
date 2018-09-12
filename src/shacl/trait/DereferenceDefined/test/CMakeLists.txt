add_executable(shacl.trait.DereferenceDefined.test DereferenceDefined.test.cpp)

target_link_libraries(shacl.trait.DereferenceDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.DereferenceDefined.test
  COMMAND shacl.trait.DereferenceDefined.test)
