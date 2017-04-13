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
	glfwSetKeyCallback(window, IM.key_callback);
}