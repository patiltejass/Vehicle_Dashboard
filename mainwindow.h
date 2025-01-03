#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"Service/Service.h"
#include"Database/Database.h"
#include <QMainWindow>
#include"selectuser.h"
#include<vector>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void main_emitter(QString name, QString mode, QString theme);
    void main_updateuser_emitter(QString name, QString mode, QString theme);
public slots:
    void handle_emitter(QString name, QString mode,QString theme);
    void handle_updateuser_emitter(QString name, QString mode,QString theme);

private slots:
    void on_ManageUser_clicked();
    void start_stop();

private:

    Ui::MainWindow *ui;
    Add_EditUser *add_edit;
    SelectUser *selectuser;
    bool checked ;
    Service *dataprovider;
    vector<QString>*users;
    // Qstring theme;
};
#endif // MAINWINDOW_H
