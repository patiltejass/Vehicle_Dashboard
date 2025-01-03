#include "Database.h"

database::database() {
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbpath);
    // qDebug()<<db.open()<<"hello";
    if (openConnection()) {
        createTable();
    }
}

database::~database()
{
    closeConnection();
}

bool database::openConnection()
{
    if (!db.open()) {
        qDebug() << "Error: " << db.lastError().text();
        return false;
    }
    return true;
}

void database::closeConnection()
{
    db.close();
}

bool database::createTable()
{
    // Create the "user" table
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS user ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "user_name TEXT UNIQUE, "
                    "mode TEXT, "
                    "color TEXT, "
                    "distance INT)"))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "User Table Created Successfully";

    // Create the "vehicleInfo" table with a foreign key constraint
    if (!query.exec("CREATE TABLE IF NOT EXISTS vehicleInfo ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "user_name TEXT UNIQUE, "
                    "totalKms INT, "
                    "batteryLevel INT, "
                    "engineHours INT, "
                    "FOREIGN KEY (user_name) REFERENCES user (user_name))"))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "Vehicle Info Table Created Successfully";

    return true;
}
void database::insert_user(const QString& username, const QString& mode, QString color) {
    QSqlQuery query;

    if (!query.prepare("INSERT INTO user (user_name, mode, color) "
                       "VALUES (:username, :mode, :color)")) {
        qDebug() << "Error preparing insert query:" << query.lastError().text();
        return;
    }

    query.bindValue(":username", username);
    query.bindValue(":mode", mode);
    query.bindValue(":color", color);
    // query.bindValue(":distance", distance);

    if (!query.exec()) {
        qDebug() << "Error inserting data into user table:" << query.lastError().text();
    } else {
        qDebug() << "User data inserted successfully";
    }
}

void database::update_user(const QString &username, const QString &mode, QString color)
{
    QSqlQuery query;

    // Prepare update query with a WHERE clause to target specific user
    if (!query.prepare("UPDATE user SET mode = :mode, color = :color WHERE user_name = :username")) {
        qDebug() << "Error preparing update query:" << query.lastError().text();
        return;
    }

    query.bindValue(":username", username);
    query.bindValue(":mode", mode);
    query.bindValue(":color", color);

    if (!query.exec()) {
        qDebug() << "Error updating user data:" << query.lastError().text();
    } else {
        qDebug() << "User data updated successfully";
    }

}

// QString database::gettheme(QString &name)
// {
//     QString theme;
//     QSqlQuery query;
//     query.prepare("SELECT theme from user where user_name=:name ");
//     if(query.exec()){
//        theme = query.value(0).toString();
//     }
//     else {
//         qDebug() << "Error executing query234: " << query.lastError().text();
//     }
//     return theme;
// }

vector<QString> database::getusers()
{
    vector<QString> operators;

    QSqlQuery query;
    query.prepare("SELECT user_name FROM user;");

    if (query.exec()) {
        while (query.next()) {
            QString operatorName = query.value(0).toString();
            operators.push_back(operatorName);
        }
    } else {
        qDebug() << "Error executing query234: " << query.lastError().text();
    }

    return operators;
}
