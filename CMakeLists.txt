cmake_minimum_required(VERSION 3.11)
project(yaxxxxay)


macro( yax_lib  name )
    set (namespace name)
#     if (${ARGC} GREATER 1)
#       set(subdir ${ARG2}
#     else()
#       set( subdir name )
    add_library(${name} 
                SHARED)
    file(GLOB_RECURSE 
         sources
         LIST_DIRECTORIES false  
          RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
         *.cxx *.hxx)
#   foreach(file ${sources})
#      string(FIND /    
     message ( " ${name} has ${sources} as sources in directory ${CMAKE_CURRENT_SOURCE_DIR}" )
      target_sources(${name} PRIVATE ${sources})
#     endforeach(file) 
endmacro ( yax_lib )


function( add_namespace subdir)
    set (namespace ${namespace}::subdir)
    add_subdirectory(subdir) 
endfunction(add_namespace)

add_subdirectory(libs apps)

# as a test just compile something 
add_executable(yaxxxxay main.cpp)
target_link_libraries(yax_core)

#target_compile_definitions(yaxxxxay PRIVATE ${namespace})

install(TARGETS yaxxxxay RUNTIME DESTINATION bin)
