cmake_minimum_required(VERSION 3.21)
project(Mandelbrot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.2.3/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        OpenGL
        REQUIRED)

add_executable(Mandelbrot main.cpp)
target_link_libraries(Mandelbrot
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::OpenGL
        )