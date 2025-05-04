cmake_minimum_required(VERSION 3.15)
project(VTKSphereWidget)

set(CMAKE_CXX_STANDARD 17)

find_package(VTK REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(GTest REQUIRED)

include(${VTK_USE_FILE})

add_executable(VTKSphereWidget
    main.cpp
    Model/SphereModel.cpp
    View/SphereView.cpp
    Controller/SphereController.cpp
)

target_include_directories(VTKSphereWidget PRIVATE
        ${VTK_INCLUDE_DIRS}
        ${Qt6Widgets_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Model
        ${CMAKE_CURRENT_SOURCE_DIR}/View
        ${CMAKE_CURRENT_SOURCE_DIR}/Controller
)

target_link_libraries(VTKSphereWidget PRIVATE
    ${VTK_LIBRARIES}
    Qt6::Widgets
)

enable_testing()

add_executable(VTKSphereWidgetTests
    Test/SphereModelTest.cpp
    Test/SphereControllerTest.cpp
    Test/SphereViewTest.cpp
)

target_include_directories(VTKSphereWidgetTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Model
        ${CMAKE_CURRENT_SOURCE_DIR}/View
        ${CMAKE_CURRENT_SOURCE_DIR}/Controller
        ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(VTKSphereWidgetTests PRIVATE
    ${GTest_LIBRARIES}
    ${VTK_LIBRARIES}
    Qt6::Widgets
)
