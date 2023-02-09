#ifndef VOTERWINDOW_H
#define VOTERWINDOW_H

#include <QDialog>

namespace Ui {
class voterwindow;
}

class voterwindow : public QDialog
{
    Q_OBJECT

public:
    explicit voterwindow(QWidget *parent = nullptr);
    ~voterwindow();

private slots:
    void on_create_clicked();

    void on_vote_clicked();

    void on_pushButton_clicked();

private:
    Ui::voterwindow *ui;
};

#endif // VOTERWINDOW_H
