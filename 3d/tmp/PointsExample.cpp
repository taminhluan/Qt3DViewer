#include "3d/tmp/PointsExample.h"

#include <string>

#include "3d/io/PCLTextReader.h"
#include "3d/io/BinReader.h"

PointsExample::PointsExample(QOpenGLFunctions_3_3_Core *f, PerspectiveCamera *camera) {
    this->f = f;
    this->camera = camera;
}

void PointsExample::setup() {
    // set flag already setup
    this->is_need_setup = false;

    f->glPointSize(1.0);

    // setup camera
    {
        camera->position.x = 676799.995003;
        camera->position.y = 246049.994999;
        camera->position.z = 700;

        camera->target.x = 676799.995003;
        camera->target.y = 246049.994999;
        camera->target.z = 540.065002;

        camera->m_far = 1000;

        camera->updateProjectionMatrix();
    }


    // setup openGL
    {
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
    }



    // SHOULD unfocus to paintGL update
//    PCLTextReader* textReader = new PCLTextReader(); // 15s to load text file, 15s
//    textReader->open("C:\\Users\\luantm\\Downloads\\zurich.pts");

    BinReader* reader = new BinReader(); // <1s
//    reader->open("C:\\Users\\luantm\\Downloads\\zurich.bin");
    reader->open(path);

    qDebug() << "Opened text file";
    while(true) {
        unsigned int buck_size = 1000;
        unsigned int return_number_of_points = 0;
        float* points = reader->next(buck_size, return_number_of_points);
        qDebug() << points[0];
        qDebug() << points[1];
        qDebug() << points[2];

        if (points == nullptr || return_number_of_points == 0) { break; }

        // vao, vbo
        unsigned int VAO, VBO;
        f->glGenVertexArrays(1, &VAO);
        f->glGenBuffers(1, &VBO);

        f->glBindVertexArray(VAO);
        f->glBindBuffer(GL_ARRAY_BUFFER, VBO);
        f->glBufferData(GL_ARRAY_BUFFER, 3 * buck_size * sizeof(float), points, GL_STATIC_DRAW);
        f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);

        f->glEnableVertexAttribArray(0);
        f->glBindBuffer(GL_ARRAY_BUFFER, 0);

        VAOs.push_back(VAO);
    }

    qDebug() << "Closed text file";
    reader->close();
}

void PointsExample::draw() {
    // check setup
    if (this->is_need_setup) {
        this->setup();
    }

    // draw
    this->m_program->bind();
    f->glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &camera->getProjectionMatrix()[0][0]);

    for (int i = 0; i < VAOs.size(); i++) {
        f->glBindVertexArray(VAOs.at(i));
        f->glDrawArrays(GL_POINTS, 0, 1000);
    }

}
