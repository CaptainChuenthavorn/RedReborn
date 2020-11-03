#pragma once
#include "SFML/Graphics.hpp"
#include "window.h"
class Game
{
public:
	Game();
	~Game();

	//void HandleInput();
	void Update();
	void Render();
	window* getWindow();

private:
	void MoveRed();
	window m_window;
	sf::Texture m_redTexture;
	sf::Sprite m_red;
	sf::Vector2i m_increment;
};


