cmake_minimum_required(VERSION 3.22)
project(ChartProcess LANGUAGES CXX)

# ---------- 基础设置 ----------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ---------- MinGW Debug：用 split-dwarf 给 .o 瘦身 ----------
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -gsplit-dwarf)   # 调试信息 -> .dwo
endif()

# 让 CMake 先找到 Qt6
set(CMAKE_PREFIX_PATH "E:/software/Qt6/6.10.0/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui PrintSupport OpenGL OpenGLWidgets Sql)

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
        ${CMAKE_CURRENT_SOURCE_DIR}          # 当前目录放 qcustomplot.h
        C:/WorkSpace/eigen-3.3.9               # 你用的 Eigen
        C:/WorkSpace/Qt/zmq                    # ZeroMQ 头文件
        C:/WorkSpace/nlohmannJson/include
)

## ---------- 库目录（仅 ZeroMQ） ----------
#target_link_directories(ChartProcess PRIVATE
#        C:/WorkSpace/Qt/libzmq-mingw64-4_3_4                    # 放 64-bit libzmq.a / libzmq.dll.a
#)

# ---------- 链接库 ----------
target_link_libraries(ChartProcess PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
        Qt6::PrintSupport
        Qt6::OpenGL
        Qt6::OpenGLWidgets
        Qt6::Sql
        # 系统自带
        opengl32
        DbgHelp
        C:/WorkSpace/Qt/zmq/libzmq-v140-mt-s-4_3_4.lib
        C:/WorkSpace/Qt/zmq/libzmq-v140-mt-4_3_4.lib
        ws2_32 iphlpapi
)

# ---------- Win 下自动拷贝 Qt 运行时 ----------
if(WIN32)
    qt6_generate_deploy_app_script(
            TARGET ChartProcess
            OUTPUT_SCRIPT deploy_script
            NO_UNSUPPORTED_PLATFORM_ERROR
    )
    install(SCRIPT ${deploy_script})
endif()

