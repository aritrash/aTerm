cmake_minimum_required(VERSION 3.20)

project(
    aTerm
    VERSION 0.1.0
    DESCRIPTION "Desktop Console for aTOS"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    SerialPort
)

qt_standard_project_setup()

qt_add_executable(aTerm WIN32
    src/main.cpp
    src/atermwindow.cpp
    src/terminalview.cpp
)

target_include_directories(aTerm
    PRIVATE
        include
)

target_link_libraries(aTerm
    PRIVATE
        Qt6::Widgets
        Qt6::SerialPort
)