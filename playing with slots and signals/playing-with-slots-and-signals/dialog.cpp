
#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->CustomBtn, &QPushButton::clicked, this, &Dialog::customSlot);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::customSlot()
{
    QMessageBox::information(this, "Custom Slot", "You have clicked on the custom button");
}



void Dialog::on_Editor_clicked()
{
    QMessageBox::information(this, "Test Button", "You have clicked on " + ui->Editor->text());
    //accept();     Just beacus i dont want the app to close after clicking on the button.
}

