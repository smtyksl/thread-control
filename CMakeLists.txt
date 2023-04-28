cmake_minimum_required(VERSION 3.5)

project(ThreadController)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_EXAMPLES ON CACHE BOOL "Build Examples")

include_directories(headers)
include_directories(sources)
# create library target for ThreadController
add_library(ThreadController SHARED sources/threadcontroller.cpp headers/threadcontroller.h)
add_library(ThreadController_static STATIC sources/threadcontroller.cpp headers/threadcontroller.h)
set_target_properties(ThreadController_static PROPERTIES OUTPUT_NAME ThreadController)

# set output directories for the libraries
set_target_properties(ThreadController PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set_target_properties(ThreadController_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# set options for building shared and static libraries
set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries")
set(BUILD_STATIC_LIBS ON CACHE BOOL "Build static libraries")

# install the libraries
install(TARGETS ThreadController ThreadController_static
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

# install the header files
install(FILES sources/threadcontroller.h DESTINATION include)

# add executable target for example
if(BUILD_EXAMPLES)
    add_executable(example examples/main.cpp )
    target_link_libraries(example ThreadController)
    set_target_properties(example PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/examples"
    )
endif()
