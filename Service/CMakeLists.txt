project(Service)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql REQUIRED)
add_library(Service SHARED
  service.h
  service.cpp)

target_link_libraries(Service PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets
  Qt${QT_VERSION_MAJOR}::Sql
  Database)

# Link the database library
# target_link_libraries(Service PRIVATE Database)
