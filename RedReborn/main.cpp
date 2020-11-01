#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080,720), "Red Journey");

    Menu menu(window.getSize().x, window.getSize().y);

    sf::Texture texture;
    if (!texture.loadFromFile("BG2.JPG")) {
        //handle error
    }
    sf::Sprite background;
    background.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0 :
                        std::cout << "Play has been preesed" << std::endl;
                        //go to state
                        break;
                       
                    case 1 :
                        std::cout << "Leaderboard has been preesed" << std::endl;
                        //go to state
                        break;

                    case 2 :
                        window.close();
                        break;
                    }
                    break;
                }
                break;

            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        window.draw(background);
        
        menu.draw(window);
        window.display();
    }
    return 0;
}