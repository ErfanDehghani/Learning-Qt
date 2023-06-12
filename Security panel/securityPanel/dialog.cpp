
#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

//    for (int i = 0; i < ui->gridLayout->count(); ++i) {
//        QPushButton *button = qobject_cast<QPushButton*>(ui->gridLayout->itemAt(i)->widget());
//        if (button) {
//            button->setStyleSheet("QPushButton { max-width:64px; height:64px; }");
//        }
//    }
}

Dialog::~Dialog()
{
    delete ui;
}


