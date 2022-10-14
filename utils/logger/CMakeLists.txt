cmake_minimum_required(VERSION 3.6)

project(logger VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

OPTION(BUILD_UNIT_TESTS "Build unit tests" OFF)

set(HEADERS_INCLUDE "Logger.hpp")
set(SOURCES_INCLUDE "Logger.cpp")

set(${PROJECT_NAME}_lib ${HEADERS_INCLUDE} ${SOURCES_INCLUDE})

# cxx compiler flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(COMPILER_FLAGS "-fPIC -Wall -pedantic -Werror=all -Werror=float-conversion -Werror=format=2 -Werror=ignored-attributes -Werror=old-style-cast -Werror=unused-parameter -Werror=unused-variable -Werror=sign-compare")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(COMPILER_FLAGS "-fPIC -Wall -pedantic -Werror=all -Werror=float-conversion -Werror=format=2 -Werror=ignored-attributes -Werror=old-style-cast -Werror=unused-parameter -Wno-set-but-unused-variable -Werror=unused-variable -Werror=sign-compare")
endif()

add_library(${PROJECT_NAME}_obj OBJECT ${logger_lib})
set_target_properties(${PROJECT_NAME}_obj 
	PROPERTIES
		CXX_STANDARD ${CMAKE_CXX_STANDARD}
		COMPILE_FLAGS ${COMPILER_FLAGS}
		POSITION_INDEPENDENT_CODE ON
)
target_include_directories(${PROJECT_NAME}_obj PUBLIC "${PROJECT_SOURCE_DIR}")

add_library(${PROJECT_NAME} STATIC 
	$<TARGET_OBJECTS:${PROJECT_NAME}_obj>
)

# target_include_directories(${PROJECT_NAME}
#     PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
# )

message("${PROJECT_NAME} lib successfully configured")
