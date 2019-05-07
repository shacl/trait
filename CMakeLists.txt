cmake_minimum_required(VERSION 3.12)

set(subproject OFF)
if(DEFINED PROJECT_NAME)
  set(subproject ON)
endif()

project(shacl-trait
  VERSION 2.0.0
  DESCRIPTION "A C++ type trait template library"
  HOMEPAGE_URL "https://xcp-stash.lanl.gov/projects/SCL/repos/trait"
  LANGUAGES CXX)

include(CTest)
include(CMakePackageConfigHelpers)
include(CMakeDependentOption)

CMAKE_DEPENDENT_OPTION(shacl.trait.tests
  "Build the trait tests and integrate with ctest"
  ON "BUILD_TESTING; NOT subproject" OFF)

add_library(trait INTERFACE)
add_library(shacl::trait ALIAS trait)

if(shacl.trait.tests)
  list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/.cmake")
  include(Git/Submodule/Packages)
  include(Warnings)
  include(Sanitizers)

  configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/CTestCustom.cmake"
    "${PROJECT_BINARY_DIR}/CTestCustom.cmake"
    COPYONLY)

  set(CMAKE_CXX_EXTENSIONS OFF)

  add_library(shacl::trait::testing IMPORTED INTERFACE)

  set_target_properties(shacl::trait::testing PROPERTIES
    INTERFACE_WARN_ALL ON
    INTERFACE_WARN_ERROR ON)

  set_property(TARGET shacl::trait::testing APPEND PROPERTY
    COMPATIBLE_INTERFACE_BOOL WARN_ALL WARN_ERROR)

  find_package(Catch2 REQUIRED)

  target_link_libraries(shacl::trait::testing INTERFACE
    shacl::cmake::Warnings_CXX
    shacl::cmake::Sanitizers_CXX
    Catch2::Catch2
    shacl::trait)
endif()

target_compile_features(trait INTERFACE cxx_std_14)

include(GNUInstallDirs)

string(CONCAT prefix
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_include_directories(trait INTERFACE "${prefix}")

add_subdirectory(include/shacl)

install(DIRECTORY include/
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  FILES_MATCHING PATTERN "*.hpp"
  PATTERN "*test*" EXCLUDE)

install(FILES
  "${PROJECT_SOURCE_DIR}/.cmake/shacl-config.cmake"
  DESTINATION share/cmake/shacl)

install(TARGETS trait EXPORT traitTargets)

install(EXPORT traitTargets
  FILE "shacl-trait-targets.cmake"
  NAMESPACE shacl::
  DESTINATION share/cmake/shacl-trait)

write_basic_package_version_file("shacl-trait-config-version.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(FILES
  "${PROJECT_SOURCE_DIR}/cmake/shacl-trait-config.cmake"
  "${PROJECT_BINARY_DIR}/shacl-trait-config-version.cmake"
  DESTINATION share/cmake/shacl-trait)

if(NOT subproject)
  set(CPACK_PACKAGE_VENDOR "Los Alamos National Laboratory")
  set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
  set(CPACK_PACKAGE_CONTACT "amccartney@lanl.gov")
  include(CPack)
endif()
