#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

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
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);

    QStringList filenames;
    if (dialog.exec()) {
        filenames = dialog.selectedFiles();
    }

    QMessageBox msgBox;
    msgBox.setText(filenames.at(0));
    msgBox.exec();
}


void MainWindow::on_actionQuit_triggered()
{
    QCoreApplication::quit();
}

