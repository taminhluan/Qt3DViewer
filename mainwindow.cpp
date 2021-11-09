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

