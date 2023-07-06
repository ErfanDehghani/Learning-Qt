#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    loadImages();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadImages()
{
    QListWidget* listWidget = ui->listWidget;

    QDir dir("/home/Erfan/Pictures");
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

    QFileInfoList dirInfo = dir.entryInfoList();

    listWidget->setIconSize(QSize(192,108));
    listWidget->setViewMode(QListView::IconMode);

    scan(dirInfo);
}

void Dialog::scan(QFileInfoList fileInfoList)
{
    QListWidget* listWidget = ui->listWidget;

    foreach (QFileInfo root, fileInfoList)
    {
        if(root.isDir())
        {
            QDir dir(root.absoluteFilePath());
            dir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
            scan(dir.entryInfoList());
        }
        else
        {
            QListWidgetItem* item = new QListWidgetItem();
            QIcon icon(root.absoluteFilePath());
            item->setIcon(icon);
            listWidget->addItem(item);
        }
    }

}

