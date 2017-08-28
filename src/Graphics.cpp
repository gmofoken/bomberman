/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditshwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:43:54 by tditshwe          #+#    #+#             */
/*   Updated: 2017/08/16 14:43:57 by tditshwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.hpp"
#include <stdio.h>

Graphics::Graphics()
{
	drawMode = MAINMENU;
}

Graphics::~Graphics() { }

void Graphics::initGlArrays()
{
	GLfloat vertices[STATIC_WALLS][20];
    GLfloat xLeft = -0.8f;
    GLfloat xRight = -0.7f;
    GLfloat fUnit = 0.2;
    
    unsigned int indices[] = {
        0, 1, 2,
        1, 2, 3
    };
    
    int k = 0;
    for (int j = 0; j < 8; j++)
    {
        
        for (int i = 0; i < 8; i++)
        {
            //Bottom left
            vertices[k][0] = xLeft + i * fUnit;
            vertices[k][1] = 0.7f - j * fUnit;
            vertices[k][2] = 0.0f;
            //texture coordinates
            vertices[k][3] = 0.0f;
            vertices[k][4] = 0.0f;
            //Bottom right
            vertices[k][5] = xRight + i * fUnit;
            vertices[k][6] = 0.7f - j * fUnit;
            vertices[k][7] = 0.0f;
            //texture coordinates
            vertices[k][8] = 1.0f;
            vertices[k][9] = 0.0f;
            //Top left
            vertices[k][10] = xLeft + i * fUnit;
            vertices[k][11] = 0.8f - j * fUnit;
            vertices[k][12] = 0.0f;
            //texture coordinates
            vertices[k][13] = 0.0f;
            vertices[k][14] = 1.0f;
            //Top right
            vertices[k][15] = xRight + i * fUnit;
            vertices[k][16] = 0.8f - j * fUnit;
            vertices[k][17] = 0.0f;
            //texture coordinates
            vertices[k][18] = 1.0f;
            vertices[k][19] = 1.0f;
            
            glGenVertexArrays(1, &VAOs[k]);
            glGenBuffers(1, &EBOs[k]);
            glGenBuffers(1, &VBOs[k]);
            glBindVertexArray(VAOs[k]);
            glBindBuffer(GL_ARRAY_BUFFER, VBOs[k]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[k]), vertices[k], GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[k]);
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
            k++;
        }
    }
}

void Graphics::drawElements()
{
   //trin logic
   for (int i = 0; i < STATIC_WALLS; i++)
   {
       glBindVertexArray(VAOs[i]);
       glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // 3 indices starting at 0 -> 1 triangle
   }
}

void Graphics::setDrawMode(GameMode mode)
{
	drawMode = mode;
}

GameMode Graphics::getDrawMode()
{
	return drawMode;
}
