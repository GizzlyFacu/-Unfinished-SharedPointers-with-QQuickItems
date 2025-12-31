cmake_minimum_required(VERSION 3.16)

project(PortfolioExtender VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appPortfolioExtender
    ./src/main.cpp
)

qt_add_qml_module(appPortfolioExtender
    URI PortfolioExtender
    VERSION 1.0
    QML_FILES
        ./qml/Main.qml
        ./qml/modular/TemplateCreator.qml
    SOURCES
        ./src/basetemplate.cpp ./src/basetemplate.h
        ./src/creatorbase.cpp ./src/creatorbase.h
    RESOURCES
        assets/assets.qrc
        qml/modular/modularQmls.qrc

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPortfolioExtender PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPortfolioExtender
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPortfolioExtender
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appPortfolioExtender
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
