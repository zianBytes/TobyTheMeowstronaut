cmake_minimum_required(VERSION 3.10)
project(TobyTheMeowstronaut)

set(CMAKE_CXX_STANDARD 20)  # Use C++20

# Add the source files from src/
add_executable(TobyTheMeowstronaut src/main.cpp
        src/game.h
        src/game.cpp
        src/player.h
        src/player.cpp
        src/obstacle.h
        src/obstacle.cpp)

# Find and Link Raylib (For macOS)
find_package(raylib REQUIRED)
include_directories(/usr/local/include)
target_link_libraries(TobyTheMeowstronaut /usr/local/lib/libraylib.dylib)
