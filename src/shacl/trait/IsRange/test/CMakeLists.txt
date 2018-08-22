add_executable(shacl.trait.IsRange.test IsRange.test.cpp)

target_link_libraries(shacl.trait.IsRange.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.IsRange.test
  COMMAND shacl.trait.IsRange.test)
