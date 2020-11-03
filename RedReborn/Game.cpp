#include "Game.h"
Game::Game() :m_window("Red Reborn", sf::Vector2u(1080, 720))
{
	m_redTexture.loadFromFile("GraveRobber.png");
	m_red.setTexture(m_redTexture);
	m_increment = sf::Vector2i(4, 4);
}
Game::~Game()
{

}
void Game::Update()
{
	m_window.Update();//Update window event
	MoveRed();
}
void Game::MoveRed()
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_redTexture.getSize();
	if (m_red.getPosition().x - (l_textSize.x / 2) < 0 && m_increment.x <0 || m_red.getPosition().x + (l_textSize.x / 2) > l_windSize.x && m_increment.x > 0)
	{
		m_increment.x = -m_increment.x;
	}
	if (m_red.getPosition().y - (l_textSize.y / 2) < 0 && m_increment.y <0 || m_red.getPosition().y + (l_textSize.y / 2) > l_windSize.y && m_increment.y > 0)
	{
		m_increment.y = -m_increment.y;
	}
	m_red.setPosition(m_red.getPosition().x + m_increment.x, m_red.getPosition().y + m_increment.y);

}
void Game::Render() {
	m_window.BeginDraw(); // Clear.
	m_window.Draw(m_red);
	m_window.EndDraw(); // Display.
}
window* getWindow()
{
#include "window.h"
}