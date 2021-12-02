cmake_minimum_required(VERSION 3.18.4)
project(CringeMessenger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

include_directories(include ${OPENGL_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

         
file(GLOB IMGUI "src/imgui/*.h"
                    "src/imgui/*.cpp")

file(GLOB Window "src/Window/*.h"
                "src/Window/*.cpp")

add_executable(CringeMessenger src/glad.c src/main.cpp ${IMGUI} ${Window})

target_link_libraries(CringeMessenger glfw OpenGL::GL Threads::Threads OpenSSL::SSL ${CMAKE_DL_LIBS})
