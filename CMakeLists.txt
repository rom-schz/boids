cmake_minimum_required(VERSION 3.16)

project(Boids
	VERSION 1.0
	DESCRIPTION "Flock simulation in two dimensions"
	LANGUAGES CXX)

# Compiling options for the project. "-pg" is for profiling.
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pg")

# Define the localization of headers. It is propagated to the entire project.
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(app)

find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
	message(FATAL_ERROR "Doxygen is required to build the documentation")
endif()

# Include raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# Doxygen for the documentation
set(doxyfile_in ../doc/doxygen.config)
set(doxyfile ../doc/doxyfile)

message("Doxygen build started...")

add_custom_target(doc
	COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_in}
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
	COMMENT "Generating API documentation with Doxygen..."
	VERBATIM)
