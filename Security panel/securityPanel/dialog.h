
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog

{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void inititalize();

private slots:
    void getNumber();

    void on_saveButton_clicked();

    void on_verifyButton_clicked();

private:
    Ui::Dialog *ui;

    QString temp = 0;
    QString code;
};

#endif // DIALOG_H
