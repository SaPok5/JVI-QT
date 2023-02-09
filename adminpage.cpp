#include "adminpage.h"
#include "ui_adminpage.h"
#include"voterid.h"
#include"start.h"
#include"setup.h"
#include"voterid.h"
#include "insight.h"
#include "voterwindow.h"
#include "publish.h"
publish *pu;
voterwindow *er;
VoterID *h1;
insight *lo;
setup *st;

AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/SQLite/Database.db");
    if(!mydb.open()){}
    else{}
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_voterid_clicked()
{
    hide();
    h1= new VoterID(this);
    h1->show();
}


void AdminPage::on_votingsystem_clicked()
{
    hide();
    st=new setup(this);
    st->show();
}


void AdminPage::on_voterwin_clicked()
{
    hide();
    er=new voterwindow(this);
    er->show();

}


void AdminPage::on_insight_clicked()
{
    hide();
    lo=new insight(this);
    lo->show();

}


void AdminPage::on_pushButton_clicked()
{
    hide();
    pu=new publish(this);
    pu->show();

}


void AdminPage::on_pushButton_2_clicked()
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

