#include "GameEngine.h"

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::Run(const int width, const int height, char* titleString, std::function<void()> Update, std::function<void()> Draw)
{
	R.Init(width, height, titleString);
	IM.Init(W);

	while (!glfwWindowShouldClose(W))
	{
		Update();

		Draw();

		glfwSwapBuffers(W);
		glfwPollEvents();
	}

	glfwDestroyWindow(W);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}