#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &Dialog::photoDoubleClicked);

    loadAlbum();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadAlbum()
{
    QListWidget* listWidget = ui->listWidget;

    QDir dir("D:/Media/Icons");
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

    QFileInfoList dirInfo = dir.entryInfoList();

    listWidget->setIconSize(QSize(192,108));
    listWidget->setViewMode(QListView::IconMode);

    scan(dirInfo);
}

void Dialog::scan(QFileInfoList fileInfoList)
{
    foreach (QFileInfo root, fileInfoList)
    {
        if(root.isDir())
        {
            QDir dir(root.absoluteFilePath());
            dir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
            return scan(dir.entryInfoList());
        }
        else
            buildImage(root.absoluteFilePath());
    }

}

void Dialog::buildImage(QString imageAbsolutePath)
{
    QListWidgetItem* item = new QListWidgetItem();
    QIcon icon(imageAbsolutePath);
    item->setIcon(icon);
    item->setData(Qt::UserRole, imageAbsolutePath);
    ui->listWidget->addItem(item);
}

void Dialog::photoDoubleClicked(QListWidgetItem* item)
{
    QString imagePath = item->data(Qt::UserRole).toString();

    loadImageViewer(imagePath);
}

void Dialog::loadImageViewer(QString imagePath)
{
    //    I had to create it as a pointer... why ? well beacus qt does automatic memory managment and deletes everything
    // after getting out of its parent's scope... so i created a pointer that it won't get deconstructed!
    PhotoViewer* imageViewer = new PhotoViewer(this);

    imageViewer->setImage(imagePath);
    imageViewer->show();
}
