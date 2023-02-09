#include "admin.h"
#include "adminsignup.h"

#include "ui_admin.h"
#include<QMessageBox>
#include"adminpage.h"
AdminPage *mn;
Admin *ad;
adminsignup *sh;
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("You can fill the form");
    QSqlQuery query;
    query.prepare( "CREATE TABLE IF NOT EXISTS admin(username TEXT, password TEXT);");
    if(query.exec()){
        ui->connect->setText("PLEASE Login");
    }
    else
        ui->connect->setText("Something is wrong, try restarting");
}

Admin::~Admin()
{
    delete ui;
}




void Admin::on_signup_clicked()
{

    hide();
    sh=new adminsignup(this);
    sh->show();

}

void Admin::on_login_clicked()
{
    QString username, password,Cpassword;
          username=ui->username->text();
       password=ui->password->text();
       Cpassword=ui->Cpassword->text();

       QSqlQuery query;

    if(query.exec("select *from admin where username='"+username+"'and password='"+password+"'"))
    {

        if(username==""||password==""){
            QMessageBox::critical(this,"SignUp Failed","Please Enter Username and Password ");

        }
        else{
            if(password!=Cpassword){
                QMessageBox::critical(this,"SignUp Failed","Password Confirmation error!! ");

            }
            else{
        if(query.next()){
            hide();
            mn=new AdminPage(this);
            mn->show();
        }
        else{
                    QMessageBox::critical(this,"Login Failed","Login error, try again ");
                }


        }

}
    }
}

