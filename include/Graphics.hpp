/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditshwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:44:19 by tditshwe          #+#    #+#             */
/*   Updated: 2017/09/11 14:39:35 by rmoswela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GRAPHICS_HPP
#define _GRAPHICS_HPP

#include "glew.h"
#include "glfw3.h"

#define STATIC_WALLS 64

enum GameMode
{
	MAINMENU,
	GAMEPLAY,
	GAMEPAUSE
};

class Graphics
{
public:
	Graphics();
	~Graphics();

	void initGlArrays();
	void drawElements();
	void setDrawMode(GameMode mode);

	GameMode getDrawMode();

private:
	GLuint VertexArrayID, staticWallTexture;
	GLuint programID, VAOs[STATIC_WALLS], VBOs[STATIC_WALLS], EBOs[STATIC_WALLS];
	GameMode drawMode;
};

#endif
