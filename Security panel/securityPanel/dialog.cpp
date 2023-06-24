
#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    inititalize();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::inititalize()
{
    ui->setupUi(this);

    ui->SecureNumber->setStyleSheet("font-size: 24px;");
    ui->saveButton->setDisabled(true);
    ui->verifyButton->setDisabled(true);

    QGridLayout* numbersGrid = ui->numbers;

    for (int i = 0; i < numbersGrid->count(); ++i)
    {
        if (QPushButton* button = qobject_cast<QPushButton*>(numbersGrid->itemAt(i)->widget()))
        {
            connect(button, &QPushButton::clicked, this, &Dialog::getNumber);
        }
    }
}

void Dialog::getNumber()
{
    QLabel *outputLabel = ui->SecureNumber;

    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    if(temp.length() < 4)
        temp = temp + clickedButton->text();

    if(code.isEmpty() && temp.length() == 4)
        ui->saveButton->setDisabled(false);

    if(!code.isEmpty() && temp.length() == 4)
        ui->verifyButton->setDisabled(false);

    if(temp.length() <= 4)
        outputLabel->setText("Security Code: " + temp);
}


void Dialog::on_saveButton_clicked()
{
    if(temp.length() == 4)
    {
        code = temp;
        temp.clear();
        ui->SecureNumber->setText("");
        ui->saveButton->setDisabled(true);
        QMessageBox::information(this, "Accepted", "Your security Code has been accepted!");
    }
}


void Dialog::on_verifyButton_clicked()
{
    if(temp.length() == 4)
    {
        if(code == temp)
        {
            temp.clear();
            ui->SecureNumber->setText("You have been authorized");
            ui->verifyButton->setDisabled(true);
        }
        else
        {
            temp.clear();
            ui->SecureNumber->setText("Not authorized!");
            ui->verifyButton->setDisabled(true);
            QMessageBox::information(this, "Rejected", "Security Code is incorrect!");
        }
    }

}

