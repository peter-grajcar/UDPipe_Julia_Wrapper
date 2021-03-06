project(UDPipe_Julia_Wrapper)

cmake_minimum_required(VERSION 3.1)

unset(CMAKE_CXX_STANDARD)

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location}")

file(GLOB_RECURSE files "${UDPIPE_DIR}/src/*.cpp")
list(FILTER files EXCLUDE REGEX ".*/derivator_dictionary_encoder.cpp$")
list(FILTER files EXCLUDE REGEX "/rest_server/")
list(FILTER files EXCLUDE REGEX ".*/udpipe.cpp$")
include_directories(udpipejl PUBLIC "${UDPIPE_DIR}/src")

set_source_files_properties(${files} PROPERTIES COMPILE_FLAGS "-std=c++11")

add_library(udpipejl SHARED ${files} src/udpipejl.cpp src/Pipeline.cpp src/Model.cpp src/ProcessingError.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_REQUIRED_FLAGS "-std=c++11")
add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS "-std=c++11" CACHE STRING "compile flags" FORCE)
set_target_properties(udpipejl PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(udpipejl JlCxx::cxxwrap_julia JlCxx::cxxwrap_julia_stl)

install(TARGETS udpipejl
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
