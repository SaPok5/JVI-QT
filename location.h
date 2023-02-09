#ifndef LOCATION_H
#define LOCATION_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>

namespace Ui {
class location;
}

class location : public QDialog
{
    Q_OBJECT

public:
    explicit location(QWidget *parent = nullptr);
    ~location();

private slots:
    void on_pushButton_clicked();

private:
    Ui::location *ui;
    QSqlDatabase mydb;

};

#endif // LOCATION_H
