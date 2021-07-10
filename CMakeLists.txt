cmake_minimum_required(VERSION 3.0)
project(
    "C++ Plotter"
    VERSION 0.1.0
    DESCRIPTION "A simple data plotter using Qt"
    LANGUAGES CXX
)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(Qt5 COMPONENTS Widgets Charts REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_library(cpp_plotter STATIC src/cpp_plotter.cpp)
target_include_directories(cpp_plotter
    PUBLIC include
)
target_link_libraries(cpp_plotter
    PRIVATE Eigen3::Eigen Qt5::Widgets Qt5::Charts
)

add_executable(example example/main.cpp)
target_link_libraries(example cpp_plotter)
