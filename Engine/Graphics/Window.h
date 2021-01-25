#pragma once
#include <iostream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Buffer.h"
#include "/GameEngineDevelopment/Game Engine Project/Engine/Game/Games.h"

class Window
{

public:

	GLFWwindow* window;

	Window(Games* game, int versionMajor = 3, int versionMinor = 3, int hint = GLFW_OPENGL_PROFILE, int value = GLFW_OPENGL_CORE_PROFILE);
	
	void CreateViewportAndWindow(int leftPositionOne, int leftPositionTwo, int width, int height, const char* name);
	bool CreateWindow(GLFWwindow* window, int leftPositionOne, int leftPositionTwo, int width, int height, const char* name = " ");
	bool IsWindowValid(GLFWwindow* _window);
	static void OnKeyPress(GLFWwindow* window, int key, int scancode, int action, int mode);
	void RunWindow(GLFWwindow* _window, Buffer buffer, Games* game);
	void EndWindow(GLFWwindow* _window);
	void ReturnGLVersion();
	void ReturnRenderer();
	void ReturnShadingLanguage();
	void ReturnUsefulStats();
	~Window();
private:
	//static Games* gameType;
};

