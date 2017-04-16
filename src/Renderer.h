#pragma once
//GLEW
#define GLEW_STATIC
#include <GL\glew.h>
//GLFW
//#include <GLFW\glfw3.h>
//#include <iostream>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Shader.h"
#include <SOIL.h>

using namespace glm;
using namespace std;

#define R Renderer::Instance()
#define W R.GetWindow()

class Renderer
{
private:
	Renderer();
	Renderer(Renderer const&);

	GLFWwindow* window;
public:
	static Renderer& Instance()
	{
		static Renderer myRenderer;
		return myRenderer;
	}
	~Renderer();

	void Init(const int width, const int height, char* titleString);

	GLFWwindow* GetWindow();
	Shader* shader;

	void DrawTriangle();
};