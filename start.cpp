#include "start.h"
#include "ui_start.h"
#include<QMessageBox>
#include"setup.h"
#include"adminpage.h"
setup *s;
AdminPage *mm;
start::start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("Please Login: ");
}

start::~start()
{
    delete ui;
}

void start::on_login_clicked()
{
    QString username, password;
          username=ui->username->text();
       password=ui->password->text();
       QSqlQuery query;

    if(query.exec("select *from admin where username='"+username+"'and password='"+password+"'"))
    {
        if(username==""||password==""){
            QMessageBox::question(this,"Login Failed","Please Enter Username and Password ");

        }
        else{
        if(query.next()){
            hide();
            mm=new AdminPage(this);
            mm->show();

        }
        else{
                    QMessageBox::critical(this,"Login Failed","Login error, try again ");
                }
        }
}
    else{
    }
}

