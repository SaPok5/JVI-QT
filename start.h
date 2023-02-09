#ifndef START_H
#define START_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();

private slots:
    void on_login_clicked();

private:
    Ui::start *ui;
    QSqlDatabase mydb;

};

#endif // START_H
