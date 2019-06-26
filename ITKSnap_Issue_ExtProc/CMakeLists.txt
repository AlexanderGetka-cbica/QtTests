cmake_minimum_required(VERSION 3.1.0)

project(ITKSnap_ExtProc)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

FIND_PACKAGE(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)

set(SRC_FILES
main.cpp
mainwindow.cpp
)

set(HDR_FILES
mainwindow.h
)

set(UI_FILES
mainwindow.ui
)

add_executable(ITKSnap_ExtProc ${SRC_FILES} ${HDR_FILES} ${UI_FILES})
target_link_libraries(ITKSnap_ExtProc Qt5::Core Qt5::Gui Qt5::Widgets ${VTK_LIBRARIES})
