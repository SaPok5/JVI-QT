#include "publish.h"
#include "ui_publish.h"
#include"QMessageBox"
#include"adminpage.h"
AdminPage *li;
publish::publish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::publish)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("Real Time Winner");

    { QString  votefor;
 QSqlQuery query("SELECT votefor FROM candidate");
 while (query.next()) {
     votefor.append( query.value(0).toString() + " ");

 }
 ui->votefor->setText(votefor);
     }
int id=0;
{
        QSqlQuery query("SELECT COUNT(*) FROM vote1");
        if (query.next()) {
            id = query.value(0).toInt();
        }


        int id2=0;{
QSqlQuery query("SELECT COUNT(*) FROM vote2");
if (query.next()) {
    id2 = query.value(0).toInt();
}
}

if(id>id2){
    {
        QString candidate_1_img;
QString p1;
        QSqlQuery query("SELECT candidate_1_img FROM candidate");
        while (query.next()) {
          p1 =   candidate_1_img.append( query.value(0).toString());

        }
        QString filename = p1;
        QPixmap pixmapTarget = QPixmap(filename);
        pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
        ui->winner->setPixmap(pixmapTarget);
            }
    { QString  name1;
 QSqlQuery query("SELECT name1 FROM candidate");
 while (query.next()) {
     name1.append( query.value(0).toString() + " ");

 }
 ui->name->setText(name1);
     }
}
else if(id<id2){
    {
        QString candidate_2_img;
        QString p1;
                QSqlQuery query("SELECT candidate_2_img FROM candidate");
                while (query.next()) {
                  p1 =   candidate_2_img.append( query.value(0).toString());

                }
                QString filename = p1;
                QPixmap pixmapTarget = QPixmap(filename);
                pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
                ui->winner->setPixmap(pixmapTarget);
        }
    { QString  name2;
 QSqlQuery query("SELECT name2 FROM candidate");
 while (query.next()) {
     name2.append( query.value(0).toString() + " ");

 }
 ui->name->setText(name2);
     }
}
else{
    {
        QString candidate_1_img;
QString p1;
        QSqlQuery query("SELECT candidate_1_img FROM candidate");
        while (query.next()) {
          p1 =   candidate_1_img.append( query.value(0).toString());

        }
        QString filename = p1;
        QPixmap pixmapTarget = QPixmap(filename);
        pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
        ui->winner->setPixmap(pixmapTarget);
            }
    { QString  name1;
 QSqlQuery query("SELECT name1 FROM candidate");
 while (query.next()) {
     name1.append( query.value(0).toString() + " ");

 }
 ui->name->setText(name1);
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
                pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
                ui->winner2->setPixmap(pixmapTarget);
        }
    { QString  name2;
 QSqlQuery query("SELECT name2 FROM candidate");
 while (query.next()) {
     name2.append( query.value(0).toString() + " ");

 }
 ui->name2->setText(name2);
     }
}
     }
{ QString  votefor_2;
QSqlQuery query("SELECT votefor FROM candidatektm");
while (query.next()) {
 votefor_2.append( query.value(0).toString() + " ");

}
ui->votefor_2->setText(votefor_2);
 }
int ild=0;
{
    QSqlQuery query("SELECT COUNT(*) FROM votektm1");
    if (query.next()) {
        ild = query.value(0).toInt();
    }


    int ild2=0;{
QSqlQuery query("SELECT COUNT(*) FROM votektm2");
if (query.next()) {
ild2 = query.value(0).toInt();
}
}

if(ild>ild2){
{
    QString candidate_1_img_2;
QString p1;
    QSqlQuery query("SELECT candidate_1_img FROM candidatektm");
    while (query.next()) {
      p1 =   candidate_1_img_2.append( query.value(0).toString());

    }
    QString filename = p1;
    QPixmap pixmapTarget = QPixmap(filename);
    pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
    ui->winner_2->setPixmap(pixmapTarget);
        }
{ QString  name1;
QSqlQuery query("SELECT name1 FROM candidatektm");
while (query.next()) {
 name1.append( query.value(0).toString() + " ");

}
ui->name_2->setText(name1);
 }
}
else if(ild<ild2){
{
    QString candidate_2_img;
    QString p1;
            QSqlQuery query("SELECT candidate_2_img FROM candidate");
            while (query.next()) {
              p1 =   candidate_2_img.append( query.value(0).toString());

            }
            QString filename = p1;
            QPixmap pixmapTarget = QPixmap(filename);
            pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
            ui->winner_2->setPixmap(pixmapTarget);
    }
{ QString  name2;
QSqlQuery query("SELECT name2 FROM candidate");
while (query.next()) {
 name2.append( query.value(0).toString() + " ");

}
ui->name_2->setText(name2);
 }
}
else{
{
    QString candidate_1_img;
QString p1;
    QSqlQuery query("SELECT candidate_1_img FROM candidate");
    while (query.next()) {
      p1 =   candidate_1_img.append( query.value(0).toString());

    }
    QString filename = p1;
    QPixmap pixmapTarget = QPixmap(filename);
    pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
    ui->winner_2->setPixmap(pixmapTarget);
        }
{ QString  name1;
QSqlQuery query("SELECT name1 FROM candidatektm");
while (query.next()) {
 name1.append( query.value(0).toString() + " ");

}
ui->name_2->setText(name1);
 }
{
    QString candidate_2_img;
    QString p1;
            QSqlQuery query("SELECT candidate_2_img FROM candidatektm");
            while (query.next()) {
              p1 =   candidate_2_img.append( query.value(0).toString());

            }
            QString filename = p1;
            QPixmap pixmapTarget = QPixmap(filename);
            pixmapTarget = pixmapTarget.scaled(ui->winner->width(), ui->winner->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
            ui->winner2_2->setPixmap(pixmapTarget);
    }
{ QString  name2;
QSqlQuery query("SELECT name2 FROM candidatektm");
while (query.next()) {
 name2.append( query.value(0).toString() + " ");

}
ui->name2_2->setText(name2);
 }
}
 }
    }


publish::~publish()
{
    delete ui;
}

void publish::on_endVoting_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"End Voting??","Do you want to end voting system? ",
                                                                           QMessageBox:: Yes | QMessageBox:: No );
               if (reply==QMessageBox::Yes){
                   QSqlQuery q;
                   q.exec(QString("DROP TABLE candidate;"));
                   q.exec(QString("DROP TABLE signup;"));
                   q.exec(QString("DROP TABLE admin;"));
                   q.exec(QString("DROP TABLE vote1;"));
                   q.exec(QString("DROP TABLE vote2;"));
                   q.exec(QString("DROP TABLE votektm2;"));
                   q.exec(QString("DROP TABLE votektm1;"));
                   q.exec(QString("DROP TABLE kathmandu;"));
                   q.exec(QString("DROP TABLE candidatektm;"));
                   this->close();
                         }
                         else{

                       }
}


void publish::on_pushButton_clicked()
{
    hide();
    li=new AdminPage(this);
    li->show();
}

