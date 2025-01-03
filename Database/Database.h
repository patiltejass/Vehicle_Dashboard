#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QDir>
#include<vector>
using namespace std;

class database:public QObject
{
    Q_OBJECT
public:
    database();
    database(const database&)=delete;
    database& operator =(const database&)=delete;
    QString path = QDir::currentPath();
    QString dbpath = path+"/example.db";
    QSqlDatabase db;
    static database* objectprovider(){
        static database* db;
        if(!db){
            db = new database;
        }
        return db;
    }
    bool openConnection();
    void closeConnection();
    bool createTable();
    void insert_user(const QString& username, const QString& mode, QString color);
    void update_user(const QString& username, const QString& mode, QString color);
    vector<QString> getusers();
    QString gettheme();
    // int getTotalKms() ;

    virtual ~database();
};

#endif // DATABASE_H
