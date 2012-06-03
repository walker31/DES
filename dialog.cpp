#include "dialog.h"
#include "ui_dialog.h"
#include "DES.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

   ui->mingwen_input_lineEdit->setMaxLength( 8 );
   ui->miwen_input_lineEdit->setMaxLength( 8 );
   ui->jiemi_key_input_lineEdit->setMaxLength( 8 );
    QObject::connect(ui->encryption_btn,SIGNAL(clicked()),this,SLOT(on_encryption_btn_clicked()));
    QObject::connect(ui->decryption_btn,SIGNAL(clicked()),this,SLOT(on_decryption_btn_clicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_encryption_btn_clicked()
{

    QString mingwen = ui->mingwen_input_lineEdit->text();
    QString user_key = ui->miwen_input_lineEdit->text();
    QString encryption_result;
    encryption_result = EncodeMain(mingwen,user_key);
    ui->miwen_output_lineEdit->setText(encryption_result);
}


void Dialog::on_decryption_btn_clicked()
{

    QString key_test = ui->jiemi_key_input_lineEdit->text();
    QString miwen = ui->jiemi_output_lineEdit->text();
    QString decryption_result;
    decryption_result= DecodeMain(miwen,key_test);
    ui->jiemi_output_lineEdit->setText(decryption_result);
}

void Dialog::on_exitButton_clicked()
{
    exit(0);
}
