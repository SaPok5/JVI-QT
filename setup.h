#ifndef SETUP_H
#define SETUP_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>

namespace Ui {
class setup;
}

class setup : public QDialog
{
    Q_OBJECT

public:
    explicit setup(QWidget *parent = nullptr);
    ~setup();

private slots:
    void on_add1_clicked();

    void on_add2_clicked();

    void on_back_clicked();

    void on_start_clicked();

private:
    Ui::setup *ui;
    QSqlDatabase mydb;

};

#endif // SETUP_H
