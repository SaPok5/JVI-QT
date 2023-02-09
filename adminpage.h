#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_voterid_clicked();

    void on_votingsystem_clicked();

    void on_voterwin_clicked();

    void on_insight_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminPage *ui;
    QSqlDatabase mydb;

};

#endif // ADMINPAGE_H
