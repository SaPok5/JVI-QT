#include "adminsignup.h"
#include "ui_adminsignup.h"
#include "admin.h"
Admin *elor;
adminsignup::adminsignup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminsignup)
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
        ui->connect->setText("PLEASE SIGN UP");
    }
    else
        ui->connect->setText("Something is wrong, try restarting");
}

adminsignup::~adminsignup()
{
    delete ui;
}

void adminsignup::on_signup_clicked()
{
   int id=0;
 QSqlQuery query("SELECT COUNT(*) FROM admin");
 if (query.next()) {
     id = query.value(0).toInt();
 }
if(id>1){
    QMessageBox::critical(this,"SignUp Failed","Admin Limit full");

}
else{
    QString username, password, Cpassword;
          username=ui->username->text();
       password=ui->password->text();
       Cpassword=ui->Cpassword->text();
       query.prepare( "SELECT *FROM admin WHERE username = '"+username+"' ");

       if(query.exec()){
           if(username==""||password==""){
               QMessageBox::critical(this,"SignUp Failed","Please Enter Username and Password ");

           }
           else{
               if(password!=Cpassword){
                   QMessageBox::critical(this,"SignUp Failed","Password Confirmation error!! ");

               }
               else{
           if(query.next()){
               QMessageBox::critical(this,"SignUp Failed","Admin already exist ");
           }

       else{
               query.prepare( "INSERT INTO admin (username, password) VALUES (?, ?)" );
                                         query.addBindValue(username);
                                         query.addBindValue(password);

if(query.exec()){
 QMessageBox::StandardButton reply = QMessageBox::question(this,"SignUp Successful","Do you Want to Login? ",
                     QMessageBox:: Yes | QMessageBox:: No );
 if (reply==QMessageBox::Yes){
hide();
elor=new Admin(this);
elor->show();
 }
else{
         this->close();
                   }
}
    else{
  QMessageBox::critical(this,"SignUp Failed","Signup error, try again!! ");
      }


     }

       }
       }

           }
}


}

void adminsignup::on_login_clicked()
{
    hide();
    elor=new Admin(this);
    elor->show();
}

