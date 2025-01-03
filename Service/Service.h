#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include<vector>
#include"..\Database\Database.h"
using namespace std;


class Service:public QObject
{
    Q_OBJECT
private slots:
               // int updatedistance();

public slots:
    void handleuseremitter(QString name,QString mode,QString theme);
    void handleupdateuseremitter(QString name,QString mode,QString theme);
    // QString gettheme();
    vector<QString> getusers();
public:
    Service();
    database *dbptr;
    // QTimer *timer;
    vector<QString> users;
};

#endif // SERVICE_H
