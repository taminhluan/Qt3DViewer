#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include "PerspectiveCamera.h"

class Drawable {
private:
//    unsigned int VBO, VAO;

//    GLuint MatrixID;
//    QOpenGLShaderProgram *m_program = nullptr;
//    QOpenGLFunctions_3_3_Core *f = nullptr;
//    PerspectiveCamera *camera = nullptr;

public:
    // bool is_need_setup = true;
    // Drawable(QOpenGLFunctions_3_3_Core *f, PerspectiveCamera *camera);

    /**
     * @brief setup()
     * usage: is called from openGL.initializeGL()
     *
     */
    virtual void setup() = 0;

    /**
     * @brief draw()
     * usage: is called from openGL.drawGL()
     */
    virtual void draw() = 0;
};


#endif // DRAWABLE_H
