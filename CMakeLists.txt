cmake_minimum_required(VERSION 3.11)

project(yaxxxxay)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE external/catch/single_include/)

macro ( trace name )
    message ( "trace \${${name}} = ${${name}}")
endmacro() 

macro( yax_lib  name topNamespace)
    add_library(${name} 
                SHARED)
    file(GLOB_RECURSE 
         sources 
         LIST_DIRECTORIES false  
          RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
         src/${topNamespace}/*.cxx src/${topNamespace}/*.hxx)
    set_property(TARGET ${name} PROPERTY CXX_STANDARD 17)
    set(namespacesSources)
    foreach(source ${sources})
        string(FIND ${source} "/" pathEnd REVERSE)
        math(EXPR last ${pathEnd}-4)
        string(SUBSTRING ${source} 4 ${last} namespacePath)
#         trace ( namespacePath )
        string(REPLACE  "/" "::" namespace ${namespacePath}) 
#         trace ( namespace )
        set(NAMESPACE ${namespace})
        configure_file(${source} ${source} @ONLY)
        list(APPEND namespacesSources ${CMAKE_CURRENT_BINARY_DIR}/${source})
    endforeach()
#    trace( namespacesSources)
    target_sources(${name} PRIVATE ${namespacesSources})
endmacro ( yax_lib ) 

add_subdirectory(libs)
#add_subdirectory(apps)

# as a test just compile something 
add_executable(yaxxxay main.cpp)
target_link_libraries(yaxxxay yax_core yax_std)

#target_compile_definitions(yaxxxxay PRIVATE ${namespace})

install(TARGETS yaxxxay RUNTIME DESTINATION bin)
