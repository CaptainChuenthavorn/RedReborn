#pragma once
#include "State.h"
class GameState :
	public State//Base class
{
public:
	GameState(sf::RenderWindow* window);
	~GameState();

	//Functions
	void endState();
	void updateKeyblinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

