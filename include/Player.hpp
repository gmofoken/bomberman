#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "Texture.hpp"
#include "shader.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Player
{
public:
	Player();
	~Player();
	void init();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void transform();
	void draw();

private:
	GLfloat xPos, yPos;
	GLuint programID, pVAO, pVBO, pEBO, pTextureId;
};

#endif
