if(NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(subproject TRUE)
else()
  set(subproject FALSE)
endif()

if(subproject)
  if(NOT DEFINED INSTALL_SUBPROJECTS)
    # Future refactor: In CMake 3.13 or later, this can be just option.
    #
    # In 3.12 and below, CMake's option does not honor directory variables
    option(INSTALL_SUBPROJECTS
      "Perform full installation of subproject dependencies" ON)
  endif()
endif()

include_guard(DIRECTORY)

if(NOT DEFINED shacl.cmake.installation)
  set(shacl.cmake.installation "default" CACHE STRING
  "Install to included shacl::cmake modules used by this project.
  When set to 'default', shacl::cmake projects will be installed for
  the highest level project and refer to the INSTALL_SUBPROJECTS cache
  variable in subprojects")

  set_property(CACHE shacl.cmake.installation PROPERTY STRINGS default ON OFF)
  mark_as_advanced(shacl.cmake.installation)
endif()

if(shacl.cmake.installation STREQUAL "default")
  if(subproject)
    set(shacl.cmake.install "${INSTALL_SUBPROJECTS}")
  else()
    set(shacl.cmake.install ON)
  endif()
endif()

include_guard(GLOBAL)
if(shacl.cmake.installation)
  install(FILES "${CMAKE_CURRENT_LIST_FILE}"
    DESTINATION share/cmake/shacl/.cmake)
endif()
