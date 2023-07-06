#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFile>
#include <QFileInfoList>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void loadImages();
    void scan(QFileInfoList fileInfoList);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
