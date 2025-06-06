cmake_minimum_required(VERSION 3.20)

project(gleam VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINE_HIDDEN ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

option(BUILD_TESTS "build tests" ON)
option(BUILD_EXAMPLES "build examples" ON)
option(BUILD_TOOLS "build tools" ON)
option(BUILD_DOCS "build documentation" ON)

add_subdirectory(src)

if (BUILD_TESTS)
    include(CTest)
    add_subdirectory(tests)
endif()

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if (BUILD_TOOLS)
    add_subdirectory(tools/asset_builder)
endif()

if (BUILD_DOCS)
    include(Doxygen)
endif()
