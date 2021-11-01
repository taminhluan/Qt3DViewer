#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>
#include <glm/glm.hpp>
#include "PerspectiveCamera.h"
/**
 * @brief The OpenGLWidget class extend from QOpenGLWidget
 */
class OpenGLWidget: public QOpenGLWidget {
private:
    unsigned int VBO, VAO;
    std::vector<unsigned int> VAOs;

    QOpenGLShaderProgram *m_program = nullptr;
    QOpenGLFunctions_3_3_Core *f = nullptr;

    QOpenGLShaderProgram *m_program2 = nullptr;

    // background color
    float background_color_red = 0.2;
    float background_color_green = 0.3;
    float background_color_blue = 0.3;

    GLuint MatrixID;
    glm::mat4 MVP;
    PerspectiveCamera *camera;
public:
    OpenGLWidget(QWidget *parent = nullptr);

    void setBackgroundColor(float red, float green, float blue);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // OPENGLWIDGET_H
