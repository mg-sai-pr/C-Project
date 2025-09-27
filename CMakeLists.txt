cmake_minimum_required(VERSION 3.10)
project(CProjectIGCSE)

set(CMAKE_CXX_STANDARD 11)

# Add source files
set(SOURCES
    main.cpp
    libs/imgui.cpp
    libs/imgui_draw.cpp
    libs/imgui_tables.cpp
    libs/imgui_widgets.cpp
    libs/imgui_demo.cpp
)

# Add executable
add_executable(CProjectIGCSE ${SOURCES})

# Include directories
include_directories(libs)

# Optionally, link additional libraries here if needed
# target_link_libraries(CProjectIGCSE ...)
