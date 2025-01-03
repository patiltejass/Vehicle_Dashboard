 find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql REQUIRED)

add_library(
	Database SHARED
        Database.h
        Database.cpp
)
 qt_import_plugins(service PLUGINS SQLiteDriverPlugin)

# target_link_libraries(Service PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Database PRIVATE  Qt${QT_VERSION_MAJOR}::Sql)
