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
    this->background_color_red = red;
    this->background_color_green = green;
    this->background_color_blue = blue;
}

void OpenGLWidget::initializeGL() {
    this->f = new QOpenGLFunctions_3_3_Core();
    f->initializeOpenGLFunctions();

    // shader
    const char *vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "uniform mat4 MVP;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
    const char *fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0";

    this->m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();

    MatrixID = f->glGetUniformLocation(m_program->programId(), "MVP");

    camera = new PerspectiveCamera(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    MVP = camera->getProjectionMatrix() * Model; // Remember, matrix multiplication is the other way around

    // vertices
    float vertices[] = {
          -0.5f, -0.5f, 0.0f, // left
           0.5f, -0.5f, 0.0f, // right
           0.0f,  0.5f, 0.0f  // top
    };


    // vao, vbo
    f->glGenVertexArrays(1, &VAO);
    f->glGenBuffers(1, &VBO);

    f->glBindVertexArray(VAO);
    f->glBindBuffer(GL_ARRAY_BUFFER, VBO);
    f->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);

    f->glEnableVertexAttribArray(0);
    f->glBindBuffer(GL_ARRAY_BUFFER, 0);

    f->glClearColor(0.2, 0.3, 0.3, 1.0);
}

void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {
    qInfo() << "paintGL update";

    f->glClearColor(this->background_color_red, this->background_color_green, this->background_color_blue, 1.0f);
    f->glClear(GL_COLOR_BUFFER_BIT);

    {
        this->m_program->bind();

        f->glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &camera->getProjectionMatrix()[0][0]);

        f->glBindVertexArray(VAO);
        f->glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}
