#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>/*allow to open a file to read text*/
#include <sstream>/*get a data*/
#include <sfml\Window.hpp>
#include <sfml\Graphics.hpp>
#include <sfml\Audio.hpp>
#include <stack>
#include <map>
#include <vector>
class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderWindow* window);
	~State();

	const bool& getQuit() const;
	virtual void checkForQuit(); 

	virtual void updateKeyblinds(const float & dt)=0;
	virtual void endState() = 0;
	virtual void update(const float& dt)=0;
	virtual void render(sf::RenderTarget* target = nullptr)=0;
};

