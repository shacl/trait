add_executable(shacl.trait.HasType.test HasType.test.cpp)
target_link_libraries(shacl.trait.HasType.test PUBLIC shacl::trait::testing)
add_test(NAME shacl.trait.HasType.test COMMAND shacl.trait.HasType.test)
