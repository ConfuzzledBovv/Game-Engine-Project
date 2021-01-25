#include "Shaders.h"

// Shaders
const GLchar* vertexShaderSource = "\n"
"#version 330\n"
"\n"
"noperspective out vec2 TexCoord;\n"
"\n"
"void main(void){\n"
"\n"
"    TexCoord.x = (gl_VertexID == 2)? 2.0: 0.0;\n"
"    TexCoord.y = (gl_VertexID == 1)? 2.0: 0.0;\n"
"    \n"
"    gl_Position = vec4(2.0 * TexCoord - 1.0, 0.0, 1.0);\n"
"}\n";
const GLchar* fragmentShaderSource = "\n"
"#version 330\n"
"\n"
"uniform sampler2D buffer;\n"
"noperspective in vec2 TexCoord;\n"
"\n"
"out vec3 outColor;\n"
"\n"
"void main(void){\n"
"    outColor = texture(buffer, TexCoord).rgb;\n"
"}\n";

// I intend to change the shader functionality and implemenation at a later date. 

typedef void(*GLFWerrorfun)(int, const char*);

void Error_Callback(int error, const char * description)
{
	fprintf(stderr, "Error: %s\n", description);
}

Shaders::Shaders(Maths::Matrix vertices)
{
	if (glfwInit() && glewInit() == GLEW_OK)
	{
		glfwSetErrorCallback(Error_Callback);
		Maths::Matrix* verticesPtr = &vertices;
		std::cout << "Glew and glfw initialized" << std::endl;
		glGenVertexArrays(1, &vao);
	//	glBindVertexArray(vao);
	//	glGenBuffers(1, &vbo);
	//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), verticesPtr, GL_STATIC_DRAW);
	//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Maths::Matrix*), (GLvoid*)0);
	//	glEnableVertexAttribArray(0);
	//	glBindVertexArray(0);
	}
	else
	{
		std::cout << "Shader initialization failed" << std::endl;
	}
}
 
GLuint Shaders::CreateVertexShader()
{
	data.vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(data.vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(data.vertexShader);
	CheckIfShaderCompiled(data.vertexShader);

	return data.vertexShader;
}

GLuint Shaders::CreateFragmentShader()
{
	data.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(data.fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(data.fragmentShader);

	CheckIfShaderCompiled(data.fragmentShader);

	return data.fragmentShader;
}

bool Shaders::CheckIfShaderCompiled(GLuint shader)
{
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR WITH SHADER COMPILATION" << std::endl;
		std::cout << infoLog << std::endl;
		return false;
	}
	std::cout << "Shader Compiled succesfully" << std::endl;
	return true;
}

bool Shaders::CheckIfShaderProgramCompiled(GLuint shaderProgram)
{
	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR WITH SHADER PROGRAM COMPILATION" << std::endl;
		std::cout << infoLog << std::endl;
		return false;
	}
	std::cout << "Shader Program Compiled Succesfully" << std::endl;
	return true;
}

void Shaders::CreateShaderProgram(GLuint vertexShader, GLuint fragmentShader)
{
	data.shaderProgram = glCreateProgram();
	glAttachShader(data.shaderProgram, vertexShader);
	glAttachShader(data.shaderProgram, fragmentShader);
	glLinkProgram(data.shaderProgram);

	CheckIfShaderProgramCompiled(data.shaderProgram);
}

void Shaders::RunShaderProgram(GLuint shaderProgram)
{
	glUseProgram(shaderProgram);
	glDeleteShader(data.vertexShader);
	glDeleteShader(data.fragmentShader);
}

int Shaders::ExitProgram()
{
	printf("Program was exited suddenly");
	glfwTerminate();
	glDeleteVertexArrays(1, &vao);
	return -1;
}

void Shaders::Draw()
{
	RunShaderProgram(data.shaderProgram);
	GLint location = glGetUniformLocation(data.shaderProgram, "buffer");
	glUniform1i(location, 0);
	glDisable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(vao);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
}



Shaders::~Shaders()
{

}


