#include "SFML/Window.hpp"
#include <iostream>
#include "Menu.h"
#include "State.hpp"
#include "GameState.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "My window");

    Menu menu(window.getSize().x,window.getSize().y);
    sf::Texture texture;
    if (!texture.loadFromFile("RedBGTheSeries_blue.JPG"))
    {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    sf::Sprite background;
    background.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
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
                    switch (menu.GetPressedItem()) {
                    case 0:
                        std::cout << "Play has been pressed" << std::endl;
                        
                        break;
                    case 1:
                        std::cout << "Option has been pressed" << std::endl;
                        
                        break;
                    case 2:
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