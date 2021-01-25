#pragma once
#include <iostream>
#include <fstream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Matrix.h"

struct ShaderData
{
	GLuint fragmentShader;
	GLuint vertexShader;
	GLuint shaderProgram;

};

class Shaders
{
public:

	GLuint vbo, vao;
	ShaderData data;
	size_t buffer_width = 224;
	size_t buffer_height = 256;
	Shaders(Maths::Matrix vertices);
	GLuint CreateVertexShader();
	GLuint CreateFragmentShader();
	bool CheckIfShaderCompiled(GLuint shader);
	bool CheckIfShaderProgramCompiled(GLuint shaderProgram);
	void CreateShaderProgram(GLuint vertexShader, GLuint fragmentShader);
	void RunShaderProgram(GLuint shaderProgram);
	int ExitProgram();
	void Draw();
	~Shaders();
};

