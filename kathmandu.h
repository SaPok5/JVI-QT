#ifndef KATHMANDU_H
#define KATHMANDU_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>
namespace Ui {
class kathmandu;
}

class kathmandu : public QDialog
{
    Q_OBJECT

public:
    explicit kathmandu(QWidget *parent = nullptr);
    ~kathmandu();

private slots:
    void on_save_clicked();

private:
    Ui::kathmandu *ui;
    QSqlDatabase mydb;

};

#endif // KATHMANDU_H
