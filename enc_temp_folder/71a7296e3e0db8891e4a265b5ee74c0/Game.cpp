#include "Game.h"

//Static functions

//Initializer functions

//Constructor / destructors

void Game::initWindow()
{
	//Create Creates a SFML window using options from window.ini file
	
	std::ifstream ifs("Config/window.ini");//ifs = in file stream //call "..." to read

	std::string title = "none";
	sf::VideoMode window_bounds(1080,720);
	unsigned framerate_limit = 120;
	bool vertical_sycn_enabled = false;
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sycn_enabled;
	}

	ifs.close(); // don't forget to close file that you open 5555555
	/* usally write this but if we have config they will read value and we have to set tovariable we create so in end we only change in config
	this ->window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Red Reborn");
	this->window->setFramerateLimit(120);
	window->setVerticalSyncEnabled(false);*/

	this->window = new sf::RenderWindow(window_bounds,title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sycn_enabled);
}

Game::Game()
{
	/*when call Game in main will run initWindow automatically*/
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::updateDt()
{
	/*Update the dt vatiable with the time to update and render one frame */
	this->dt = this->dtClock.restart().asSeconds();

	system("cls");
	std::cout << dt << "\n";
}

//Functions
void Game::updateSFMLEvents()
{

	sf::Event event;
	while (window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateSFMLEvents();

	int sum = 0;
	for (size_t i = 0;i < 10000000;i++)/*note that if method in game have a lot you dtClock will slowly (lag) if less method it will smoothly not lag*/
	{
		sum += i;
	}
}

void Game::render()
{
	this->window->clear();
	
	//render items
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
