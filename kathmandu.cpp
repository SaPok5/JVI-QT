#include "kathmandu.h"
#include "ui_kathmandu.h"
#include"voterid.h"
#include"confirm.h"

VoterID *vid1;
confirm *vm1;
kathmandu::kathmandu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kathmandu)
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
        query.prepare( "CREATE TABLE IF NOT EXISTS kathmandu(username TEXT, password TEXT);");
        if(query.exec()){
            ui->connect->setText("PLEASE SIGN UP");
        }
        else
            ui->connect->setText("Something is wrong, try restarting");
}

kathmandu::~kathmandu()
{
    delete ui;
}

void kathmandu::on_save_clicked()
{
QString username, password, Cpassword;
      username=ui->username->text();
   password=ui->password->text();
   Cpassword=ui->Cpassword->text();


   QSqlQuery query;
   query.prepare( "SELECT *FROM kathmandu WHERE username = '"+username+"'");
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


    query.prepare( "INSERT INTO kathmandu (username, password) VALUES (?, ?)" );
       query.addBindValue(username);
           query.addBindValue(password);

           if(query.exec()){
                QMessageBox::StandardButton reply = QMessageBox::question(this,"SignUp Successful","Click:   \n Open->To Vote Immediately \n Cancel-> To Save VoterID ",
                                                                                       QMessageBox:: Open | QMessageBox:: Cancel );
                           if (reply==QMessageBox::Cancel){
                          hide();
                           vid1=new VoterID(this);
                           vid1->show();
                                     }
                                     else{
                                     hide();
                                       vm1=new confirm(this);
                                       vm1->show();
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

