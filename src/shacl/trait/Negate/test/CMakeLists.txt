add_executable(shacl.trait.Negate.test Negate.test.cpp)
target_link_libraries(shacl.trait.Negate.test PUBLIC shacl::trait::testing)
add_test(NAME shacl.trait.Negate.test COMMAND shacl.trait.Negate.test)
