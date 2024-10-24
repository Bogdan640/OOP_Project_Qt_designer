cmake_minimum_required(VERSION 3.27)
project(qt11)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.0/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)

add_executable(qt11 main.cpp
        Domain/DynamicArr.cpp
        Domain/DynamicArr.h
        Domain/coat.cpp
        Repository/Repo.h
        Repository/Repo.cpp
        Service/Services.h
        Service/Services.cpp
        #UI.h
        #UI.cpp
        main.cpp
        Test/tests.h
        Test/tests.cpp
        Utils/Utils.h
        Utils/Utils.cpp
        Repository/RepositoryExceptions.h
        Repository/RepositoryExceptions.cpp
        Domain/shopping_basket.h
        Domain/shopping_basket.cpp
        Repository/FileBasket.h
        Repository/FileBasket.cpp
        GUI/GUI.h
        GUI/GUI.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
        Domain/Action.cpp
        Domain/Action.h
        Domain/TableModel.h
        Domain/TableModel.cpp

)

target_link_libraries(qt11
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::PrintSupport
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
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
    foreach (QT_LIB Core Gui Widgets PrintSupport)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
