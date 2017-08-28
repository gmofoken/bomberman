/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditshwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:28:53 by tditshwe          #+#    #+#             */
/*   Updated: 2017/08/14 15:29:07 by tditshwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wall.hpp"

Wall::Wall()
{
	glDeleteBuffers(1, &vertexbuffer);
}

Wall::Wall(int x, int y, bool isDec)
{
	xPos = x;
	yPos = y;
	isDestructable = isDec;
}

Wall::~Wall()
{
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Wall::init()
{
	static const GLfloat g_vertex_buffer_data[] = {
		//vertex data			//texture coordinates 
		-1.0f, 0.9f, 0.0f,		0.0f, 0.0f,
		1.0f, 0.9f, 0.0f,		20.0f, 0.0f,
		1.0f,  1.0f, 0.0f,		20.0f, 1.0f,
		-1.0f, 1.0f, 0.0f,		0.0f, 1.0f,

		0.9f, -1.0f, 0.0f,		0.0f, 1.0f,
		1.0f,  -1.0f, 0.0f,		0.0f, 0.0f,
		0.9f, 0.9f, 0.0f,		20.0f, 1.0f,

		-1.0f, -1.0f, 0.0f,		20.0f, 1.0f,
		0.9f, -0.9f, 0.0f,		0.0f, 0.0f,
		-1.0f, -0.9f, 0.0f,		20.0f, 0.0f,

		-0.9f, -0.9f, 0.0f,		20.0f, 1.0f,
		-0.9f, 0.9f, 0.0f,		0.0f, 1.0f
	};

	GLuint elements[] = {
		0, 1, 2,
		0, 3, 2,
		4, 5, 6,
		5, 1, 6,
		7, 4, 8,
		7, 9, 8,
		9, 10, 11,
		9, 0, 11

	};

	GLuint elementBuffer;

	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glGenBuffers(1, &vertexbuffer);
	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		5 * sizeof(GL_FLOAT),                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Texture texture("next.JPEG", &wallTexture);
}

void Wall::draw()
{
	glBindTexture(GL_TEXTURE_2D, wallTexture);
	glBindVertexArray(VertexArrayID);
	// Draw the triangle !
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0); // 3 indices starting at 0 -> 1 triangle
}
