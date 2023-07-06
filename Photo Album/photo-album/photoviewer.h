#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QDialog>

namespace Ui {
class PhotoViewer;
}

class PhotoViewer : public QDialog
{
    Q_OBJECT

public:
    explicit PhotoViewer(QWidget *parent = nullptr);
    ~PhotoViewer();

private:
    Ui::PhotoViewer *ui;
};

#endif // PHOTOVIEWER_H
