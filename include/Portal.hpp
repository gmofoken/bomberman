#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "Texture.hpp"
#include "shader.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Portal{
public:
    Portal();
    ~Portal();
    void init();
    void transform();
	void draw();


private:
    GLfloat xPos, yPos;
	GLuint programID, pVAO, pVBO, pEBO, pTextureId;

protected:

};
#endif