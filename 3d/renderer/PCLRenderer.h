#ifndef PCLRENDERER_H
#define PCLRENDERER_H
#include <3d/renderer/Renderer.h>

class PCLRenderer: public Renderer {
public:
    PCLRenderer();
    void setup() override;
    void draw() override;
};

#endif // PCLRENDERER_H
