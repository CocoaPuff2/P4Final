cmake_minimum_required(VERSION 3.10)
project(my_executable)

set(CMAKE_CXX_STANDARD 17)

# Set C++ compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Specify source files explicitly
set(SOURCES
        media.cpp
        classics.cpp
        comedy.cpp
        drama.cpp
        customer.cpp
        inventory.cpp
        media.cpp
        transaction.cpp
        customer.cpp
        inventory.cpp
        classics.h
        comedy.h
        drama.h
        transaction.h
        inventory.h
        customer.h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Include header files
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
