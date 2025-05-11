cmake_minimum_required(VERSION 3.15)
project(VTKSphereWidget)

set(CMAKE_PREFIX_PATH "/usr/local/opt/qt@6/lib/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.9.0/lib/cmake")

find_package(VTK REQUIRED COMPONENTS
        CommonCore
        FiltersSources
        InteractionStyle
        RenderingCore
        RenderingOpenGL2
        RenderingContextOpenGL2
        RenderingGL2PSOpenGL2
        RenderingAnnotation
        RenderingFreeType
        RenderingVolumeOpenGL2
        RenderingUI
        GUISupportQt)

find_package(Qt6 REQUIRED COMPONENTS Test Widgets OpenGL)
find_package(GTest REQUIRED)

#include(${VTK_USE_FILE})

add_executable(VTKSphereWidget
        main.cpp
        Model/SphereModel.cpp
        View/SphereView.cpp
        Controller/SphereController.cpp
        Settings/SphereSettings.cpp
        Settings/SphereSettings.cpp
)

target_include_directories(VTKSphereWidget PRIVATE
        ${VTK_INCLUDE_DIRS}
        ${Qt6Widgets_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Model
        ${CMAKE_CURRENT_SOURCE_DIR}/View
        ${CMAKE_CURRENT_SOURCE_DIR}/Controller
        ${CMAKE_CURRENT_SOURCE_DIR}/Settings
)

target_link_libraries(VTKSphereWidget PRIVATE
        ${VTK_LIBRARIES}
        Qt6::Widgets
        Qt6::OpenGL
)

enable_testing()

add_executable(VTKSphereWidgetTests
        Test/SphereModelTest.cpp
        Model/SphereModel.cpp
        Test/SphereViewTest.cpp
        View/SphereView.cpp
        Controller/SphereController.cpp
        Test/SphereControllerTest.cpp
        Settings/SphereSettings.cpp
)



target_include_directories(VTKSphereWidgetTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Model
        ${CMAKE_CURRENT_SOURCE_DIR}/View
        ${CMAKE_CURRENT_SOURCE_DIR}/Controller
        ${CMAKE_CURRENT_SOURCE_DIR}/Settings
        ${GTEST_INCLUDE_DIRS}

)


target_link_libraries(VTKSphereWidgetTests PRIVATE
        ${GTest_LIBRARIES}
        ${VTK_LIBRARIES}
        GTest::gtest
        GTest::gtest_main
        pthread
        Qt6::OpenGL
        Qt6::Widgets
        Qt6::Test
)

