#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "Bomberman.hpp"
#include "camera.hpp"
#include "loader.hpp"


class Player
{
public:
	Bomb *bomb;
	Player();
	~Player();
	void init();
	void moveUp(); 
	void moveDown();
	void moveLeft();
	void moveRight();
	void transform();
	void player_callback(GLFWwindow* window);
	void draw();
	GLfloat xPos, yPos;

private:
	
	GLuint texture_programID, pUVO, pVAO, pVBO, pEBO, pTextureId;
	glm::mat4 _view;
    glm::mat4 _model;
    glm::mat4 _projection;
	unsigned int _modelLoc;
	unsigned int _vmodelLoc;
	std::vector<glm::vec3> _vertices;
	std::vector<glm::vec2> _uvbuffer;
	std::vector<glm::vec3> normals;
	int x;
	int y;
};

#endif
