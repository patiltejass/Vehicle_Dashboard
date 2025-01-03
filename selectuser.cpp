#include "selectuser.h"
#include "ui_selectuser.h"

SelectUser::SelectUser(vector<QString>&users,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectUser),
    Users(users)
{
    ui->setupUi(this);
    updateusers();
}

SelectUser::~SelectUser()
{
    delete addedit;
    delete ui;
}

void SelectUser::on_AddUserButton_clicked()
{
    addedit = new Add_EditUser(Users);
    connect(addedit,&Add_EditUser::useremitter,this,&SelectUser::handleemituser);
    connect(addedit,&Add_EditUser::updateuser_emiter,this,&SelectUser::handle_updateuser_emiter);
    addedit->show();
}

void SelectUser::updateusers()
{
    ui->comboBox->clear();
    for(auto it:Users){
        ui->comboBox->addItem(it);
    }
}

void SelectUser::handleemituser(QString name, QString mode, QString theme){
    emit useremiter(name,mode,theme);
}

void SelectUser::handle_updateuser_emiter(QString name, QString mode, QString theme)
{
    qDebug()<<"Selectuser"<<name<<mode<<theme<<" ";
    emit update_user_emiter(name,mode,theme);
}



