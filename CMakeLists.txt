cmake_minimum_required(VERSION 3.6)

project(cxx-blockchain VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

OPTION(BUILD_UNIT_TESTS "Build unit tests" OFF)

# connect sources
set(DIRS
    networking
    core
)

foreach(DIR ${DIRS})
    include("${PROJECT_SOURCE_DIR}/${DIR}/CmakeListsInclude.cmake")
endforeach()

set(HEADERS ${HEADERS_INCLUDE})
source_group ("Header Files" FILES ${HEADERS})

set(SOURCES ${SOURCES_INCLUDE})
source_group("Source Files" FILES ${SOURCES})

# connect dependensies
# dependensies flags
# set(*_AS_STATIC_LIB ON)

find_package(Threads REQUIRED)
add_subdirectory(utils/logger)

include_directories(utils)

# cxx compiler flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(COMPILER_FLAGS "-fPIC -Wall -pedantic -Werror=all -Werror=float-conversion -Werror=format=2 -Werror=ignored-attributes -Werror=old-style-cast -Werror=unused-parameter -Werror=unused-variable -Werror=sign-compare")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(COMPILER_FLAGS "-fPIC -Wall -pedantic -Werror=all -Werror=float-conversion -Werror=format=2 -Werror=ignored-attributes -Werror=old-style-cast -Werror=unused-parameter -Wno-set-but-unused-variable -Werror=unused-variable -Werror=sign-compare")
endif()

# create app lib obj
add_library(${PROJECT_NAME}_obj OBJECT ${SOURCES} ${HEADERS})
set_target_properties(${PROJECT_NAME}_obj
    PROPERTIES
    COMPILE_FLAGS ${COMPILER_FLAGS}
    LINKER_LANGUAGE CXX
)
# target_include_directories(${PROJECT_NAME}_obj SYSTEM PUBLIC)

# link libs and create exec
add_executable(${PROJECT_NAME} "main.cpp"
    $<TARGET_OBJECTS:${PROJECT_NAME}_obj>
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        logger
        Threads::Threads
)

# create package
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# enable tests
if(UNIT_TEST)
    enable_testing()
    add_subdirectory("tests/unitTests")
endif()
