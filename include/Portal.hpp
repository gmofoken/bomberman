#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "Bomberman.hpp"

class Portal{
public:
    Portal();
    ~Portal();
    
    void init();
    void draw();

private:
    GLuint vao, vbo, portalTexture;

};
#endif
