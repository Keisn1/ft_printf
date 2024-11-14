cmake_minimum_required(VERSION 3.14)
project(ft_printf)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

file(GLOB TEST_FILES "tests/*.cpp")

set(TEST_NAME "run_tests")

add_executable(${TEST_NAME} ${SRC_FILES} ${TEST_FILES})

# Link the test executable with GoogleTest and your static library
target_link_libraries(run_tests gtest gtest_main ${CMAKE_SOURCE_DIR}/libftprintf.a)

target_include_directories(${TEST_NAME} PRIVATE includes)
target_include_directories(${TEST_NAME} PRIVATE ${gtest_SOURCE_DIR}/googletest/include)
