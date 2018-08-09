cmake_minimum_required(VERSION 3.11)

project(yaxxxxay)

add_subdirectory(external/catch/)

set (traceEnabled false) 
macro ( trace traceEnabler name )
    if (${traceEnabler} )
        message ( "trace \${${name}} = ${${name}}")
    endif()
endmacro() 

macro( yax_lib  
        name 
        topNamespace)
    add_library(${name} 
                SHARED)
    file(GLOB_RECURSE 
         sources 
         LIST_DIRECTORIES false  
         RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
         CONFIGURE_DEPEND
         src/${topNamespace}/*.in.cxx src/${topNamespace}/*.in.hxx)
    set_property(TARGET ${name} 
                 PROPERTY CXX_STANDARD 17)
    set(namespacesSources)
    set( traceEnabled false ) 
    trace (  traceEnabled sources )
    set(separator "-----------------------------------")
    foreach(source ${sources})
        trace ( traceEnabled source )
        string(SUBSTRING ${source} 4 -1 srcLess )
        trace (  traceEnabled srcLess )
        string(FIND ${source} ".in" inPos REVERSE)
        trace ( traceEnabled inPos )
        string(REPLACE ".in." "." destination ${srcLess})
        trace ( traceEnabled destination)
        string(FIND ${destination} "/" lastPath REVERSE)
        trace ( traceEnabled lastPath )
        math(EXPR filenameStart ${lastPath}+1)
        trace ( traceEnabled filenameStart )
        string(SUBSTRING ${destination} 0 ${lastPath} namespacePath)
        trace (  traceEnabled namespacePath )
        string(SUBSTRING ${destination} ${filenameStart} -1 filename)
        trace (  traceEnabled filename )
        string(FIND ${filename} "." lastDot REVERSE)
        trace ( traceEnabled lastDot )
        math(EXPR extensionStart ${lastDot}+1)
        trace ( traceEnabled extensionStart )
        string(SUBSTRING ${filename} ${extensionStart} -1 extension)
        trace (  traceEnabled extension )
        string(SUBSTRING ${filename} 0 ${lastDot} basename)
        trace (  traceEnabled basename )
        string(REPLACE  "/" "::" namespace ${namespacePath}) 
        trace (  traceEnabled namespace )
        string(SUBSTRING ${source} 4 ${lastPath} namespacePath)
        trace (  traceEnabled namespacePath )
        set(NAMESPACE ${namespace})
        set(ORIGFILENAME ${source})
        set(FILENAME ${filename})
        set(BASENAME ${basename})
        configure_file(${source} ${destination} @ONLY)
        list(APPEND namespacesSources ${CMAKE_CURRENT_BINARY_DIR}/${destination})
        trace( traceEnabled separator)
    endforeach()
#     trace ( traceEnabled namespacesSources)
    target_sources(${name} PRIVATE ${namespacesSources})
endmacro ( yax_lib ) 

add_subdirectory(libs)
#add_subdirectory(apps)

# as a test just compile something 
add_executable(yaxxxay main.cpp)
target_link_libraries(yaxxxay yax_core yax_std)

#target_compile_definitions(yaxxxxay PRIVATE ${namespace})

install(TARGETS yaxxxay RUNTIME DESTINATION bin)

