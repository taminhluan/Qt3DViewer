#include "3d/tmp/TriangleExample.h"

TriangleExample::TriangleExample(QOpenGLFunctions_3_3_Core *f, PerspectiveCamera *camera) {
    this->f = f;
    this->camera = camera;
}

void TriangleExample::setup() {
    // setup openGL
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

    this->m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();

    this->MatrixID = f->glGetUniformLocation(m_program->programId(), "MVP");

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

    // set flag already setup
    this->is_need_setup = false;
}

void TriangleExample::draw() {
    // check setup
    if (this->is_need_setup) {
        this->setup();
    }

    // draw
    this->m_program->bind();
    f->glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &camera->getProjectionMatrix()[0][0]);
    f->glBindVertexArray(VAO);
    f->glDrawArrays(GL_TRIANGLES, 0, 3);
}
