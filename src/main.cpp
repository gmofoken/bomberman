// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
//#include <GL/glew.h>

// Include GLFW
//#include <GLFW/glfw3.h>

#include "Wall.hpp"
#include "shader.hpp"
#include "Graphics.hpp"
#include "Window.hpp"
#include "MainMenu.hpp"
#include "Player.hpp"

GLFWwindow* window;
MainMenu *mainMenu;
Graphics *graphics;
Player *player;

//move player callback        :Trinity
static void player_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveDown();
	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveUp();
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveLeft();
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveRight();
	if (key == GLFW_KEY_SPACE)
	{
		std::cout << "Call the Bomb Class \n";
	}
}

//Key Checking input        :Cradebe
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ((key == GLFW_KEY_DOWN || key == GLFW_KEY_UP || key == GLFW_KEY_ENTER) && action == GLFW_PRESS)
	{
		mainMenu->toggleCommands(key);
		if (mainMenu->getInput() == 0 && key == GLFW_KEY_ENTER)
			glfwSetKeyCallback(window, player_callback);
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	Sound *sound;
	Window myWindow;
	WindowKeyEvents *keyEvents;

	myWindow.runGame();
	sound = myWindow.getSound();
	window = myWindow.getWindow();
	keyEvents = myWindow.getEvents();

	glfwSetKeyCallback(window, key_callback);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "TextureFragmentShader.hlsl");

	GLuint wallTexture;

	Texture texture("next.JPEG", &wallTexture);

	graphics = new Graphics();
	player = new Player();
	Wall wall;

	graphics->initGlArrays();
	//graphics->initPlayerVertices(&pVBO, &pVAO, &pEBO);
	mainMenu = new MainMenu(window, graphics);
	mainMenu->initMenuImage();
	wall.init();
	player->init();

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		switch (graphics->getDrawMode())
		{
		case MAINMENU:
			mainMenu->LoadMainMenuImage();
			keyEvents->keyEventsWrapper(window, sound);
			break;
		case GAMEPLAY:
			//bind texture
			glBindTexture(GL_TEXTURE_2D, wallTexture);
			// Use our shader
			glUseProgram(programID);
			wall.draw();
			graphics->drawElements();
			//player transformations
			player->transform();
			//draw player
			player->draw();
		default:
			break;
		}

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	// Cleanup VBO
	delete graphics;
	delete player;
	mainMenu->menuCleanup();
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
