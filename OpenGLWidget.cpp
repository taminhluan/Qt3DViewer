#include "OpenGLWidget.h"
#include <QDebug>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <PerspectiveCamera.h>

// constructor
OpenGLWidget::OpenGLWidget(QWidget *parent): QOpenGLWidget(parent) {
}

void OpenGLWidget::setBackgroundColor(float red, float green, float blue) {
    if (red != this->background_color_red
            || green != this->background_color_green
            || blue != this->background_color_blue) {
        this->background_color_red = red;
        this->background_color_green = green;
        this->background_color_blue = blue;

        qDebug() << "OpenGLWidget::setBackgroundColor";
        emit backgroundChanged();
    }
}

void OpenGLWidget::initializeGL() {
    this->f = new QOpenGLFunctions_3_3_Core();
    f->initializeOpenGLFunctions();

    { // init camera
        camera = new PerspectiveCamera(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        connect(camera, &PerspectiveCamera::projectionMatrix_changed,
                         this, &OpenGLWidget::onCameraChanged);

        // Model matrix : an identity matrix (model will be at the origin)
        glm::mat4 Model = glm::mat4(1.0f);
        camera->updateProjectionMatrix();

        // Our ModelViewProjection : multiplication of our 3 matrices
        MVP = camera->getProjectionMatrix() * Model; // Remember, matrix multiplication is the other way around


    }

    this->triangleExample = new TriangleExample(f, camera);
//    this->triangleExample->setup();

    this->pointsExample = new PointsExample(f, camera);
//    this->pointsExample->setup();
    this->cubeExample = new CubeExample(f);
}

void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {
    qInfo() << "paintGL update";

    f->glClearColor(this->background_color_red, this->background_color_green, this->background_color_blue, 1.0f);
    f->glClear(GL_COLOR_BUFFER_BIT);

//    this->triangleExample->draw();
    this->pointsExample->draw();
}

void OpenGLWidget::onCameraChanged() {
    qDebug() << "OpenGLWidget::onCameraChanged";
    this->update();
    emit cameraChanged();
}

