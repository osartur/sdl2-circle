cmake_minimum_required(VERSION 3.0.0)
project(window)
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.c")
#Cxxdroid-binary: window
add_executable(window ${SRC_FILES})

find_package(SDL2 REQUIRED)
target_link_libraries(window ${SDL2_LIBRARIES} m)
