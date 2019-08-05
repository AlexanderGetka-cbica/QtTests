cmake_minimum_required(VERSION 3.1.0)

project(Preferences)

#find_package(VTK REQUIRED)
#include(${VTK_USE_FILE})

FIND_PACKAGE(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)

set(SRC_FILES
main.cpp
mainwindow.cpp
fontwidget.cpp
ipreferencepage.cpp
themewidget.cpp
preferencedialog.cpp
)

set(HDR_FILES
mainwindow.h
fontwidget.h
ipreferencepage.h
themewidget.h
preferencedialog.h
)

set(UI_FILES
mainwindow.ui
fontwidget.ui
themewidget.ui
preferencedialog.ui
)

add_executable(Preferences ${SRC_FILES} ${HDR_FILES} ${UI_FILES})
target_link_libraries(Preferences Qt5::Core Qt5::Gui Qt5::Widgets )
