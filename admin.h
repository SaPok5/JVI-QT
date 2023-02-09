#ifndef ADMIN_H
#define ADMIN_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_signup_clicked();

    void on_login_clicked();

private:
    Ui::Admin *ui;
    QSqlDatabase mydb;

};

#endif // ADMIN_H
