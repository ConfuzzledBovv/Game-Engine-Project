#include "Vector3D.h"
#include "Window.h"
#include "Shaders.h"
#include "Buffer.h"
#include "Sprite.h"
#include "Games.h"
#include "Alien.h"
#include "Character.h"
#include "SpaceInvadersGame.h"

int main()
{	
	Buffer buffer;
	Games* spaceInvaders = new SpaceInvadersGame(buffer);
	Maths::Matrix Coordinates(-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f);
	Window newWindow(spaceInvaders, 3, 3);


	newWindow.CreateViewportAndWindow(0, 0, 640, 480, spaceInvaders->gameName);
	newWindow.ReturnUsefulStats();
	buffer.Buffer_Texture();
	Shaders shader(Coordinates);
	shader.CreateVertexShader();
	shader.CheckIfShaderCompiled(shader.data.vertexShader);
	shader.CreateFragmentShader();
	shader.CheckIfShaderCompiled(shader.data.fragmentShader);
	shader.CreateShaderProgram(shader.data.vertexShader, shader.data.fragmentShader);
	if (!shader.CheckIfShaderProgramCompiled(shader.data.shaderProgram))
	{
		delete[] buffer.buffer.data;
		printf("Shader Program failed, Buffer data deleted.");
		return -1;
	}
	spaceInvaders->RunGame();
	
	shader.Draw();

	newWindow.RunWindow(newWindow.window, buffer, spaceInvaders);



	shader.ExitProgram();

	return 0;
}


