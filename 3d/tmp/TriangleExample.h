#ifndef TRIANGLEEXAMPLE_H
#define TRIANGLEEXAMPLE_H

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include "PerspectiveCamera.h"

class TriangleExample {
private:
    unsigned int VBO, VAO;

    GLuint MatrixID;
    QOpenGLShaderProgram *m_program = nullptr;
    QOpenGLFunctions_3_3_Core *f = nullptr;
    PerspectiveCamera *camera = nullptr;

public:
    bool is_need_setup = true;
    TriangleExample(QOpenGLFunctions_3_3_Core *f, PerspectiveCamera *camera);

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

#endif // TRIANGLEEXAMPLE_H
