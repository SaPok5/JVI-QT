#include "voterwindow.h"
#include "ui_voterwindow.h"
#include"confirm.h"
#include"voterid.h"
#include"start.h"
start *gg;
confirm *aa;
VoterID *bb;
voterwindow::voterwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voterwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("JVI");

}

voterwindow::~voterwindow()
{
    delete ui;
}

void voterwindow::on_create_clicked()
{
    hide();
    bb= new VoterID(this);
    bb->show();
}


void voterwindow::on_vote_clicked()
{
    hide();
    aa=new confirm(this);
    aa->show();
}

void voterwindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Admin","Go to Admin Window? ",
                                                                           QMessageBox:: Yes | QMessageBox:: No );
               if (reply==QMessageBox::Yes){
                   hide();
                   gg=new start(this);
                   gg->show();
               }
               else{

   }

}

