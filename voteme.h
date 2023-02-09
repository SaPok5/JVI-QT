#ifndef VOTEME_H
#define VOTEME_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<QMessageBox>
namespace Ui {
class voteme;
}

class voteme : public QDialog
{
    Q_OBJECT

public:
    explicit voteme(QWidget *parent = nullptr);
    ~voteme();

private slots:

    void on_vote1_clicked();

    void on_vote2_clicked();

private:
    Ui::voteme *ui;
    QSqlDatabase mydb;

};

#endif // VOTEME_H
