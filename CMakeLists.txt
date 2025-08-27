cmake_minimum_required(VERSION 3.16)

project(42Cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Try to find system SDL2
find_package(SDL2 CONFIG QUIET)

if(NOT SDL2_FOUND)
    message(STATUS "SDL2 not found on system. Fetching SDL2...")
    include(FetchContent)
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.28.5
    )
    FetchContent_MakeAvailable(SDL2)
    find_package(SDL2 CONFIG REQUIRED)
endif()

# Example executable to ensure configuration succeeds.
add_executable(example main.cpp)

target_link_libraries(example PRIVATE SDL2::SDL2)
