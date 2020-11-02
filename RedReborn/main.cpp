class window {
public:
	window();
	window(const std::string& l_title, const sf::Vector2u& l_size);
	~window();
	void BeginDraw(); // Clear the window.
	void EndDraw(); // Display the changes.
	void Update();
	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();
	void ToggleFullscreen();
	void Draw(sf::Drawable& l_drawable);
private:
	void Setup(const std::string& l_title,
		const sf::Vector2u& l_size);
	void Destroy();
	void Create();
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};

#include <sfml\Graphics.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Reborn ");

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("asset/GraveRobber.png")) {}
	sf::Sprite player(playerTexture);
	sf::Vector2u size = playerTexture.getSize();
	sf::Vector2f increment(0.4f, 0.4f);
	player.setOrigin(size.x / 2, size.y / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (player.getPosition().x -( size.x/2 ) < 0&& increment.x <0 || player.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0)
		{
			increment.x = -increment.x;
		}
		if (player.getPosition().y - (size.y / 2) < 0 &&  increment.y <0 || player.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0)
		{
			increment.y = -increment.y;
		}
		player.setPosition(player.getPosition() + increment);

		window.clear(); //วาดหลังclear
		//window.draw(rectangle);
		window.draw(player);
		window.display();
	}
	return 0;
}

