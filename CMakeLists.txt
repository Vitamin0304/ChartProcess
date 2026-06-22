cmake_minimum_required(VERSION 3.22)
project(ChartProcess LANGUAGES CXX)

# ---------- 基础设置 ----------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ---------- 查找依赖 ----------
set(CMAKE_PREFIX_PATH "/opt/Qt/6.9.3/gcc_64")
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui PrintSupport OpenGL OpenGLWidgets Sql)
find_package(OpenGL REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(ZMQ REQUIRED libzmq)   # libzmq3-dev

# ---------- 可执行文件 ----------
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

# ---------- 编译定义 ----------
target_compile_definitions(ChartProcess PRIVATE
        QCUSTOMPLOT_USE_OPENGL      # 启用 QCustomPlot OpenGL 加速
)

# ---------- 头文件搜索路径 ----------
target_include_directories(ChartProcess PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${EIGEN3_INCLUDE_DIR}
        ${nlohmann_json_INCLUDE_DIRS}
        ${ZMQ_INCLUDE_DIRS}
)

# ---------- 链接库 ----------
target_link_libraries(ChartProcess PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
        Qt6::PrintSupport
        Qt6::OpenGL
        Qt6::OpenGLWidgets
        Qt6::Sql
        OpenGL::GL
        ${ZMQ_LIBRARIES}
)

