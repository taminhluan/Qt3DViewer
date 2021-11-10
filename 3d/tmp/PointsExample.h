#ifndef POINTSEXAMPLE_H
#define POINTSEXAMPLE_H

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include "PerspectiveCamera.h"
#include <vector>

class PointsExample {
private:
    std::vector<unsigned int> VAOs;

    GLuint MatrixID;
    QOpenGLShaderProgram *m_program = nullptr;
    QOpenGLFunctions_3_3_Core *f = nullptr;
    PerspectiveCamera *camera = nullptr;

public:
    bool is_need_setup = true;

    PointsExample(QOpenGLFunctions_3_3_Core *f, PerspectiveCamera *camera);

    /**
     * @brief setup()
     * usage: is called from openGL.initializeGL()
     *
     */
    void setup();

    /**
     * @brief draw()
     * usage: is called from openGL.drawGL()
     */
    void draw();
};

#endif // POINTSEXAMPLE_H
