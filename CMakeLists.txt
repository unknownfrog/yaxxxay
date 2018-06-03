cmake_minimum_required(VERSION 3.11)


project(yaxxxxay)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE external/Catch2/single_include/)

macro ( trace name )
    message ( "trace \${${name}} = ${${name}}")
endmacro() 

macro( yax_lib  name topNamespace)
#     set (namespace name)
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
         src/${topNamespace}/*.cxx src/${topNamespace}/*.hxx)
#     message ( " ${name} in directory ${CMAKE_CURRENT_SOURCE_DIR} has top namespace ${topNamespace}\n\tand ${sources} as sources  " )
    target_sources(${name} PRIVATE ${sources}) 
    set_property(TARGET ${name} PROPERTY CXX_STANDARD 17)
    foreach(source ${sources})
        string(FIND ${source} "/" pathEnd REVERSE)
        math(EXPR last ${pathEnd}-4)
        string(SUBSTRING ${source} 4 ${last} namespacePath)
#         trace ( namespacePath ) 
#         string(SUBSTRING ${headTrimmed} 4 -1 headTrimmed)
        string(REPLACE  "/" "::" namespace ${namespacePath}) 
#         trace ( namespace )
#         message("set namespace for source file ${source} to ${namespace} ")
        set_source_files_properties(${source}  
                                        PROPERTIES COMPILE_DEFINITIONS NAMESPACE=${namespace})
    endforeach() 
          
endmacro ( yax_lib ) 

add_subdirectory(libs apps)

# as a test just compile something 
add_executable(yaxxxay main.cpp)
target_link_libraries(yaxxxay yax_core yax_std)

#target_compile_definitions(yaxxxxay PRIVATE ${namespace})

install(TARGETS yaxxxay RUNTIME DESTINATION bin)
