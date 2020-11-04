#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window) //call state constructor
{
}

GameState::~GameState()
{
}


void GameState::endState()
{
	std::cout << "ending Game" << "\n";
}

void GameState::updateKeyblinds(const float& dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateKeyblinds(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << "\n";
}

void GameState::render(sf::RenderTarget* target )
{
}
