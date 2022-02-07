#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <vector>

class Object3D {
public:
    std::vector<Object3D> children;
    bool visible;
};

#endif // OBJECT3D_H
