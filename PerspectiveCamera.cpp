#include "PerspectiveCamera.h"

/**
 * @brief PerspectiveCamera::PerspectiveCamera
 * @param fov in degree
 * @param aspect
 * @param near
 * @param far
 */
PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float near, float far) {
    this->m_fov = fov;
    this->m_aspect = aspect;
    this->m_near = near;
    this->m_far = far;
    this->updateProjectionMatrix();
}

glm::mat4 PerspectiveCamera::getProjectionMatrix() {
    return this->projectionMatrix;
}


void PerspectiveCamera::updateProjectionMatrix() {
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(glm::radians(m_fov), m_aspect, m_near, m_far);

    // Camera matrix
    glm::mat4 View = glm::lookAt(
        position, // Camera is at (4,3,3), in World Space
        target, // and looks at the origin
        head_up  // Head is up (set to 0,-1,0 to look upside-down)
    );
    this->projectionMatrix = Projection * View;
    qDebug() << "PerspectiveCamera::updateProjectionMatrix";

    emit projectionMatrix_changed();
}

