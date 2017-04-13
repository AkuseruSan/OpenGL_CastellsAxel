#pragma once

#include "Settings.h"
#include "Renderer.h"
#include "InputManager.h"

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

	void Run();
};