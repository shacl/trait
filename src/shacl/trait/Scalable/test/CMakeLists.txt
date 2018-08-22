add_executable(shacl.trait.Scalable.test Scalable.test.cpp)

target_link_libraries(shacl.trait.Scalable.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Scalable.test
  COMMAND shacl.trait.Scalable.test)
