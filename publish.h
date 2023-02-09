#ifndef PUBLISH_H
#define PUBLISH_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>
namespace Ui {
class publish;
}

class publish : public QDialog
{
    Q_OBJECT

public:
    explicit publish(QWidget *parent = nullptr);
    ~publish();

private slots:
    void on_endVoting_clicked();

    void on_pushButton_clicked();

private:
    Ui::publish *ui;
    QSqlDatabase mydb;

};

#endif // PUBLISH_H
