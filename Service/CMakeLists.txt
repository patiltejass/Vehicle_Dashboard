project(Service VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql REQUIRED)

add_library(
        Service SHARED
        Service.h
        Service.cpp
)

target_link_libraries(Service PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Link the database library
target_link_libraries(Service PRIVATE Database)
