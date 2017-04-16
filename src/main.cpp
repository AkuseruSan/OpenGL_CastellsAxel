#include "GameEngine.h"

const int WIDTH = 512;
const int HEIGHT = 512;

void InputUpdate()
{
	if (IM.GetKeyCallback().first == GLFW_KEY_ESCAPE && IM.GetKeyCallback().second == GLFW_PRESS)
		glfwSetWindowShouldClose(W, GL_TRUE);
}

void Update()
{
	InputUpdate();
}

void Draw()
{
	R.DrawTriangle();
}

int main()
{
	GE.Run(WIDTH, HEIGHT, "OpenGL - TestChamber", Update, Draw);

	return 0;
}