#ifndef MAINMENU_HPP
# define MAINMENU_HPP

//# include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
# include <iostream>

#include "Window.hpp"
#include "shader.hpp"

struct Input
{
    enum GameCommands{
        Start,
        Continue,
        Settings,
        HighScore,
        Exit
    };
};

class MainMenu
{
    public:
		MainMenu();
        MainMenu(GLFWwindow* window, Graphics *g);
        ~MainMenu();

        MainMenu(MainMenu & obj);
        MainMenu& operator=(MainMenu& obj);

        void gameStart();
        void gameSettings();
        void gameContinue();       
        void gameExit();
        void toggleCommands(int input);
        void executeCommand(int command);
        void setGraphics(Graphics *g);
        void gameHighScore();
        void initMenuImage();
        void LoadMainMenuImage();
        void menuCleanup();

        int getInput();
    
    private:
        int _input;
        GLFWwindow* _window;
        Graphics *graphics;
        GLuint menuVAO, menuTexture, menuEBO, menuVBO, programID;
};

#endif