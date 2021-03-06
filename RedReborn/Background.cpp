#include "Background.h"

Background::Background(sf::Texture* texture, float speed)
{
	
	this->speed = speed;
	this->size = sf::Vector2f(512.0f*4.5, 320.0f*4.5);
	
	body[0].setSize(size);
	body[1].setSize(size);
	//body[0].setPosition(512.0f * 4.5, 100.0f);
	body[1].setPosition(512.0f * 4.5, 100.0f);
	body[0].setTexture(texture);
	body[1].setTexture(texture);
	body[0].setOrigin(0, 0);

	if (speed < 0)//left
		body[1].setPosition(size.x - 2.0f, 0.0f);
	else
		body[1].setPosition(-size.x + 2.0f, 0.0f);

}

void Background::Update(float deltaTime)
{
	for (int i = 0;i < 2;i++) {
		position = body[i].getPosition();
		body[i].move(speed * deltaTime, 0);

		if (position.x <= -size.x && speed < 0)
			body[i].setPosition(size.x - 4.0f, position.y);
		else if (position.x >= -size.x && speed > 0)
			body[i].setPosition(size.x + 4.0f, position.y);

	}
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(body[0]);
	window.draw(body[1]);
}
