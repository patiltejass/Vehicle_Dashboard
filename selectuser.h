#ifndef SELECTUSER_H
#define SELECTUSER_H

#include <QDialog>
#include"add_edituser.h"
#include"Service/Service.h"

namespace Ui {
class SelectUser;
}

class SelectUser : public QDialog
{
    Q_OBJECT

public:
    explicit SelectUser(vector<QString>&users,QWidget *parent = nullptr);
    ~SelectUser();

signals:
    void useremiter(QString name,QString mode,QString theme);
    void update_user_emiter(QString name,QString mode,QString theme);
public slots:
    void handleemituser(QString name,QString mode,QString theme);
    void handle_updateuser_emiter(QString name,QString mode,QString theme);
private slots:
    void on_AddUserButton_clicked();
    void updateusers();

private:
    Ui::SelectUser *ui;
    Add_EditUser *addedit;
    vector<QString> &Users;
};

#endif // SELECTUSER_H
