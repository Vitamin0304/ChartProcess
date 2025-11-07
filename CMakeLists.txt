cmake_minimum_required(VERSION 3.22)
project(ChartProcess)

add_compile_definitions(QCUSTOMPLOT_USE_OPENGL=1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:/software/Qt6/6.10.0/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(Qt6OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
FIND_PACKAGE(Qt6Sql REQUIRED)
#FIND_PACKAGE(Qt6SerialPort REQUIRED)
FIND_PACKAGE(Qt6PrintSupport REQUIRED)

link_directories(E:/software/Qt6/6.10.0/mingw_64/lib)
link_directories(C:/WorkSpace/Qt/zmq)

add_executable(ChartProcess
        chartmain.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        qcustomplot.cpp
        qcustomplot.h
        ChartDisplay.cpp
        ChartDisplay.h
        ZmqSubThread.cpp
        ZmqSubThread.h
        ChartDataSave/ChartDataSave.cpp
        ChartDataSave/ChartDataSave.h
        ChartDataSave/ChartDataSave.ui
        )

target_link_libraries(ChartProcess
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::PrintSupport
        )

# include
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories(C:/Qt/5.15.2/mingw81_64/include)
include_directories(C:/WorkSpace/eigen-3.3.9)
#include_directories(D:/WorkSpace/qcustomplot)
# link
#target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

include_directories(C:/WorkSpace/Qt/zmq)

target_link_libraries(ChartProcess freeglut)
target_link_libraries(ChartProcess opengl32)
target_link_libraries(ChartProcess DbgHelp)
target_link_libraries(ChartProcess libzmq-v140-mt-4_3_4)
target_link_libraries(ChartProcess libzmq-v140-mt-s-4_3_4)

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
