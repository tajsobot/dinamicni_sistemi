cmake_minimum_required(VERSION 4.2)
project(dinamicni_sistemi)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(dinamicni_sistemi main.cpp
        src/vaja1/Vaja1.cpp
        src/vaja1/Vaja1.h
)

target_compile_definitions(dinamicni_sistemi PRIVATE PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

target_link_libraries(dinamicni_sistemi PRIVATE raylib Eigen3::Eigen)


