#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFile>
#include <QFileInfoList>
#include <QDir>
#include "photoviewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void loadAlbum();
    void scan(QFileInfoList fileInfoList);
    void buildImage(QString imageAbsolutePath);
    void loadImageViewer(QString imageAbsolutePath);

private:
    Ui::Dialog *ui;

public slots:
    void photoDoubleClicked(QListWidgetItem* item);
};
#endif // DIALOG_H
