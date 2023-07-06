#include "photoviewer.h"
#include "ui_photoviewer.h"
#include <QtSvgWidgets/QSvgWidget>

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

void PhotoViewer::setImage(QString imageAbsolutePath)
{
    QPixmap image(imageAbsolutePath);
    ui->photoViewerLabel->setPixmap(image);
    ui->photoViewerLabel->setAlignment(Qt::AlignCenter);
}

QString PhotoViewer::getType(QString imageAbsolutePath)
{
    QFileInfo fileInfo(imageAbsolutePath);
    QString fileType = fileInfo.suffix();
    return fileType;
}
