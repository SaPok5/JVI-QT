#include "voterid.h"
#include "ui_voterid.h"
#include<cstdlib>
#include<string.h>
#include <QLCDNumber>
#include<time.h>
#include <QStatusBar>
#include<QMessageBox>
#include"voterwindow.h"
#include "kathmandu.h"
kathmandu *kth;
voterwindow *mw;
idcreator *id;
VoterID::VoterID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VoterID)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("You can fill the form");
}

VoterID::~VoterID()
{
    delete ui;
}
int yeary,monthy,dayy;

void VoterID::on_signup_clicked()
{
QString firstname,middlename,lastname;
    QString  citizen,gender,date, address;
    firstname=ui->firstname->text();
    middlename=ui->middlename->text();
    lastname=ui->lastname->text();
    QString year=ui->year->text();
    QString month =ui->month->text();
    QString day=ui->day->text();
    citizen=ui->citizen->text();
    gender=ui->gender->text();
    date=ui->date->text();
address=ui->address->currentText();
QSqlQuery qry;
{
    {
 QSqlQuery query("SELECT year FROM nd where citizen='"+citizen+"'");
 if (query.next()) {
     yeary = query.value(0).toInt();
 }
}
{
QSqlQuery query("SELECT month FROM nd where citizen='"+citizen+"'");
if (query.next()) {
 monthy = query.value(0).toInt();
}
}
{
QSqlQuery query("SELECT day FROM nd where citizen='"+citizen+"'");
if (query.next()) {
 dayy = query.value(0).toInt();
}
}
}
if(yeary>=2004&&monthy>=05&&dayy>=06){
            QMessageBox::critical(this,"Not Eligible","Your Age is not Eligibale to vote");
}
 else if(firstname==""||lastname==""){
QMessageBox::critical(this,"Verification Failed","Please Enter Names Correctly ");
}
else if(citizen==""){
QMessageBox::critical(this,"Verification Failed","Please Enter CitizenID Correctly ");
}

else if(gender==""){
QMessageBox::critical(this,"Verification Failed","Please Enter Gender Correctly ");
}

else{

if(qry.exec("select *from nd where first_name='"+firstname+"'and middle_name='"+middlename+"'and last_name='"+lastname+"'and year='"+year+"'and month='"+month+"'and day='"+day+"'and citizen='"+citizen+"'and issue='"+date+"'and gender='"+gender+"'and address='"+address+"'"))
{
    if(!qry.next()){
        QMessageBox::critical(this,"Verification Failed","Please Enter correct information !");

       }
    else {

        qry.prepare( "INSERT INTO backup (first_name,middle_name,last_name,year,month,day,citizen,issue,gender,address) VALUES (?,?,?,?,?,?,?,?,?,?)" );
        qry.addBindValue(firstname);
        qry.addBindValue(middlename);
        qry.addBindValue(lastname);
        qry.addBindValue(year);
        qry.addBindValue(month);
        qry.addBindValue(day);
        qry.addBindValue(citizen);
        qry.addBindValue(date);
        qry.addBindValue(gender);
        qry.addBindValue(address);
        if(qry.exec()){
                        qry.prepare("DELETE FROM nd where first_name='"+firstname+"'and middle_name='"+middlename+"'and last_name='"+lastname+"'and year='"+year+"'and month='"+month+"'and day='"+day+"'and citizen='"+citizen+"'and issue='"+date+"'and address='"+address+"'and gender='"+gender+"'");
        if(qry.exec()){
            if(address=="Kathmandu"){
                hide();
                kth=new kathmandu(this);
                kth->show();
            }
            else{
                        hide();
                        id=new idcreator(this);
                        id->show();
            }
                        }

                    else{}
                }
            else{
                        QMessageBox::critical(this,"Veriication Failed","Verification error, try again ");
                    }
        }
            }
        }

}

void VoterID::on_pushButton_clicked()
{
                   hide();
                   mw=new voterwindow(this);
                   mw->show();
}

