#ifndef VOTERID_H
#define VOTERID_H
#include<cstdlib>
#include <QDialog>
#include<QMessageBox>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<idcreator.h>
namespace Ui {
class VoterID;
}

class VoterID : public QDialog
{
    Q_OBJECT

public:
    explicit VoterID(QWidget *parent = nullptr);
    ~VoterID();

private slots:
    void on_signup_clicked();

    void on_pushButton_clicked();

    void on_verify_clicked();

private:
    Ui::VoterID *ui;
    QSqlDatabase mydb;
};

#endif // VOTERID_H
