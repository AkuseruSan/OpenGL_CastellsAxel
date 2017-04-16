#include "GameEngine.h"

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void GameEngine::Run(const int width, const int height, char* titleString, std::function<void()> Update, std::function<void()> Draw)
{
	//glfwSetErrorCallback(error_callback);

	R.Init(width, height, titleString);
	IM.Init(W);

	while (!glfwWindowShouldClose(W))
	{
		R.SetProjectionMatrix();
		
		Update();
		Draw();

		glfwSwapBuffers(W);
		glfwPollEvents();
	}

	glfwDestroyWindow(W);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}