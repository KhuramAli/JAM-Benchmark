project (project_partest)

file(GLOB_RECURSE PARTEST_CPP_SOURCES "src/*.cc" "src/*.h")
file(GLOB_RECURSE PARTEST_CPP_HEADERS "include/partest/*.h")
file(GLOB_RECURSE PARTEST_TEST_SOURCES "test/*.cc" "test/*.h")

# Execute the GroupSources macro
include(${CMAKE_SOURCE_DIR}/CMakeCommon/GroupSourcesMSVC.cmake)
GroupSourcesMSVC(partest)
GroupSourcesMSVC(src)
GroupSourcesMSVC(test)

if(CMAKE_COMPILER_IS_GNUCXX)
  if (use_exceptions STREQUAL ON)
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPARTEST_DISABLE_EXCEPTIONS")
  endif()
endif()
if(MSVC)
  if (use_exceptions STREQUAL ON)
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DPARTEST_DISABLE_EXCEPTIONS")
  endif()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library (partest STATIC ${PARTEST_CPP_SOURCES} ${PARTEST_CPP_HEADERS} )
add_executable (partest_test ${PARTEST_TEST_SOURCES})

target_link_libraries(partest_test partest ${compiler_libs})
