#include "insight.h"
#include "ui_insight.h"
#include "adminpage.h"
AdminPage *hu;

insight::insight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insight)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open())
        ui->connect->setText("Something is wrong, try restarting");
    else
        ui->connect->setText("Real Time Votes");  
    }


insight::~insight()
{
    delete ui;
}

void insight::on_return_2_clicked()
{
    hide();
    hu=new AdminPage(this);
 hu->show();
}


void insight::on_show_clicked()
{
    QString address;
    address=ui->address->currentText();
    if(address=="Chitwan"){
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
               { int id=0;
            QSqlQuery query("SELECT COUNT(*) FROM vote1");
            if (query.next()) {
                id = query.value(0).toInt();
            }

            ui->vote1->setText(QString::number(id));
                }

               { int id=0;
            QSqlQuery query("SELECT COUNT(*) FROM vote2");
            if (query.next()) {
                id = query.value(0).toInt();
            }

            ui->vote2->setText(QString::number(id));
                }
    }
    else{
        { QString  name1;
     QSqlQuery query("SELECT name1 FROM candidatektm");
     while (query.next()) {
         name1.append( query.value(0).toString() + " ");

     }
     ui->name1->setText(name1);
         }
        { QString name2;
     QSqlQuery query("SELECT name2 FROM candidatektm");
     while (query.next()) {
         name2.append( query.value(0).toString() + " ");
     }
     ui->name2->setText(name2);
         }
        {
            QString candidate_1_img;
    QString p1;
            QSqlQuery query("SELECT candidate_1_img FROM candidatektm");
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
                    QSqlQuery query("SELECT candidate_2_img FROM candidatektm");
                    while (query.next()) {
                      p1 =   candidate_2_img.append( query.value(0).toString());

                    }
                    QString filename = p1;
                    QPixmap pixmapTarget = QPixmap(filename);
                    pixmapTarget = pixmapTarget.scaled(ui->candidate_2_img->width(), ui->candidate_2_img->height(), Qt::IgnoreAspectRatio , Qt::SmoothTransformation);
                    ui->candidate_2_img->setPixmap(pixmapTarget);
            }
        { int id=0;
     QSqlQuery query("SELECT COUNT(*) FROM votektm1");
     if (query.next()) {
         id = query.value(0).toInt();
     }

     ui->vote1->setText(QString::number(id));
         }

        { int id=0;
     QSqlQuery query("SELECT COUNT(*) FROM votektm2");
     if (query.next()) {
         id = query.value(0).toInt();
     }

     ui->vote2->setText(QString::number(id));
         }
    }

}

