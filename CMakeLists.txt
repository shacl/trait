cmake_minimum_required(VERSION 3.12)

set(subproject OFF)
if(DEFINED PROJECT_NAME)
  set(subproject ON)
endif()

project(shacl-trait
  VERSION 2.1.0
  DESCRIPTION "A C++ type trait template library"
  HOMEPAGE_URL "https://xcp-stash.lanl.gov/projects/SCL/repos/trait"
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/.cmake")

include(CTest)
include(CMakePackageConfigHelpers)
include(CMakeDependentOption)
include(DependentDelegatingOption)

#
# The file referenced in this block used by version branches of shacl::trait to
# fix the version of the dependencies found by the find_package overload
# provided by Git Submodule Packages.
#
# Currently, shacl::trait has no dependencies. That said, this block provides
# some degree of forward compatability should a dependency become useful and
# allows for uniformity between shacl projects.
#
if(EXISTS "${PROJECT_SOURCE_DIR}/cmake/specification.cmake")
  set(git.submodule.packages.specification
    "${PROJECT_SOURCE_DIR}/cmake/specification.cmake" CACHE FILEPATH
    "(READ ONLY) Path to consumed git submodule packages specification file" FORCE)
  include("${PROJECT_SOURCE_DIR}/cmake/specification.cmake")
endif()

CMAKE_DEPENDENT_OPTION(shacl.trait.tests
  "Build the trait tests and integrate with ctest"
  ON "BUILD_TESTING; NOT subproject" OFF)

# Allow coarse-grain exclusion from INSTALLATION, with default of ON
CMAKE_DEPENDENT_OPTION(INSTALL_SUBPROJECTS
    "Perform installaiton of some subprojects"
    ON "subproject" ON)
  
dependent_delegating_option(shacl.trait.installation
    DEFAULT INSTALL_SUBPROJECTS
    DOCSTRING "Perform a full installation of trait"
    CONDITION "subproject"
    FALLBACK ON
)

add_library(trait INTERFACE)
add_library(shacl::trait ALIAS trait)

if(shacl.trait.tests)
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

if(MSVC_VERSION GREATER_EQUAL 1910)
  # On MSVC, must set standards-conformant mode.
  target_compile_options(trait INTERFACE "/permissive-")
elseif(MSVC)
  message(FATAL_ERROR "MSVC++ 14.10 or newer (Visual Studio 2017) is required to use this library.")
endif()

include(GNUInstallDirs)

string(CONCAT prefix
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_include_directories(trait INTERFACE "${prefix}")

add_subdirectory(include/shacl)

if(shacl.trait.installation)
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
endif()
