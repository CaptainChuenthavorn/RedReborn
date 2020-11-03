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
class State
{
private:
	std::vector<sf::Texture> textures;


public:
	State();
	~State();

	virtual void update()=0;
	virtual void render()=0;
};

