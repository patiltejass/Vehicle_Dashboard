#ifndef ADD_EDITUSER_H
#define ADD_EDITUSER_H

#include <QDialog>
#include<vector>
using namespace std;

namespace Ui {
class Add_EditUser;
}

class Add_EditUser : public QDialog
{
    Q_OBJECT

public:
    explicit Add_EditUser(vector<QString>&users,QWidget *parent = nullptr);
    ~Add_EditUser();

signals:
    void useremitter(QString name,QString mode,QString theme);
    void updateuser_emiter(QString name,QString mode,QString theme);


private slots:
    void updateWidget();
    void on_pushButton_2_clicked();
    void updateusers();
    void on_pushButton_clicked();

private:
    Ui::Add_EditUser *ui;
    QString name;
    QString theme;
    QString mode;
    vector<QString> &Users;
    // QVector<QString> user;

};

#endif // ADD_EDITUSER_H
