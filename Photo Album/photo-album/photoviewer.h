#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QDialog>
#include <QFileInfo>

namespace Ui {
class PhotoViewer;
}

class PhotoViewer : public QDialog
{
    Q_OBJECT

public:
    explicit PhotoViewer(QWidget *parent = nullptr);
    ~PhotoViewer();

    void setImage(QString imageAbsolutePath);


private:
    Ui::PhotoViewer *ui;
    QString imageAbsolutePath;
    QString getType(QString imageAbsolutePath);
};

#endif // PHOTOVIEWER_H
