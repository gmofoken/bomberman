/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticWall.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditshwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:28:53 by tditshwe          #+#    #+#             */
/*   Updated: 2017/09/11 16:27:00 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StaticWall.hpp"

StaticWall::StaticWall()
{
    //glDeleteBuffers(1, &VBO);
}

StaticWall::~StaticWall()
{
    /*glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);*/
}

void StaticWall::init()
{
    Texture texture("brick2.jpg", &wallTexture);
    
    GLfloat vertices[STATIC_WALLS][40];
    GLfloat xLeft = -0.8f;
    GLfloat xRight = -0.7f;
    GLfloat fUnit = 0.2;
    
    unsigned int indices[] = {
        //bottom
        0, 1, 3,
        3, 2, 0,
        //top
        4, 5, 7,
        7, 6, 4,
        //front
        0, 1, 5,
        5, 4, 0,
        //right side
        1, 3, 7,
        7, 5, 1,
        //left side
        0, 2, 6,
        6, 4, 0,
        
        //back
        2, 3, 7,
        7, 6, 2
    };
    
    int k = 0;
    for (int j = 0; j < 8; j++)
    {
        
        for (int i = 0; i < 8; i++)
        {
            /*bottom side*/
            
            //Bottom left
            vertices[k][0] = xLeft + i * fUnit;
            vertices[k][1] = 0.6f - j * fUnit;
            vertices[k][2] = -0.05f;
            //texture coordinates
            vertices[k][3] = 0.0f;
            vertices[k][4] = 0.0f;
            //Bottom right
            vertices[k][5] = xRight + i * fUnit;
            vertices[k][6] = 0.6f - j * fUnit;
            vertices[k][7] = -0.05f;
            //texture coordinates
            vertices[k][8] = 1.0f;
            vertices[k][9] = 0.0f;
            //Top right
            vertices[k][15] = xRight + i * fUnit;
            vertices[k][16] = 0.7f - j * fUnit;
            vertices[k][17] = -0.05f;
            //texture coordinates
            vertices[k][18] = 1.0f;
            vertices[k][19] = 1.0f;
            //Top left
            vertices[k][10] = xLeft + i * fUnit;
            vertices[k][11] = 0.7f - j * fUnit;
            vertices[k][12] = -0.05f;
            //texture coordinates
            vertices[k][13] = 1.0f;
            vertices[k][14] = 0.0f;
            
            
            /*top side*/
            
            //Bottom left
            vertices[k][20] = xLeft + i * fUnit;
            vertices[k][21] = 0.6f - j * fUnit;
            vertices[k][22] = 0.05f;
            //texture coordinates
            vertices[k][23] = 0.0f;
            vertices[k][24] = 0.0f;
            //Bottom right
            vertices[k][25] = xRight + i * fUnit;
            vertices[k][26] = 0.6f - j * fUnit;
            vertices[k][27] = 0.05f;
            //texture coordinates
            vertices[k][28] = 1.0f;
            vertices[k][29] = 0.0f;
            //Top left
            vertices[k][30] = xLeft + i * fUnit;
            vertices[k][31] = 0.7f - j * fUnit;
            vertices[k][32] = 0.05f;
            //texture coordinates
            vertices[k][33] = 1.0f;
            vertices[k][34] = 1.0f;
            //Top right
            vertices[k][35] = xRight + i * fUnit;
            vertices[k][36] = 0.7f - j * fUnit;
            vertices[k][37] = 0.05f;
            //texture coordinates
            vertices[k][38] = 0.0f;
            vertices[k][39] = 1.0f;
            
            /*front side*/
            
            /*back side*/
            
            /*right side view*/
            
            /*left side view*/
            
            glGenVertexArrays(1, &VAOs[k]);
            
            glGenBuffers(1, &EBOs[k]);
            glGenBuffers(1, &VBOs[k]);
            
            glBindVertexArray(VAOs[k]);
            
            glBindBuffer(GL_ARRAY_BUFFER, VBOs[k]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[k]), vertices[k], GL_STATIC_DRAW);
            
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[k]);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
            
            //position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            // texture coord attribute
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            
            k++;
        }
    }
    
}

void StaticWall::draw()
{
    for (int i = 0; i < STATIC_WALLS; i++)
    {
        glBindTexture(GL_TEXTURE_2D, wallTexture);
        glBindVertexArray(VAOs[i]);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    }
}
