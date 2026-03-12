# Project specific definitions.

set(ENABLE_MINIMAL_TEST true)
set(ENABLE_SAMPLE_TEST true)
set(ENABLE_UNIT_TEST true)

set(xpack_dependencies_project_folders)

# Each test has its own library. Add only those enabled.
if(ENABLE_MINIMAL_TEST)
  list(APPEND xpack_dependencies_project_folders
       "${CMAKE_SOURCE_DIR}/minimal-test"
  )
endif()

if(ENABLE_SAMPLE_TEST)
  list(APPEND xpack_dependencies_project_folders
       "${CMAKE_SOURCE_DIR}/sample-test"
  )
endif()

if(ENABLE_UNIT_TEST)
  list(APPEND xpack_dependencies_project_folders
       "${CMAKE_SOURCE_DIR}/unit-test"
  )
endif()
