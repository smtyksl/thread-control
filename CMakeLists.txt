cmake_minimum_required(VERSION 3.5)

project(ThreadController)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# create library target for ThreadController
add_library(ThreadController SHARED threadcontroller.cpp)
add_library(ThreadController_static STATIC threadcontroller.cpp)
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
install(FILES ThreadController.h DESTINATION include)
