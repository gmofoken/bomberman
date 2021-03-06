// Include standard headers
#include "Wall.hpp"
#include "shader.hpp"
#include "Graphics.hpp"
#include "Window.hpp"
#include "MainMenu.hpp"
#include "Player.hpp"
#include "Floor.hpp"
#include "Portal.hpp"
#include "StaticWall.hpp"
#include "Destructible.hpp"
#include "camera.hpp"
#include "Gamestate.hpp"

GLFWwindow* window;
MainMenu *mainMenu;
Graphics *graphics;
Player *player;

// camera
glm::vec3 cameraPos   = glm::vec3(-1.0f, 2.0f,  2.76f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  1.0f);

//move player callback
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
        {
			glfwSetKeyCallback(window, player_callback);
            glEnable(GL_DEPTH_TEST);
        }
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	Sound *sound;
	GameState gs;	
	Window myWindow;
	WindowKeyEvents *keyEvents;

	myWindow.runGame();
	sound = myWindow.getSound();
	window = myWindow.getWindow();
	keyEvents = myWindow.getEvents();

	glfwSetKeyCallback(window, key_callback);

    // Initialize GLEW
    if (myWindow.initializeGlew() == false)
        return -1;

	graphics = new Graphics();
	player = new Player();
	Wall wall;
	StaticWall staticWall;
	Portal portal;
	Destructible destructible;
    Floor floor;
    Camera camera(cameraPos, cameraFront, cameraUp, window);

	gs.loadPlayerState(player);
	graphics->initGlArrays();
	//graphics->initPlayerVertices(&pVBO, &pVAO, &pEBO);
	mainMenu = new MainMenu(window, graphics);
	mainMenu->initMenuImage();
	wall.init();
	staticWall.init();
	portal.init();
	destructible.init1();
    floor.init();
	player->init();
	Mix_VolumeMusic(10);
    
    //=========================================================================================
    //build and compile our shader program
    GLuint shadersID = LoadShaders("shaderVertexCoordinate.vs", "shaderFragCoordinate.fs");
    glUseProgram(shadersID);
    camera.perspectiveView(shadersID);
    //====================================================================================
    
    do {
		// Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		keyEvents->keyEventsWrapper(window, sound, graphics);
		switch (graphics->getDrawMode())
		{
			case MAINMENU:
				sound->playMusicForvever(MUSIC_MENU1);
				mainMenu->LoadMainMenuImage();
				break;
			case GAMEPLAY:
				sound->playMusicForvever(MUSIC_BACK);
				// Use our shader
				//glUseProgram(programID);
                //------------------------------
                camera.processKeyInput();
                glUseProgram(shadersID);
                camera.cameraTimeLogic();
                camera.cameraFunction(shadersID);
                floor.draw();
                //---------------------------------
				wall.draw();
				staticWall.draw();
				portal.draw();
				destructible.draw();
                
                glUseProgram(player->getProgramId());
                camera.cameraFunction(player->getProgramId());
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

	/* emsimang: save the player's coords*/
	gs.savePlayerState(*player);

	// Cleanup VBO
	delete graphics;
	delete player;
	
	mainMenu->menuCleanup();
	//glDeleteProgram(programID);
    glDeleteProgram(shadersID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
