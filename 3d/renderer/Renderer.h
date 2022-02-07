#ifndef RENDERER_H
#define RENDERER_H


class Renderer {
public:

    virtual ~Renderer() = default;
    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    virtual void setup() = 0;
    virtual void draw() = 0;
protected:
    Renderer() = default; // prevent accidental creation
};


#endif // RENDERER_H
