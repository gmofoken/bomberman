#include "Window.hpp"
#include "MainMenu.hpp"
#include "Sound.hpp"

//Error checking         :Cradebe
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

Window::Window(){
    _width  = WIDTH;
    _window = nullptr;
    _height  = HEIGHT;
    _sound = new Sound();
    _keyEvents = new WindowKeyEvents();
}
Window::~Window(){
    // delete graphics;
    // delete _sound;
    // delete _keyEvents;
}

//Runs Game         :Cradebe
void Window::runGame(){
    // _sound->playMusicForvever(MUSIC_BEAR);
    initiateSystems();
}

//Initiates Screen  :Cradebe
void Window::initiateSystems(){
    
    glfwSetErrorCallback(error_callback);
    
    // Initialise GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    _window = glfwCreateWindow(800, 600, "Bomberman", NULL, NULL);
    
    if (!_window)
    {
        terminateSystems();
    }
    
    glfwMakeContextCurrent(_window);
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark green background
    glClearColor(0.0f, 0.3f, 0.0f, 0.0f);
    
    //Keeps screen open
    /*while (!glfwWindowShouldClose(_window))
    {
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);*/
}

void Window::setGraphics(Graphics g)
{
    this->graphics = &g;
}

//Terminates initialised system
void Window::terminateSystems()
{
    fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
    getchar();
    glfwDestroyWindow(_window);    
    glfwTerminate();
    exit(EXIT_FAILURE);
}

Sound* Window::getSound()
{
    return (_sound);
}

GLFWwindow* Window::getWindow()
{
    return _window;
}

WindowKeyEvents* Window::getEvents()
{
    return (_keyEvents);
}

