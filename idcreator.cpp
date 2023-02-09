#include "idcreator.h"
#include "ui_idcreator.h"
#include<QMessageBox>
#include"confirm.h"
#include"voterid.h"
VoterID *vid;
confirm *vm;
idcreator::idcreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::idcreator)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/SQLite/Database.db");
        if(!mydb.open())
            ui->connect->setText("Something is wrong, try restarting");
        else
            ui->connect->setText("PLEASE SIGN UP");
        QSqlQuery query;
        query.prepare( "CREATE TABLE IF NOT EXISTS signup(username TEXT, password TEXT);");
        if(query.exec()){
            ui->connect->setText("PLEASE SIGN UP");
        }
        else
            ui->connect->setText("Something is wrong, try restarting");



}

idcreator::~idcreator()
{
    delete ui;
}
int i;
void idcreator::on_save_clicked()
{
    QString username, password, Cpassword;
          username=ui->username->text();
       password=ui->password->text();
       Cpassword=ui->Cpassword->text();


       QSqlQuery query;
       query.prepare( "SELECT *FROM signup WHERE username = '"+username+"'");
       if(query.exec()){
           if(username==""||password==""){
               QMessageBox::critical(this,"SignUp Failed","Please Enter Username or password ");

           }
           else{
               if(password!=Cpassword){
                   QMessageBox::critical(this,"SignUp Failed","Password Confirmation error!! ");

               }
               else{
           if(query.next()){
               QMessageBox::critical(this,"SignUp Failed","Username already exist, Try again!");
           }

       else{


        query.prepare( "INSERT INTO signup (username, password) VALUES (?, ?)" );
           query.addBindValue(username);
               query.addBindValue(password);

               if(query.exec()){
                    QMessageBox::StandardButton reply = QMessageBox::question(this,"SignUp Successful","Do you want to  vote now? ",
                                                                                           QMessageBox:: Yes | QMessageBox:: No );
                               if (reply==QMessageBox::Yes){
                              hide();
                              vm=new confirm(this);
                              vm->show();
                                         }
                                         else{
                                         hide();
                                           vid=new VoterID(this);
                                           vid->show();
                                       }
                                         }
                                 else{
                                             QMessageBox::critical(this,"SignUp Failed","Signup error, try again ");
                                         }
       }

           }
           }
       }
}



