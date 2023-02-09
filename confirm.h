#ifndef CONFIRM_H
#define CONFIRM_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>
namespace Ui {
class confirm;
}

class confirm : public QDialog
{
    Q_OBJECT

public:
    explicit confirm(QWidget *parent = nullptr);
    ~confirm();

private slots:
    void on_confirmid_clicked();

private:
    Ui::confirm *ui;
    QSqlDatabase mydb;

};

#endif // CONFIRM_H
