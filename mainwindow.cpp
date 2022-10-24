#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

#include <QDebug>

#include <app/OpenFileUsecase.h>
#include "3d/io/BinWriter.h"
#include "3d/io/BinReader.h"
#include <iostream>

#include "3d/tool/Converter.h"
#include "converterdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // show full screen
    this->showMaximized();

    { // show openGLWidget
        QSurfaceFormat format;
        format.setDepthBufferSize(24);
        format.setStencilBufferSize(8);
        format.setVersion(3, 3);
        format.setProfile(QSurfaceFormat::CoreProfile);

        // set format
        openGLWidget = new OpenGLWidget();
        openGLWidget->show();
        openGLWidget->activateWindow();
    }

    // we need QWidget*
    setCentralWidget(openGLWidget);

    { // test io/bin read/write
//        BinWriter binWriter;
//        binWriter.open("abc.bin");
//        binWriter.write(NULL, 0);
//        binWriter.close();
//        qDebug() << "Write to a file abc.bin";
//        qDebug() << "Reading file abc.bin";

//        BinReader binReader;
//        binReader.open("abc.bin");
//        binReader.next(0);
//        binReader.close();
    }

    { // test converter
          // Converter converter;
          // converter.convert("", "");
    }

    { // test bin reader
//        BinReader binReader;
//        binReader.open("C:\\Users\\luantm\\Downloads\\zurich.bin");
//        int returnNPoints;
//        float *first1000Points = binReader.next(1000, returnNPoints);
//        qDebug() << first1000Points[0];
//        qDebug() << first1000Points[1];
//        qDebug() << first1000Points[2];

//        qDebug() << "-----------------";
//        qDebug() << first1000Points[0];
//        qDebug() << first1000Points[1];
//        qDebug() << first1000Points[2];
    }

    { // test plain text
        ui->txtProperties->setPlainText("Everything is working fine\nNew line also work");

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

    qDebug() << "Open file " << filenames.at(0);

    OpenFileUsecase openFileUsecase;

    openFileUsecase.run(filenames.at(0).toStdString(), true, true, true, true, true);
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

    this->openGLWidget->setBackgroundColor(red, green, blue);

    // change background didn't work
    // we need call update function()
    this->openGLWidget->update();
}

void MainWindow::on_CameraChanged() {
    qDebug() << "on Camera Changed";

    // update UI information
    ui->lineEditCameraPositionX->setText( QString::number(openGLWidget->camera->position.x) );
    ui->lineEditCameraPositionY->setText( QString::number(openGLWidget->camera->position.y) );
    ui->lineEditCameraPositionZ->setText( QString::number(openGLWidget->camera->position.z) );

    ui->lineEditCameraTargetX->setText( QString::number(openGLWidget->camera->target.x) );
    ui->lineEditCameraTargetY->setText( QString::number(openGLWidget->camera->target.y) );
    ui->lineEditCameraTargetZ->setText( QString::number(openGLWidget->camera->target.z) );

    ui->lineEditCameraFOV->setText( QString::number(openGLWidget->camera->m_fov) );
    ui->lineEditCameraNear->setText( QString::number(openGLWidget->camera->m_near) );
    ui->lineEditCameraFar->setText( QString::number(openGLWidget->camera->m_far) );
}

void MainWindow::onBackgroundChanged() {
    QColor *color = new QColor(openGLWidget->background_color_red * 255,
           openGLWidget->background_color_green * 255,
           openGLWidget->background_color_blue * 255);


    ui->lineEditBackgroundColor->setText( color->name(color->HexRgb) );
}

void MainWindow::on_pushButtonUpdateCamera_clicked()
{
    qDebug() << "Update projection matrix";

    float cameraPositionX = ui->lineEditCameraPositionX->text().toFloat();
    float cameraPositionY = ui->lineEditCameraPositionY->text().toFloat();
    float cameraPositionZ = ui->lineEditCameraPositionZ->text().toFloat();

    float cameraTargetX = ui->lineEditCameraTargetX->text().toFloat();
    float cameraTargetY = ui->lineEditCameraTargetY->text().toFloat();
    float cameraTargetZ = ui->lineEditCameraTargetZ->text().toFloat();

    float cameraFOV = ui->lineEditCameraFOV->text().toFloat();
    float cameraNear= ui->lineEditCameraNear->text().toFloat();
    float cameraFar = ui->lineEditCameraFar->text().toFloat();

    openGLWidget->camera->position.x = cameraPositionX;
    openGLWidget->camera->position.y = cameraPositionY;
    openGLWidget->camera->position.z = cameraPositionZ;

    openGLWidget->camera->target.x = cameraTargetX;
    openGLWidget->camera->target.y = cameraTargetY;
    openGLWidget->camera->target.z = cameraTargetZ;

    openGLWidget->camera->m_fov = cameraFOV;
    openGLWidget->camera->m_near = cameraNear;
    openGLWidget->camera->m_far = cameraFar;

    openGLWidget->camera->updateProjectionMatrix();
}



// EXAMPLEs
void MainWindow::on_btnTriangleExample_clicked()
{
    ui->statusbar->showMessage("Open triangle example");
    openGLWidget->setupAndRunTriangleExample();
}


void MainWindow::on_btnPointExample_clicked()
{
    ui->statusbar->showMessage("Open points example");
    openGLWidget->setupAndRunPointsExample();
}


void MainWindow::on_btnCubeExample_clicked()
{
    ui->statusbar->showMessage("Open cube example");
    openGLWidget->setupAndRunCubeExample();
}

void MainWindow::on_btnSamplePointExample_clicked()
{
    ui->statusbar->showMessage("Open sample points example");
    openGLWidget->setupAndRunSamplePointsExample();
}
// end EXAMPLEs

void MainWindow::on_actionConverter_triggered()
{
    ConverterDialog dialog;
    dialog.exec();
}




