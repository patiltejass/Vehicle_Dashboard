
project(Database)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql REQUIRED)

set(QT_PLUGIN_PATH "C:/Qt/6.4.2/msvc2019_64/plugins")
add_library(Database SHARED
  database.h
  database.cpp

)

target_link_libraries(Database PRIVATE
  Qt${QT_VERSION_MAJOR}::Sql)
