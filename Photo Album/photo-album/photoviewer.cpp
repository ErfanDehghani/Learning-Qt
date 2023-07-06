#include "photoviewer.h"
#include "ui_photoviewer.h"

PhotoViewer::PhotoViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhotoViewer)
{
    ui->setupUi(this);
}

PhotoViewer::~PhotoViewer()
{
    delete ui;
}
