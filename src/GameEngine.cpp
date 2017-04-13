#include "GameEngine.h"

GameEngine::GameEngine()
{
	R.Init(Settings::WIDTH, Settings::HEIGHT, "Hi!");
	IM.Init(W);
}

GameEngine::~GameEngine()
{

}

void GameEngine::Run()
{
	while (!glfwWindowShouldClose(W))
	{
		if (IM.GetKeyCallback().first == GLFW_KEY_ESCAPE && IM.GetKeyCallback().second == GLFW_PRESS)
			glfwSetWindowShouldClose(W, GL_TRUE);

		glfwSwapBuffers(W);
		glfwPollEvents();
	}

	glfwDestroyWindow(W);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}