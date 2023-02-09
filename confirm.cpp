#include "confirm.h"
#include "ui_confirm.h"
#include"voteme.h"
#include "votektm.h"
votektm *vkt;
voteme *lg;
confirm::confirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirm)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("PLEASE  Confirm Your ID");
}

confirm::~confirm()
{
    delete ui;
}

void confirm::on_confirmid_clicked()
{
    QString username, password, Cpassword, address;
          username=ui->username->text();
       password=ui->password->text();
       Cpassword=ui->Cpassword->text();
address=ui->address->currentText();
       QSqlQuery query;
if(address=="Chitwan"){
    if(query.exec("select *from signup where username='"+username+"'and password='"+password+"'"))
    {

        if(username==""||password==""){
            QMessageBox::critical(this,"Confirmation Failed","Please Enter Username and Password ");

        }
        else{
            if(password!=Cpassword){
                QMessageBox::critical(this,"Confirmation Failed","Password Confirmation error!! ");

            }
            else{
        if(query.next()){
            query.prepare("DELETE FROM signup where username='"+username+"'and password='"+password+"' ");
             if(query.exec()){


                 hide();
                 lg=new voteme(this);
                 lg->show();
        }
             else{
                 ui->connect->setText("Something is wrong");
             }
        }
        else{
                    QMessageBox::critical(this,"Confirmation Failed","Confirmation error, try again!");
                }


        }

}
    }
    else  {}
}
else{
    if(query.exec("select *from kathmandu where username='"+username+"'and password='"+password+"'"))
    {

        if(username==""||password==""){
            QMessageBox::critical(this,"Confirmation Failed","Please Enter Username and Password ");

        }
        else{
            if(password!=Cpassword){
                QMessageBox::critical(this,"Confirmation Failed","Password Confirmation error!! ");

            }
            else{
        if(query.next()){
            query.prepare("DELETE FROM kathmandu where username='"+username+"'and password='"+password+"' ");
             if(query.exec()){
                 hide();
                 vkt=new votektm(this);
                 vkt->show();
        }
             else{
                 ui->connect->setText("Something is wrong");
             }
        }
        else{
                    QMessageBox::critical(this,"Confirmation Failed","Confirmation error, try again!!");
                }


        }

}
    }
    else  {}

}
}
