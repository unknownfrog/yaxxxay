

yax_lib(yax_core core)
target_include_directories(yax_core INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/src)
target_link_libraries(yax_core PUBLIC Catch)

yax_lib(yax_std std) 
target_include_directories(yax_std INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/src)
target_link_libraries(yax_core PUBLIC Catch)
