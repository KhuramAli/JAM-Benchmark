#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "embb_base_c" for configuration "Release"
set_property(TARGET embb_base_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(embb_base_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libembb_base_c.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS embb_base_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_embb_base_c "${_IMPORT_PREFIX}/lib/libembb_base_c.a" )

# Import target "embb_base_cpp" for configuration "Release"
set_property(TARGET embb_base_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(embb_base_cpp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "embb_base_c"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libembb_base_cpp.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS embb_base_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_embb_base_cpp "${_IMPORT_PREFIX}/lib/libembb_base_cpp.a" )

# Import target "embb_mtapi_c" for configuration "Release"
set_property(TARGET embb_mtapi_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(embb_mtapi_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "embb_base_c"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libembb_mtapi_c.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS embb_mtapi_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_embb_mtapi_c "${_IMPORT_PREFIX}/lib/libembb_mtapi_c.a" )

# Import target "embb_mtapi_network_c" for configuration "Release"
set_property(TARGET embb_mtapi_network_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(embb_mtapi_network_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "embb_mtapi_c;embb_base_c"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libembb_mtapi_network_c.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS embb_mtapi_network_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_embb_mtapi_network_c "${_IMPORT_PREFIX}/lib/libembb_mtapi_network_c.a" )

# Import target "embb_mtapi_cpp" for configuration "Release"
set_property(TARGET embb_mtapi_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(embb_mtapi_cpp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "embb_mtapi_c"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libembb_mtapi_cpp.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS embb_mtapi_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_embb_mtapi_cpp "${_IMPORT_PREFIX}/lib/libembb_mtapi_cpp.a" )

# Import target "embb_containers_cpp" for configuration "Release"
set_property(TARGET embb_containers_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(embb_containers_cpp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "embb_base_cpp"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libembb_containers_cpp.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS embb_containers_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_embb_containers_cpp "${_IMPORT_PREFIX}/lib/libembb_containers_cpp.a" )

# Import target "embb_dataflow_cpp" for configuration "Release"
set_property(TARGET embb_dataflow_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(embb_dataflow_cpp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "embb_mtapi_cpp;embb_base_cpp;embb_mtapi_c;embb_base_c"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libembb_dataflow_cpp.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS embb_dataflow_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_embb_dataflow_cpp "${_IMPORT_PREFIX}/lib/libembb_dataflow_cpp.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
