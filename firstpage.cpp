#include "firstpage.h"
#include "ui_firstpage.h"
#include<QMessageBox>
#include"admin.h"
#include"voterwindow.h"
Admin *yy;
voterwindow *zz;
firstpage::firstpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstpage)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

}

firstpage::~firstpage()
{
    delete ui;
}

void firstpage::on_admin_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Admin","Do you want to enter as Admin? ",
                                                                           QMessageBox:: Yes | QMessageBox:: No );
               if (reply==QMessageBox::Yes){
                   hide();
                   yy = new Admin(this);
                   yy->show();
               }
               else{

               }

}


void firstpage::on_voter_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Voter","Do you want to enter as Voter? ",
                                                                           QMessageBox:: Yes | QMessageBox:: No );
               if (reply==QMessageBox::Yes){
                   hide();
                   zz = new voterwindow(this);
                   zz->show();
               }
               else{

               }
}

