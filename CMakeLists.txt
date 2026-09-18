cmake_minimum_required(VERSION 3.20)

project(Playbook LANGUAGES CXX)

# Generate compile_commands.json for clangd/tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------------
# Playbook Core
# --------------------------------------------------

add_library(PlaybookCore
    src/Record.cc
    src/TeamIdentity.cc
    src/utils/StringUtils.cc
)

target_include_directories(PlaybookCore PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(PlaybookCore PUBLIC
    cxx_std_23
)

# --------------------------------------------------
# Playbook Application
# --------------------------------------------------

add_executable(Playbook
    src/main.cc
)

target_link_libraries(Playbook PRIVATE
    PlaybookCore
)

# --------------------------------------------------
# Testing
# --------------------------------------------------

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(RecordTests
    tests/RecordTests.cc
)
add_executable(TeamIdentityTests
    tests/TeamIdentityTests.cc
)
add_executable(StringUtilsTests
    tests/StringUtilsTests.cc
)

target_link_libraries(RecordTests PRIVATE
    PlaybookCore
    GTest::gtest_main
)
target_link_libraries(TeamIdentityTests PRIVATE
    PlaybookCore
    GTest::gtest_main
)
target_link_libraries(StringUtilsTests PRIVATE
    PlaybookCore
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(RecordTests)
gtest_discover_tests(TeamIdentityTests)
gtest_discover_tests(StringUtilsTests)
