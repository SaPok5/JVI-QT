#ifndef ADMINSIGNUP_H
#define ADMINSIGNUP_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>

namespace Ui {
class adminsignup;
}

class adminsignup : public QDialog
{
    Q_OBJECT

public:
    explicit adminsignup(QWidget *parent = nullptr);
    ~adminsignup();

private slots:
    void on_signup_clicked();

    void on_login_clicked();

private:
    Ui::adminsignup *ui;
    QSqlDatabase mydb;

};

#endif // ADMINSIGNUP_H
