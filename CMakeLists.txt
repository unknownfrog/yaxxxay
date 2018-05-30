cmake_minimum_required(VERSION 3.11)
project(yaxxxxay)


macro( yax_lib  name namespace )
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
         ${namespace}/*.cxx ${namespace}/*.hxx)
#   foreach(file ${sources})
#      string(FIND /     
     message ( " ${name} in directory ${CMAKE_CURRENT_SOURCE_DIR} has top  namespace ${namespace}\n\tand ${sources} as sources  " )
      target_sources(${name} PRIVATE ${sources})
#     endforeach(file)  
endmacro ( yax_lib )

add_subdirectory(libs apps)

# as a test just compile something 
add_executable(yaxxxay main.cpp)
target_link_libraries(yaxxxay yax_core yax_std)

#target_compile_definitions(yaxxxxay PRIVATE ${namespace})

install(TARGETS yaxxxay RUNTIME DESTINATION bin)
