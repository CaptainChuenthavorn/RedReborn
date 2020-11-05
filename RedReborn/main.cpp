#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>

int main()
{

	

/*

	sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Reborn", sf::Style::Close | sf::Style::Resize);

	sf::Clock cl;
	float times;

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("asset/PlayerSheet.png"))
	{
		//Handle error
	}
	int ShapeX = 96;
	int ShapeY = 96;

	sf::Sprite player;
	player.setTexture(playerTexture);
	player.setTextureRect(sf::IntRect(0, 0, ShapeX, ShapeY));

	int animationFrame = 0; //Frame of animate
	while (window.isOpen())
	{
		window.draw(player);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.move(-0.1f, 0.0f);
			player.setTextureRect(sf::IntRect(ShapeX * animationFrame, ShapeY * 1, ShapeX, ShapeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(0.1f, 0.0f);
			player.setTextureRect(sf::IntRect(ShapeX * animationFrame, ShapeY * 0, ShapeX, ShapeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0.0f, -0.1f);
			player.setTextureRect(sf::IntRect(ShapeX * animationFrame, ShapeY * 5, ShapeX, ShapeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0.0f, 0.1f);
			player.setTextureRect(sf::IntRect(ShapeX * animationFrame, ShapeY * 5, ShapeX, ShapeY));
		}
		/*sf::Event event;
		while (window.pollEvent(event))
		{
				if (event.type == sf::Event::Closed)
					window.close();
			}

		animationFrame++;
		if (animationFrame >= 7)
		{
			animationFrame = 0;
		}
			window.clear();
			
			

		}

	return 0;
}*/