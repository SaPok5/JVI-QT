#ifndef INSIGHT_H
#define INSIGHT_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>

namespace Ui {
class insight;
}

class insight : public QDialog
{
    Q_OBJECT

public:
    explicit insight(QWidget *parent = nullptr);
    ~insight();

private slots:
    void on_return_2_clicked();

    void on_show_clicked();

private:
    Ui::insight *ui;
    QSqlDatabase mydb;

};

#endif // INSIGHT_H
