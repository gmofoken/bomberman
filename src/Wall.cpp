/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wall.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditshwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:28:53 by tditshwe          #+#    #+#             */
/*   Updated: 2017/09/11 14:48:42 by rmoswela         ###   ########.fr       */
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

	Texture texture("brick2.jpg", &wallTexture);
    
    static const GLfloat vertexData[] = {
        //wall up
        //bottom
        -1.0f, 0.9f, -0.05f,	0.0f, 0.0f,
        1.0f,  0.9f,  -0.05f,	20.0f, 0.0f,
        1.0f,  1.0f, -0.05f,	20.0f, 1.0f,
        -1.0f, 1.0f, -0.05f,	0.0f, 1.0f,
        
        //top
        -1.0f, 0.9f, 0.05f,     0.0f, 0.0f,
        1.0f,  0.9f,  0.05f,	20.0f, 0.0f,
        1.0f,  1.0f, 0.05f,     20.0f, 1.0f,
        -1.0f, 1.0f, 0.05f,     0.0f, 1.0f,
        
        
        //wall right
        //bottom
        0.9f,  0.9f, -0.05f,		16.0f, 1.0f,
        0.9f, -0.9f, -0.05f,		0.0f, 1.0f,
        1.0f, -0.9f, -0.05f,		0.0f, 0.0f,
        
        //top
        0.9f,  0.9f, 0.05f,		16.0f, 1.0f,
        0.9f, -0.9f, 0.05f,		0.0f, 1.0f,
        1.0f,  0.9f, 0.05f,     16.0f, 0.0f,
        1.0f, -0.9f, 0.05f,     0.0f, 0.0f,
        
        //wall left
        //bottom
        -1.0f, 0.9f, -0.05f,		16.0f, 1.0f,
        -1.0f, -0.9f, -0.05f,		0.0f, 1.0f,
        -0.9f, 0.9f, -0.05f,		16.0f, 0.0f,
        -0.9f, -0.9f, -0.05f,		0.0f, 0.0f,
        
        //top
        -1.0f, 0.9f, 0.05f,		16.0f, 1.0f,
        -1.0f, -0.9f, 0.05f,		0.0f, 1.0f,
        -0.9f, 0.9f, 0.05f,		16.0f, 0.0f,
        -0.9f, -0.9f, 0.05f,		0.0f, 0.0f,
        
        //wall down
        //bottom
        -1.0f, -1.0f, -0.05f,		0.0f, 0.0f,
        1.0f, -1.0f, -0.05f,		16.0f, 0.0f,
        1.0f, -0.9f, -0.05f,		16.0f, 1.0f,
        -1.0f, -0.9f, -0.05f,		0.0f, 1.0f,
        
        //top
        -1.0f, -1.0f, 0.05f,		0.0f, 0.0f,
        1.0f, -1.0f, 0.05f,		16.0f, 0.0f,
        1.0f, -0.9f, 0.05f,		16.0f, 1.0f,
        -1.0f, -0.9f, 0.05f,		0.0f, 1.0f,
    };
    
    GLuint elements[] = {
        //wall up
        0, 1, 2,
        0, 3, 2,
        4, 5, 6,
        4, 7, 6,
        0, 1, 5,
        0, 4, 5,
        
        //wall right
        8, 9, 1,
        1, 10, 9,
        11, 12, 13,
        13, 14, 12,
        8, 11, 9,
        9, 12, 11,
        
        //wall left
        15, 16, 17,
        17, 18, 16,
        19, 20, 21,
        21, 22, 20,
        17, 21, 18,
        18, 22, 21,
        
        //wall down
        23, 24, 25,
        25, 26, 23,
        27, 28, 29,
        29, 30, 27,
        23, 27, 24,
        24, 28, 27
        
        
    };
    
    glGenVertexArrays(1, &VertexArrayID);
    
    glGenBuffers(1, &vertexbuffer);
    glGenBuffers(1, &elementBuffer);
    
    glBindVertexArray(VertexArrayID);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
    
    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
}

void Wall::draw()
{
	glBindTexture(GL_TEXTURE_2D, wallTexture);
	glBindVertexArray(VertexArrayID);
	// Draw the triangle !
	glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_INT, 0); // 3 indices starting at 0 -> 1 triangle
}
