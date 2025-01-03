#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , checked(false)
{
    ui->setupUi(this);

    // database db;
    dataprovider = new Service;
    users=new vector<QString>;
    connect(ui->StartStopButton, &QPushButton::clicked, this, &MainWindow::start_stop);
    *users=dataprovider->getusers();
    connect(this,&MainWindow::main_emitter,dataprovider,&Service::handleuseremitter);
    connect(this,&MainWindow::main_updateuser_emitter,dataprovider,&Service::handleupdateuseremitter);
}

void MainWindow::start_stop() {
        checked = !checked;  // Toggle the state

    if (checked) {
        // Start actions
        ui->StartStopButton->setText("Stop"); // Example state change
        ui->StartStopButton->setStyleSheet(
            "background-color: rgb(107, 174, 255);"
            "border-radius: 62px;"
            "text-align: center;"
            "color: rgb(255, 255, 255);"
            ); // ...
    } else {
        // Stop actions
        ui->StartStopButton->setText("Start"); // Example state change
        ui->StartStopButton->setStyleSheet(
            "background-color: rgb(45, 45, 45);"
            "border-radius: 62px;"
            "text-align: centre;"
            "color: rgb(255,255,255);"
            ); // ...
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle_emitter(QString name, QString mode, QString theme)
{
    emit main_emitter(name,mode,theme);
}

void MainWindow::handle_updateuser_emitter(QString name, QString mode, QString theme)
{
    emit main_updateuser_emitter(name,mode,theme);
}

void MainWindow::on_ManageUser_clicked()
{
    selectuser = new SelectUser(*users);
    selectuser->show();
    connect(selectuser,&SelectUser::useremiter,this,&MainWindow::handle_emitter);
    connect(selectuser,&SelectUser::update_user_emiter,this,&MainWindow::handle_updateuser_emitter);
}
