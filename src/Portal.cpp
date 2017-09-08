#include "Portal.hpp"

Portal::Portal(){
    xPos = 0.0f;
	yPos = 0.0f;
}

Portal::~Portal()
{
	glDeleteBuffers(1, &pVAO);
	glDeleteBuffers(1, &pVBO);
	glDeleteBuffers(1, &pEBO);
	glDeleteProgram(programID);
}

void Portal::init()
{
	programID = LoadShaders("TransformationFragmentShader.hlsl", "TextureFragmentShader.hlsl");

	GLfloat vertices[] = {

        //co-ordinates
		-0.89f, 0.81f, 0.0f,    0.0f, 0.0f, //Bottom left
		-0.81, 0.81f, 0.0f,     1.0f, 0.0f, //Bottom right
		-0.89f, 0.89f, 0.0f,    0.0f, 1.0f, //Top left
		-0.81, 0.89f, 0.0f,     1.0f, 1.0f, //Top right
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

	Texture pTexture("doorz.jpeg", &pTextureId);
}

void Portal::transform()
{
	// create transformations
	glm::mat4 transform;
	transform = glm::translate(transform, glm::vec3(xPos, yPos, 0.0f));
	//transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	// get matrix's uniform location and set matrix
	glUseProgram(programID);
	unsigned int transformLoc = glGetUniformLocation(programID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
}

void Portal::draw()
{
	//draw portal
	glBindTexture(GL_TEXTURE_2D, pTextureId);
	glBindVertexArray(pVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}