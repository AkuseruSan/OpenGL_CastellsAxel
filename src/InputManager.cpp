#include "InputManager.h"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

pair<int, int> InputManager::GetKeyCallback()
{
	return keyCallbackRet;
}

void InputManager::Init(GLFWwindow* window)
{
	//set function when callback
	//TODO

	glfwSetKeyCallback(window, IM.key_callback);
}