if (BUILD_SHARED_LIBS)
    message(FATAL_ERROR "
        ⚠️ Unit tests should be built in conjunction with a static library.\n
        -- -DBUILD_SHARED_LIBS=0 or -DBUILD_TESTS=0
    ")
endif()

set(BUILD_GMOCK OFF CACHE BOOL "")

find_package(GTest REQUIRED)

if (NOT GTest_FOUND)
    message(FATAL_ERROR "
        ⚠️ GTest was not found. Use conan to install missing depedencies.
        -- conan install . --output-folder=build --build=missing
    ")
endif()

file(GLOB TEST_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/**/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/**/**/*.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_LIST_DIR})

foreach(TEST IN LISTS TEST_SOURCES)
    get_filename_component(FILE_NAME ${TEST} NAME)
    string(REGEX REPLACE "\\.[^.]*$" "" NAME_NO_EXT ${FILE_NAME})
    message(STATUS "🧪 Adding test ${FILE_NAME}")

    set(TEST_TARGET run_${NAME_NO_EXT})
    add_executable(${TEST_TARGET} test_helpers.hpp ${TEST})
    target_link_libraries(${TEST_TARGET} PRIVATE GTest::gtest GTest::gtest_main gleam)
    add_test(${NAME_NO_EXT} ${TEST_TARGET})

    add_custom_command(
        TARGET ${TEST_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${TEST_TARGET}>/assets
    )
endforeach()