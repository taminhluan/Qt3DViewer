#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "OpenGLWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    OpenGLWidget *openGLWidget;

public slots:
    void on_CameraChanged();
    void onBackgroundChanged();

private slots:
    void on_actionOpen_triggered();

    void on_actionQuit_triggered();

    void on_lineEditBackgroundColor_editingFinished();

    void on_pushButtonUpdateCamera_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
