#pragma once

#include "Renderer.h"
#include "InputManager.h"
#include <functional>

#define GE GameEngine::Instance()

class GameEngine
{
private:
	GameEngine();
	GameEngine(GameEngine const&);
public:
	static GameEngine& Instance()
	{
		static GameEngine ge;
		return ge;
	}
	~GameEngine();

	static void error_callback(int error, const char* description);
	void Run(const int width, const int height, char* titleString, std::function<void()> Update, std::function<void()> Draw);
};