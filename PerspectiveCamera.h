#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <QObject>
#include <QDebug>

class PerspectiveCamera: public QObject {
    Q_OBJECT
public:
    PerspectiveCamera(float fov, float aspect, float near, float far);

    glm::vec3 position = glm::vec3(4, 3, 3); // Camera is at (4,3,3), in World Space
    glm::vec3 target = glm::vec3(0, 0, 0); // and looks at the origin
    glm::vec3 head_up = glm::vec3(0, 1, 0);

    float m_fov;
    float m_aspect;
    float m_near;
    float m_far;

    glm::mat4 getProjectionMatrix();

    void updateProjectionMatrix();

signals:
    void projectionMatrix_changed();

private:
    glm::mat4 projectionMatrix;
};

#endif // PERSPECTIVECAMERA_H
