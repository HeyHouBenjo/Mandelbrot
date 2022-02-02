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
        OpenGLWidgets
        REQUIRED)

file(GLOB_RECURSE SOURCE_FILES src/**.cpp)
file(GLOB_RECURSE HEADER_FILES headers/**.h)
add_executable(Mandelbrot ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Mandelbrot
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::OpenGLWidgets
        )