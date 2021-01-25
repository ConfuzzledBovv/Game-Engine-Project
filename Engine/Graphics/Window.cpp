#include "Window.h"

Games* gameType;

Window::Window(Games* game, int versionMajor, int versionMinor, int hint, int value)
{
	glewExperimental = GL_TRUE;
	if (!glfwInit() || !glewInit())
	{
		std::cout << "Glew or glfw didn't initialize" << std::endl;
	}
	else
	{
		std::cout << "Glew and glfw initialized" << std::endl;
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
		glfwWindowHint(hint, value);
		gameType = game;
	}
}

void Window::CreateViewportAndWindow(int leftPositionOne, int leftPositionTwo, int width, int height, const char* name)
{
	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (IsWindowValid(window))
	{
		glfwMakeContextCurrent(window);
		//glViewport(leftPositionOne, leftPositionTwo, width, height);
		glClearColor(1.0, 0.0, 0.0, 1.0);
	}
}

bool Window::CreateWindow(GLFWwindow* window, int leftPositionOne, int leftPositionTwo, int width, int height, const char* name)
{
	if (IsWindowValid(window))
	{
		glfwMakeContextCurrent(window);
		glViewport(leftPositionOne, leftPositionTwo, width, height);
		std::cout << "Window created!" << std::endl;
		glClearColor(1.0, 0.0, 0.0, 1.0);
		return true;
	}
	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (window)
	{
		glfwMakeContextCurrent(window);
		glViewport(leftPositionOne, leftPositionTwo, width, height);
		std::cout << "Window created on second try!" << std::endl;
		return true;
	}
	std::cout << "Window creation failed!" << std::endl;
	return false;
}

bool Window::IsWindowValid(GLFWwindow* _window)
{
	if (!_window)
	{
		std::cout << "Window returned nullptr!" << std::endl;
		return false;
	}
	std::cout << "Window returned valid data!" << std::endl;
	return true;
}

void Window::OnKeyPress(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
			std::cout << "Escape key was pressed, window should close" << std::endl;
		}
		break;
	case GLFW_KEY_LEFT:
	case GLFW_KEY_A: 
		if (action == GLFW_PRESS)
		{
			gameType->LeftKey();
		}
		else if (action == GLFW_RELEASE)
		{
			gameType->LeftRightKeyReleased();
		}
		break;
	case GLFW_KEY_RIGHT:
	case GLFW_KEY_D:
		if (action == GLFW_PRESS)
		{
			gameType->RightKey();
		}
		else if (action == GLFW_RELEASE)
		{
			gameType->LeftRightKeyReleased();
		}
		break;
	case GLFW_KEY_UP:
	case GLFW_KEY_W:
		if (action == GLFW_RELEASE)
		{
			gameType->UpKey();
		}
	default:
		break;
	}
}

void Window::RunWindow(GLFWwindow * _window, Buffer buffer, Games* game)
{
	if (IsWindowValid(_window) == false)
	{
		std::cout << "Window not valid!" << std::endl;
		return;
	}
	gameType = game;
	glfwSetKeyCallback(window, OnKeyPress);
	glfwSwapInterval(1);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glTexSubImage2D(
			GL_TEXTURE_2D, 0, 0, 0,
			buffer.buffer.width, buffer.buffer.height,
			GL_RGBA, GL_UNSIGNED_INT_8_8_8_8,
			buffer.buffer.data
		);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		glfwSwapBuffers(window);

		glfwPollEvents();

		gameType->GameLoop();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::EndWindow(GLFWwindow * _window)
{
	glfwSetWindowShouldClose(window, GL_TRUE);
}

void Window::ReturnGLVersion()
{
	int glVersion[2] = { -1, 1 };
	glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

	printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);
}

void Window::ReturnRenderer()
{
	printf("Renderer used: %s\n", glGetString(GL_RENDERER));
}

void Window::ReturnShadingLanguage()
{
	printf("Shading Language: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void Window::ReturnUsefulStats()
{
	ReturnGLVersion();
	ReturnRenderer();
	ReturnShadingLanguage();
}


Window::~Window()
{

}
