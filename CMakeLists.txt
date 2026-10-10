# CMakeLists.txt for the Lost and Found GUI project
# Uses Qt 6 Widgets

cmake_minimum_required(VERSION 3.16)

project(LostAndFoundGUI VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt needs these turned on so .ui and moc files are handled automatically
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Look for Qt6 (fall back to Qt5 if not found)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# All our source files
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    lostandfound.cpp
    lostandfound.h
)

add_executable(LostAndFoundGUI ${PROJECT_SOURCES})

target_link_libraries(LostAndFoundGUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
