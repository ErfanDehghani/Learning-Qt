
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadStyleSheet("./stylesheet.qss", *ui->centralwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loadStyleSheet(const QString &filePath, QWidget widget)
{
    QFile styleFile(filePath);
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    widget.setStyleSheet(styleSheet);
    return true;
}
