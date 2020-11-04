#pragma once // == ifndef ... GAME_H
#include "GameState.h"
class Game
{
private:
	//Variables
	sf::RenderWindow* window;//pointer (can use this->)
	sf::Event sfEvent;


	sf::Clock dtClock;
	float dt; //clock variable to record sf clock && counting time as second with name dt| variable float 

	std::stack<State*> states; //initialize stack variable && State is abstract class (can only create pointer) && create new stack because we gonna go dowm slide(put out old slide)

	//Initialization
	void initWindow();
	void initStates();
public:

	//Constructor / destructors

	Game();
	~Game();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();// update state that will come into stack
	void render();
	void run();//run our game;)






};

