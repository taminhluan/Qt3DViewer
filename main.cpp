#include "mainwindow.h"

#include <QApplication>

#include "Speacker.h"
#include "Listener.h"
#include "listenerimpl.h"
#include "OpenGLWidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Listener *listener = new Listener();
    ListenerImpl *listenerImpl = new ListenerImpl();
    Speacker *speacker = new Speacker();

    QObject::connect(speacker, &Speacker::speak, listener, &Listener::listen);
    QObject::connect(speacker, &Speacker::speak, listenerImpl, &ListenerImpl::listenImpl);
    QObject::connect(w.openGLWidget, &OpenGLWidget::cameraChanged, &w, &MainWindow::on_CameraChanged);
    QObject::connect(w.openGLWidget->camera, &PerspectiveCamera::projectionMatrix_changed, &w, &MainWindow::on_CameraChanged);
    QObject::connect(w.openGLWidget, &OpenGLWidget::backgroundChanged, &w, &MainWindow::onBackgroundChanged);

    w.openGLWidget->setBackgroundColor(0.2, 0.3, 0.3);
    return a.exec();
}
