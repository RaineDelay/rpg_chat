cmake_minimum_required(VERSION 3.15)

project(NetClient)

# I want CMake to produce a `compile_commands.json`, which is what clangd uses
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# I want to use C++20, which is a more recent version
# Older versions are fine too but C++20 has some nice additions
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# This is an example of using CPM to add a library
# It will automatically download it and put it in your build directory
#
# If you want it to cache downloads, you can enable this by setting the `CPM_SOURCE_CACHE`
# environment variable in your .bashrc or .zshrc:
#
# export CPM_SOURCE_CACHE=$HOME/.cache/cpm

include(cmake/CPM.cmake)
CPMAddPackage("gh:fmtlib/fmt#11.2.0")

# fixes deprecated find_package for modern versions of Boost
if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

# Add boost as dependency
find_package(Boost REQUIRED)
find_package(Threads REQUIRED)


# Find all the .cpp files in src/*.cpp
file(GLOB files client_app/*.cpp)

# Add an executable target named 'main', with the files
add_executable(net_client ${files})


# Add Boost::asio as a dependency of net_client
# These are private dependencies because net_client is an executable,
# so the dependencies don't need to be public
#
# (eg, for a library, you might choose to have public dependencies)
target_link_libraries(
    net_client
    PRIVATE
        Boost::boost
        fmt::fmt
        Threads::Threads
)

target_include_directories(
    net_client
    PRIVATE
        include/
)
