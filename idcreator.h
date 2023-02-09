#ifndef IDCREATOR_H
#define IDCREATOR_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>

namespace Ui {
class idcreator;
}

class idcreator : public QDialog
{
    Q_OBJECT

public:
    explicit idcreator(QWidget *parent = nullptr);
    ~idcreator();

private slots:

    void on_save_clicked();

private:
    Ui::idcreator *ui;
    QSqlDatabase mydb;

};

#endif // IDCREATOR_H
