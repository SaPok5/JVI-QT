#include "setup.h"
#include "ui_setup.h"
#include "votektm.h"

#include <QPixmap>
#include <QFileDialog>
#include <QtWidgets>
#include"adminpage.h"
#include"voteme.h"
#include<QMessageBox>
#include <QtWidgets>
#include <QPixmap>
votektm *fu;
voteme *dd;
AdminPage *cc;
setup::setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setup)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("Fill the form correctly");
    QSqlQuery query;
    query.prepare( "CREATE TABLE IF NOT EXISTS candidate(candidate_1_img TEXT,candidate_2_img TEXT,name1 TEXT,name2 TEXT,votefor TEXT);");

    if(query.exec()){
        query.prepare( "CREATE TABLE IF NOT EXISTS candidatektm(candidate_1_img TEXT,candidate_2_img TEXT,name1 TEXT,name2 TEXT,votefor TEXT);");
        if(query.exec()){
        ui->connect->setText("Fill the form correctly");
        }
        else{        ui->connect->setText("Something is wrong, try restarting");
}
    }
    else
        ui->connect->setText("Something is wrong, try restarting");
}
setup::~setup()
{
    delete ui;
}
QString filename,filename2;
void setup::on_add1_clicked()
{
      filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap pixmapTarget = QPixmap(filename);
    pixmapTarget = pixmapTarget.scaled(ui->candidate_1_img->width(), ui->candidate_1_img->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
    ui->candidate_1_img->setPixmap(pixmapTarget);
                              }
void setup::on_add2_clicked()
{
     filename2 = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap pixmapTarget = QPixmap(filename2);
    pixmapTarget = pixmapTarget.scaled(ui->candidate_2_img->width(), ui->candidate_2_img->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
    ui->candidate_2_img->setPixmap(pixmapTarget);

                              }
void setup::on_back_clicked()
{
    hide();
    cc=new AdminPage(this);
    cc->show();
}
void setup::on_start_clicked()
{
    QString votefor, name1, name2,address;
    votefor=ui->votefor->text();
 name1=ui->name1->text();
 name2=ui->name2->text();
 address=ui->address->currentText();
 if(address=="Chitwan"){
QSqlQuery query;
query.prepare( "INSERT INTO candidate (votefor,name1,name2,candidate_1_img,candidate_2_img) VALUES (?,?,?,?,?)" );
                          query.addBindValue(votefor);
                          query.addBindValue(name1);
                          query.addBindValue(name2);
                          query.addBindValue(filename);
                          query.addBindValue(filename2);

                          if(query.exec()){
                              QMessageBox::StandardButton reply = QMessageBox::question(this,"Saved","Want to Save Voting System For Chitwan? ",
                                                                                                     QMessageBox:: Yes | QMessageBox:: No );
                                         if (reply==QMessageBox::Yes){
                                             hide();
                                             cc=new AdminPage(this);
                                             cc->show();
                                         }
                                         else{
                                         }
                   }
                          else{
                              ui->connect->setText("Something is wrong, Try Again!!");
}
 }
 else{
     QSqlQuery query;
     query.prepare( "INSERT INTO candidatektm (votefor,name1,name2,candidate_1_img,candidate_2_img) VALUES (?,?,?,?,?)" );
                               query.addBindValue(votefor);
                               query.addBindValue(name1);
                               query.addBindValue(name2);
                               query.addBindValue(filename);
                               query.addBindValue(filename2);

                               if(query.exec()){
                                   QMessageBox::StandardButton reply = QMessageBox::question(this,"Saved","Want to Save Voting System For Kathmandu? ",
                                                                                                          QMessageBox:: Yes | QMessageBox:: No );
                                              if (reply==QMessageBox::Yes){
                                                  hide();
                                                  cc=new AdminPage(this);
                                                  cc->show();
                                              }
                                              else{
                                              }
                        }
                               else{
                                   ui->connect->setText("Something is wrong, Try Again!!");
     }
 }
}
