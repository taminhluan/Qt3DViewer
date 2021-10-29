#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    { // show openGLWidget
        QSurfaceFormat format;
        format.setDepthBufferSize(24);
        format.setStencilBufferSize(8);
        format.setVersion(3, 3);
        format.setProfile(QSurfaceFormat::CoreProfile);

        // set format
        openGLWidget.show();
        openGLWidget.activateWindow();
    }
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


void MainWindow::on_lineEditBackgroundColor_editingFinished()
{

    QString backgroundColor = this->ui->lineEditBackgroundColor->text();
    qInfo() << "Background Color: " << backgroundColor;


    float red = 0.2;
    float green = 0.3;
    float blue = 0.3;
    {
        // from hex to rgb
        QColor *color = new QColor(backgroundColor);
        red = color->redF();
        green = color->greenF();
        blue = color->blueF();

        qInfo() << "Update color: " << color->red() << color->green() << color->blue();

    }

    this->openGLWidget.setBackgroundColor(red, green, blue);
    this->openGLWidget.activateWindow();
}

