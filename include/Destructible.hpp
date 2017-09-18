#ifndef _DESTRUCTIBLE_HPP
#define _DESTRUCTIBLE_HPP

#define STATIC_WALLS 64

#include "Player.hpp"

class Destructible
{
public:
    Destructible();
    ~Destructible();
    
    void init();
    void draw();
    
private:
    GLuint VertexArrayID, destructibleTexture;
    GLuint programID, VAOs[STATIC_WALLS], VBOs[STATIC_WALLS], EBOs[STATIC_WALLS];

};

#endif
