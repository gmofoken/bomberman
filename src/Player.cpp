#include "Player.hpp"

Player::Player()
{
	xPos = -1.0f;
	yPos = 2.0f;
}

Player::~Player()
{
	glDeleteBuffers(1, &pVAO);
	glDeleteBuffers(1, &pVBO);
	glDeleteBuffers(1, &pEBO);
	glDeleteProgram(programID);
}

void Player::init()
{
	programID = LoadShaders("TransformationFragmentShader.hlsl", "TextureFragmentShader.hlsl");

	GLfloat vertices[] = {
		-0.89f, 0.81f, 0.05f,  0.0f, 0.0f, //Bottom left
		-0.81, 0.81f, 0.05f,  1.0f, 0.0f, //Bottom right
		-0.89f, 0.89f, 0.05f,  0.0f, 1.0f, //Top left
		-0.81, 0.89f, 0.05f,  1.0f, 1.0f, //Top right
	};

	unsigned int indices[] = {
		0, 1, 2,
		1, 2, 3
	};

	glGenVertexArrays(1, &pVAO);
	glGenBuffers(1, &pEBO);
	glGenBuffers(1, &pVBO);
	glBindVertexArray(pVAO);
	glBindBuffer(GL_ARRAY_BUFFER, pVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		5 * sizeof(float),                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Texture pTexture("cool.png", &pTextureId);

	/*glm::mat4 projection;
	projection = glm::perspective(glm::radians(30.0f), (float)1027 / (float)768, 0.1f, 100.0f);
	glUniformMatrix4fv(glGetUniformLocation(programID, "projection"), 1, GL_FALSE, &projection[0][0]);*/
}

void Player::moveUp()
{
	//std::cout << yPos << "f" << std::endl;
	if (yPos < 2.0f)
		yPos += 0.025f;
}

void Player::moveDown()
{	
	if (yPos > 0.375f)
		yPos -= 0.025f;
}

void Player::moveLeft()
{
	//std::cout << xPos << "f" << std::endl;
	if (xPos >= -1.275f)
		xPos -= 0.025f;
}
void Player::moveRight()
{
	if (xPos < 0.375f)
		xPos += 0.025f;
}

void Player::transform()
{
	// create transformations
	glm::mat4 transform;
	transform = glm::translate(transform, glm::vec3(xPos, yPos, -1.0f));
	float angle = 20.0f * 0;
	transform = glm::rotate(transform, glm::radians(-70.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	//glm::mat4 view;
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(10.0f), (float)1024 / (float)768, 0.1f, 100.0f);
	glUniformMatrix4fv(glGetUniformLocation(programID, "projection"), 1, GL_FALSE, &projection[0][0]);

	// get matrix's uniform location and set matrix
	glUseProgram(programID);
	unsigned int transformLoc = glGetUniformLocation(programID, "model");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
}

void Player::draw()
{
	glUseProgram(programID);
	//camera.cameraFunction(programID);
	//draw player
	glBindTexture(GL_TEXTURE_2D, pTextureId);
	glBindVertexArray(pVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

GLfloat Player::getYPos()
{
	return yPos;
}

GLfloat Player::getXPos()
{
	return xPos;
}

GLuint Player::getProgramId()
{
	return programID;
}
