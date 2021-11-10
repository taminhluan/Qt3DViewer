#ifndef CUBEEXAMPLE_H
#define CUBEEXAMPLE_H

#include <QOpenGLFunctions_3_3_Core>

class CubeExample {
public:
    bool is_need_setup = false;
    QOpenGLFunctions_3_3_Core *f;

    CubeExample(QOpenGLFunctions_3_3_Core *f);

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

#endif // CUBEEXAMPLE_H
