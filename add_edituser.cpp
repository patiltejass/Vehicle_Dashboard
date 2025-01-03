#include "add_edituser.h"
#include "ui_add_edituser.h"

Add_EditUser::Add_EditUser(vector<QString>&users,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_EditUser),
    Users(users)
{

    ui->setupUi(this);

    connect(ui->radioButton, &QRadioButton::clicked, this, &Add_EditUser::updateWidget);
    connect(ui->radioButton_2, &QRadioButton::clicked, this, &Add_EditUser::updateWidget);
    ui->comboBox_4->addItem("Dark");
    ui->comboBox_4->addItem("Light");
    ui->comboBox_5->addItem("ECO");
    ui->comboBox_5->addItem("Sports");
    ui->comboBox_2->addItem("Dark");
    ui->comboBox_2->addItem("Light");
    ui->comboBox_3->addItem("ECO");
    ui->comboBox_3->addItem("Sports");
    updateusers();

}
void Add_EditUser::updateWidget(){

    if(ui->radioButton->isChecked()){
        ui->stackedWidget->setCurrentWidget(ui->add_user);
    }
    else if(ui->radioButton_2->isChecked()){
        ui->stackedWidget->setCurrentWidget(ui->edit_user);
    }

}

Add_EditUser::~Add_EditUser()
{
    delete ui;
}

void Add_EditUser::on_pushButton_2_clicked()
{
    name = ui->textEdit_2->toPlainText();
    mode = ui->comboBox_5->currentText();
    theme= ui->comboBox_4->currentText();
    emit useremitter(name, mode,theme);
}

void Add_EditUser::updateusers()
{
    ui->comboBox_6->clear();
    for(auto it:Users){
        ui->comboBox_6->addItem(it);
    }

}


void Add_EditUser::on_pushButton_clicked()
{
    name = ui->comboBox_6->currentText();
    mode = ui->comboBox_3->currentText();
    theme= ui->comboBox_2->currentText();
    emit updateuser_emiter(name, mode,theme);
}

