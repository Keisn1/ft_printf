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

##############################################################
# mandatory part
##############################################################

# Add libftprintf library
file(GLOB LIBFTPRINTF_SOURCES "src/*.c")
add_library(ftprintf STATIC ${LIBFTPRINTF_SOURCES})
target_include_directories(ftprintf PRIVATE includes)

# Add libft subdirectory
add_subdirectory(libft)

# Make sure the libftprintf library depends on libft
target_link_libraries(ftprintf PRIVATE ft)

# Add test executable
file(GLOB TEST_FILES "tests/*.cpp")
add_executable(run_tests ${TEST_FILES})

# Link the test executable with GoogleTest, ftprintf, and libft
set(TEST_NAME "run_tests")
target_link_libraries(${TEST_NAME} gtest gtest_main ftprintf)

target_include_directories(${TEST_NAME} PRIVATE includes)
target_include_directories(${TEST_NAME} PRIVATE tests)
target_include_directories(${TEST_NAME} PRIVATE ${gtest_SOURCE_DIR}/googletest/include)
##############################################################
# bonus part
##############################################################

# Add libftprintf library
file(GLOB LIBFTPRINTF_BONUS_SOURCES "bonus/*.c")
add_library(ftprintf_bonus STATIC ${LIBFTPRINTF_BONUS_SOURCES})
target_include_directories(ftprintf_bonus PRIVATE includes_bonus)

# Make sure the libftprintf library depends on libft
target_link_libraries(ftprintf_bonus PRIVATE ft)

# Add test executable
file(GLOB TEST_BONUS_FILES "tests_bonus/*.cpp")
add_executable(run_tests_bonus ${TEST_BONUS_FILES})

# Link the test executable with GoogleTest, ftprintf, and libft
set(TEST_NAME_BONUS "run_tests_bonus")
target_link_libraries(${TEST_NAME_BONUS} gtest gtest_main ftprintf_bonus)

target_include_directories(${TEST_NAME_BONUS} PRIVATE includes_bonus)
target_include_directories(${TEST_NAME_BONUS} PRIVATE tests_bonus)
target_include_directories(${TEST_NAME_BONUS} PRIVATE ${gtest_SOURCE_DIR}/googletest/include)
