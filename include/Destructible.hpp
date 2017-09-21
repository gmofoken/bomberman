#ifndef _DESTRUCTIBLE_HPP
#define _DESTRUCTIBLE_HPP

#define STATIC_WALLS 64

#include "Bomberman.hpp"
#include "Player.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Destructible
{
public:
    Destructible();
    ~Destructible();
    
    void init();
    void test();
    void draw();
    
private:
    GLuint VertexArrayID, destructibleTexture;
    GLuint programID, VAOs[STATIC_WALLS], VBOs[STATIC_WALLS], EBOs[STATIC_WALLS], vao, vbo;

};

#endif
