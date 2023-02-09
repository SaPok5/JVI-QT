#include "voteme.h"
#include "ui_voteme.h"
#include<QPixmap>
#include<QMessageBox>
#include"firstpage.h"
firstpage *fp;
voteme::voteme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voteme)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("You Can Vote");
    QSqlQuery query;
    query.prepare( "CREATE TABLE IF NOT EXISTS vote1(id INTEGER not null primary key, vote INTEGER);");
    if(query.exec()){
        ui->connect->setText("You Can Vote");
    }
    else
        ui->connect->setText("Something is wrong, try restarting");
    query.prepare( "CREATE TABLE IF NOT EXISTS vote2( vote2	INTEGER, id	INTEGER not null primary key);" );

    if(query.exec()){
        ui->connect->setText("You Can Vote");
    }
    else
        ui->connect->setText("Something is wrong, try restarting");




   { QString votefor;
QSqlQuery query("SELECT votefor FROM candidate");
while (query.next()) {
    votefor.append( query.value(0).toString() + " ");

}
ui->votefor->setText(votefor);
    }
    { QString  name1;
 QSqlQuery query("SELECT name1 FROM candidate");
 while (query.next()) {
     name1.append( query.value(0).toString() + " ");

 }
 ui->name1->setText(name1);
     }
    { QString name2;
 QSqlQuery query("SELECT name2 FROM candidate");
 while (query.next()) {
     name2.append( query.value(0).toString() + " ");
 }
 ui->name2->setText(name2);
     }
    {
        QString candidate_1_img;
QString p1;
        QSqlQuery query("SELECT candidate_1_img FROM candidate");
        while (query.next()) {
          p1 =   candidate_1_img.append( query.value(0).toString());

        }
        QString filename = p1;
        QPixmap pixmapTarget = QPixmap(filename);
        pixmapTarget = pixmapTarget.scaled(ui->candidate_1_img->width(), ui->candidate_1_img->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
        ui->candidate_1_img->setPixmap(pixmapTarget);
            }

    {
        QString candidate_2_img;
        QString p1;
                QSqlQuery query("SELECT candidate_2_img FROM candidate");
                while (query.next()) {
                  p1 =   candidate_2_img.append( query.value(0).toString());

                }
                QString filename = p1;
                QPixmap pixmapTarget = QPixmap(filename);
                pixmapTarget = pixmapTarget.scaled(ui->candidate_2_img->width(), ui->candidate_2_img->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
                ui->candidate_2_img->setPixmap(pixmapTarget);
        }
    }
voteme::~voteme()
{
    delete ui;
}

int voe=0;

void voteme::on_vote1_clicked()
{


        QMessageBox::StandardButton reply = QMessageBox::question(this,"Confirm Vote","Please press yes to confirm your vote ",
                                                                               QMessageBox:: Yes | QMessageBox:: No );
                   if (reply==QMessageBox::No){
                                        }
                             else{
                       voe++;
                       QSqlQuery query;

                       query.prepare( "INSERT INTO vote1 (vote) VALUES (?)" );
                          query.addBindValue(voe);
                          if(query.exec()){
                              hide();
                              fp=new firstpage(this);
                              fp->show();

                                                    }
                                            else{
                                                        QMessageBox::critical(this,"Voting Failed","Voting Error, try again ");
                                                    }
                           }


                              }


int vote1;
void voteme::on_vote2_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this,"Confirm Vote","Please press yes to confirm your vote ",
                                                                           QMessageBox:: Yes | QMessageBox:: No );
               if (reply==QMessageBox::No){
                                    }
                         else{
                   vote1++;
                   QSqlQuery query;

                   query.prepare( "INSERT INTO vote2 (vote2) VALUES (?)" );
                      query.addBindValue(vote1);
                      if(query.exec()){
hide();
fp=new firstpage(this);
fp->show();

                      }
                                        else{
                                                    QMessageBox::critical(this,"Voting Failed","Voting Error, try again ");
                                                }
                       }
}
