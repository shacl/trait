add_executable(shacl.trait.getterResult.test getterResult.test.cpp)
target_link_libraries(shacl.trait.getterResult.test PUBLIC shacl::trait::testing)
add_test(NAME shacl.trait.getterResult.test COMMAND shacl.trait.getterResult.test)
