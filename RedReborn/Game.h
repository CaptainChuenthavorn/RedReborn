#pragma once // == ifndef ... GAME_H
#include "State.h"
class Game
{
private:
	//Variables
	sf::RenderWindow* window;//pointer (can use this->)
	sf::Event sfEvent;


	sf::Clock dtClock;
	float dt; //clock variable to record sf clock && counting time as second with name dt| variable float 

	//Initialization
	void initWindow();

public:

	//Constructor / destructors

	Game();
	~Game();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();






};

