#include "Service.h"

Service::Service():dbptr(database::objectprovider()){
    users=dbptr->getusers();
}

vector<QString> Service::getusers()
{
    return users;
}

void Service::handleuseremitter(QString name, QString mode, QString theme){
    qDebug()<<name<<mode<<theme;
    dbptr->insert_user(name,mode,theme);
}

void Service::handleupdateuseremitter(QString name, QString mode, QString theme)
{
    dbptr->update_user(name,mode,theme);
}

// QString Service::gettheme()
// {
//     QString theme= dbptr->gettheme();
//     return theme;
// }



