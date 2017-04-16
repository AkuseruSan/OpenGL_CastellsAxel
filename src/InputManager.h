#pragma once
//GLFW
#include <GLFW\glfw3.h>
#include <iostream>
#include <queue>



using namespace std;

#define IM InputManager::Instance()

class InputManager
{
private:
	InputManager();
	InputManager(InputManager const&);

	//Recoge "key" y "action" de key_callback
	pair<int, int> keyCallbackRet;
public:
	static InputManager& Instance()
	{
		static InputManager im;
		return im;
	}
	~InputManager();

	void Init(GLFWwindow* window);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
		//TODO, comprobar que la tecla pulsada es escape para cerrar la aplicación y la tecla w para cambiar a modo widwframe
		IM.keyCallbackRet = pair<int, int>(key, action);
	}

	//Primer int: key  |  Segundo int: action
	pair<int, int> GetKeyCallback();
};