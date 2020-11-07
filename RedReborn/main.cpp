#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include "TileMap.cpp"
int main()
{
  
    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
    sf::View first(sf::FloatRect(500, 500, 1000, 1000));
    sf::View second(sf::Vector2f(250, 250), sf::Vector2f(800, 600));
    sf::View view(sf::FloatRect(0, 0, 800, 600)); //top-left 0:0 bottom-right 800:600
    view.setCenter(100, 100);//move center to 100, 100
    view.move(100, 100);//move by 100x100 offset
    view.setSize(640, 480);//
    view.zoom(0.5f);//smaller view space
    window.setView(view);//applies view to window


    // define the level with an array of tile indices
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("Tileset.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // draw the map
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}