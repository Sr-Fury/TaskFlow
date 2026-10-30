cmake_minimum_required(VERSION 3.16)

project(TaskFlow
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(taskflow_core
    src/models/Task.cpp
    src/services/TaskManager.cpp
)

target_include_directories(taskflow_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(taskflow
    src/main.cpp
)

target_link_libraries(taskflow
    PRIVATE
        taskflow_core
)

include(CTest)

if(BUILD_TESTING)

    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.tar.gz
    )

    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(taskflow_tests
        tests/TaskTests.cpp
        tests/TaskManagerTests.cpp
    )

    target_link_libraries(taskflow_tests
        PRIVATE
            taskflow_core
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(taskflow_tests)

endif()