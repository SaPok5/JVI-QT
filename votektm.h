#ifndef VOTEKTM_H
#define VOTEKTM_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>
namespace Ui {
class votektm;
}

class votektm : public QDialog
{
    Q_OBJECT

public:
    explicit votektm(QWidget *parent = nullptr);
    ~votektm();

private slots:
    void on_vote1_clicked();

    void on_vote2_clicked();

private:
    Ui::votektm *ui;
    QSqlDatabase mydb;

};

#endif // VOTEKTM_H
