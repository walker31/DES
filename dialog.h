#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void on_decryption_btn_clicked();
    void on_encryption_btn_clicked();
    void on_exitButton_clicked();
};

#endif // DIALOG_H
