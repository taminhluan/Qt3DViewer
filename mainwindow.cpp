#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Hello world");
    msgBox.exec();
}


void MainWindow::on_actionQuit_triggered()
{
    QCoreApplication::quit(); // we can press Ctrl+Q also
}

