# Bare Minimum version of cmake that is required
cmake_minimum_required(VERSION 3.22)

# Project name and the languages
project(fantasy_tracker LANGUAGES CXX)

# C++23 is the mandatory standard
# Always update to most updated standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_OBJCXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cc
    src/Manager.cc
    src/Player.cc
    src/ScoringRules.cc
    src/StatLine.cc
)

# Executable 
add_executable(${PROJECT_NAME} ${SOURCES})

# Include what needs to be included for src
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
