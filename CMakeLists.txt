cmake_minimum_required(VERSION 3.16)

# Defines
add_compile_definitions(RA_ENABLE_ASSERTS)
add_compile_definitions(RA_ENABLE_LOGGING)

# Project
project(RESTAPI)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Executable
add_executable(
    RESTAPI
    Source/Main.cpp
    Source/Core/Logger.cpp
    Source/Core/Guid.cpp
)

# Include libraries
target_include_directories(RESTAPI PUBLIC External/cpp-httplib)
target_include_directories(RESTAPI PUBLIC External/json/include)
target_include_directories(RESTAPI PUBLIC External/spdlog/include)
target_include_directories(RESTAPI PUBLIC External/stduuid/include)

# Link libraries
# target_link_libraries(RESTAPI PRIVATE mono-2.0-sgen)
