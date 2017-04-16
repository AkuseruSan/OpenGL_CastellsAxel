#include "GameEngine.h"

const int WIDTH = 512;
const int HEIGHT = 512;

void InputUpdate();
void Update();
void Draw();

int main()
{
	GE.Run(WIDTH, HEIGHT, "OpenGL - TestChamber", Update, Draw);

	return 0;
}

void Update()
{
	InputUpdate();
}

void Draw()
{
	R.DrawTriangle();
}

void InputUpdate()
{
	if (IM.GetKeyboardInput().first == GLFW_KEY_ESCAPE && IM.GetKeyboardInput().second == GLFW_PRESS)
		glfwSetWindowShouldClose(W, GL_TRUE);
}