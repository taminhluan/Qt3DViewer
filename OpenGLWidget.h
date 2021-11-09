#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>
#include <glm/glm.hpp>
#include "PerspectiveCamera.h"

#include "3d/tmp/TriangleExample.h"
#include "3d/tmp/PointsExample.h"
#include "3d/tmp/CubeExample.h"

/**
 * @brief The OpenGLWidget class extend from QOpenGLWidget
 */
class OpenGLWidget: public QOpenGLWidget {
    Q_OBJECT

private:
    QOpenGLShaderProgram *m_program2 = nullptr;
    glm::mat4 MVP;

    QOpenGLFunctions_3_3_Core *f;

    TriangleExample* triangleExample;
    PointsExample* pointsExample;
    CubeExample* cubeExample;

public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    void setBackgroundColor(float red, float green, float blue);

    // background color
    float background_color_red = 0;
    float background_color_green = 0;
    float background_color_blue = 0;

    PerspectiveCamera *camera;

public slots:
    void onCameraChanged();
signals:
    void cameraChanged();
    void backgroundChanged();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // OPENGLWIDGET_H
