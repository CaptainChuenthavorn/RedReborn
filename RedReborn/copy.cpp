////setposition//
//walls.setPosition(0.f, 100.f);
//walls1.setPosition(0.f, 1700.f);
//float deltaTime = 0.0f;
//sf::Clock clock, clock2, clock3, clock4, clock5, clock6, clock7, clock8, clockspeed01, clockspeed02, clockspeed03, clockE, clockE1;
//float speed01 = 1.0f;
//float speed02 = 1.0f;
//float speed03 = 1.0f;
//float speedE = 1.0f;
//float speedE1 = 1.0f;
//float delayShoot = 10.0f;
//float clockDelays;
//int a = 0;
//int e = 0;
//int shoot = 0;
//bool faceRight = true;
//bool check = false;
//int animationFrameBat = 0;
//int animationFrameZombie = 0;
//int animationFrameSpider = 0;
//int animationFrameTrap = 0;
//int animationFrameBird = 0;
//int animationFrameBoss = 0;
//int animationFireBlack = 0;
//int animationCoin = 0;
//int animationCloud = 0;
//
//while (window.isOpen())
//{
//    deltaTime = clock.restart().asSeconds();
//    int time2 = clock3.getElapsedTime().asSeconds();
//    int time = clock2.getElapsedTime().asSeconds();
//    int time3 = clock4.getElapsedTime().asSeconds();
//    int time4 = clock5.getElapsedTime().asSeconds();
//    int timeover = clock6.getElapsedTime().asSeconds();
//    int timeboss = clock7.getElapsedTime().asSeconds();
//    int perth = clock8.getElapsedTime().asSeconds();
//    speed01 = clockspeed01.getElapsedTime().asMilliseconds();
//    speed02 = clockspeed02.getElapsedTime().asMilliseconds();
//    speed03 = clockspeed03.getElapsedTime().asMilliseconds();
//    speedE = clockE.getElapsedTime().asMilliseconds();
//    speedE1 = clockE1.getElapsedTime().asMilliseconds();
//    text2.setString(std::to_string(flame));
//    if (deltaTime > 1.0f / 20.0f)
//    {
//        deltaTime = 1.0f / 20.0f;
//    }
//    sf::Event event;
//    while (window.pollEvent(event))
//    {
//        switch (event.type)
//        {
//        case sf::Event::Closed:
//            window.close();
//            break;
//        case sf::Event::Resized:
//            ResizeView(window, view);
//            break;
//        case sf::Event::KeyReleased:
//            if (sf::Keyboard::P)
//            {
//                a = 0;
//            }
//
//            if (sf::Keyboard::X)
//            {
//                e = 0;
//            }
//
//
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//        {
//            window.close();
//        }
//
//    }
//    int R = rand() % 300;
//    int G = rand() % 300;
//    int B = rand() % 300;
//    sf::RectangleShape HpbarPP;
//    HpbarPP.setFillColor(sf::Color(R, G, B));
//
//    //speed01//
//    if (speed01 == 100)
//    {
//        animationFrameBird = 1;
//
//    }
//    if (speed01 == 300)
//    {
//        animationFrameBird = 0;
//    }
//    if (speed01 >= 400)
//    {
//        clockspeed01.restart();
//    }
//    //speed03//
//    if (speed03 == 290)
//    {
//        animationCloud = 0;
//
//    }
//    if (speed03 == 400)
//    {
//        animationCloud = 1;
//    }
//    if (speed03 >= 500)
//    {
//        animationCloud = 2;
//    }
//    if (speed03 >= 600)
//    {
//        animationCloud = 3;
//    }
//    if (speed03 >= 700)
//    {
//        animationCloud = 4;
//    }
//    if (speed03 >= 800)
//    {
//        animationCloud = 5;
//    }
//    if (speed03 > 800 && speed03 < 900)
//    {
//        Cloud01.setPosition(-10000.f, -10000.f);
//        Cloud02.setPosition(-10000.f, -10000.f);
//    }
//
//    if (time == 0)
//    {
//        animationFrameBat = 5;
//        animationFrameZombie = 1;
//        animationFrameSpider = 1;
//        animationFrameTrap = 1;
//        animationFrameBoss = 1;
//        animationFireBlack = 0;
//        animationCoin = 0;
//
//
//    }
//    if (time == 1)
//    {
//        animationFrameBat = 3;
//        animationFrameZombie = 0;
//        animationFrameSpider = 0;
//        animationFrameTrap = 0;
//        animationFrameBoss = 0;
//        animationFireBlack = 1;
//        animationCoin = 1;
//    }
//
//    if (time >= 2)
//    {
//        clock2.restart();
//    }
//    // sprite animation //
//    Enemy01.setTextureRect(sf::IntRect(spriteSizeX * animationFrameBat, spriteSizeY * 0, spriteSizeX, spriteSizeY));
//    Enemy02.setTextureRect(sf::IntRect(spriteSizeX * animationFrameBat, spriteSizeY * 0, spriteSizeX, spriteSizeY));
//    Enemy03.setTextureRect(sf::IntRect(ZspriteSizeX * animationFrameZombie, ZspriteSizeY * 0, ZspriteSizeX, ZspriteSizeY));
//    Enemy04.setTextureRect(sf::IntRect(ZspriteSizeX * animationFrameZombie, ZspriteSizeY * 0, ZspriteSizeX, ZspriteSizeY));
//    Enemy05.setTextureRect(sf::IntRect(ZspriteSizeX * animationFrameZombie, ZspriteSizeY * 0, ZspriteSizeX, ZspriteSizeY));
//    Enemy06.setTextureRect(sf::IntRect(SspriteSizeX * animationFrameSpider, SspriteSizeY * 0, SspriteSizeX, SspriteSizeY));
//    Enemy07.setTextureRect(sf::IntRect(SspriteSizeX * animationFrameSpider, SspriteSizeY * 0, SspriteSizeX, SspriteSizeY));
//    Enemy08.setTextureRect(sf::IntRect(BspriteSizeX * animationFrameBird, BspriteSizeY * 0, BspriteSizeX, BspriteSizeY));
//    Enemy09.setTextureRect(sf::IntRect(BspriteSizeX * animationFrameBird, BspriteSizeY * 0, BspriteSizeX, BspriteSizeY));
//    Enemy10.setTextureRect(sf::IntRect(BspriteSizeX * animationFrameBird, BspriteSizeY * 0, BspriteSizeX, BspriteSizeY));
//    EnemyB.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    Enemy11.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    Enemy12.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    Enemy13.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    Enemy14.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    Enemy15.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    Enemy16.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    logo1.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    logo2.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//    trap01.setTextureRect(sf::IntRect(TspriteSizeX * animationFrameTrap, TspriteSizeY * 0, TspriteSizeX, TspriteSizeY));
//    trap02.setTextureRect(sf::IntRect(TspriteSizeX * animationFrameTrap, TspriteSizeY * 0, TspriteSizeX, TspriteSizeY));
//    fireblack01.setTextureRect(sf::IntRect(FspriteSizeX * animationFireBlack, FspriteSizeY * 0, FspriteSizeX, FspriteSizeY));
//    fireblack02.setTextureRect(sf::IntRect(FspriteSizeX * animationFireBlack, FspriteSizeY * 0, FspriteSizeX, FspriteSizeY));
//    fireblack03.setTextureRect(sf::IntRect(FspriteSizeX * animationFireBlack, FspriteSizeY * 0, FspriteSizeX, FspriteSizeY));
//    coin01.setTextureRect(sf::IntRect(CspriteSizeX * animationCoin, CspriteSizeY * 0, CspriteSizeX, CspriteSizeY));
//    Cloud01.setTextureRect(sf::IntRect(CCspriteSizeX * animationCloud, CCspriteSizeY * 0, CCspriteSizeX, CCspriteSizeY));
//    Cloud02.setTextureRect(sf::IntRect(CCspriteSizeX * animationCloud, CCspriteSizeY * 0, CCspriteSizeX, CCspriteSizeY));
//
//
//
//
//
//
//
//
//
//    //setposition//
//    walls.setPosition(0.f, 100.f);
//    walls1.setPosition(0.f, 1700.f);
//    float deltaTime = 0.0f;
//    sf::Clock clock, clock2, clock3, clock4, clock5, clock6, clock7, clock8, clockspeed01, clockspeed02, clockspeed03, clockE, clockE1;
//    float speed01 = 1.0f;
//    float speed02 = 1.0f;
//    float speed03 = 1.0f;
//    float speedE = 1.0f;
//    float speedE1 = 1.0f;
//    float delayShoot = 10.0f;
//    float clockDelays;
//    int a = 0;
//    int e = 0;
//    int shoot = 0;
//    bool faceRight = true;
//    bool check = false;
//    int animationFrameBat = 0;
//    int animationFrameZombie = 0;
//    int animationFrameSpider = 0;
//    int animationFrameTrap = 0;
//    int animationFrameBird = 0;
//    int animationFrameBoss = 0;
//    int animationFireBlack = 0;
//    int animationCoin = 0;
//    int animationCloud = 0;
//
//    while (window.isOpen())
//    {
//        deltaTime = clock.restart().asSeconds();
//        int time2 = clock3.getElapsedTime().asSeconds();
//        int time = clock2.getElapsedTime().asSeconds();
//        int time3 = clock4.getElapsedTime().asSeconds();
//        int time4 = clock5.getElapsedTime().asSeconds();
//        int timeover = clock6.getElapsedTime().asSeconds();
//        int timeboss = clock7.getElapsedTime().asSeconds();
//        int perth = clock8.getElapsedTime().asSeconds();
//        speed01 = clockspeed01.getElapsedTime().asMilliseconds();
//        speed02 = clockspeed02.getElapsedTime().asMilliseconds();
//        speed03 = clockspeed03.getElapsedTime().asMilliseconds();
//        speedE = clockE.getElapsedTime().asMilliseconds();
//        speedE1 = clockE1.getElapsedTime().asMilliseconds();
//        text2.setString(std::to_string(flame));
//        if (deltaTime > 1.0f / 20.0f)
//        {
//            deltaTime = 1.0f / 20.0f;
//        }
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            switch (event.type)
//            {
//            case sf::Event::Closed:
//                window.close();
//                break;
//            case sf::Event::Resized:
//                ResizeView(window, view);
//                break;
//            case sf::Event::KeyReleased:
//                if (sf::Keyboard::P)
//                {
//                    a = 0;
//                }
//
//                if (sf::Keyboard::X)
//                {
//                    e = 0;
//                }
//
//
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//            {
//                window.close();
//            }
//
//        }
//        int R = rand() % 300;
//        int G = rand() % 300;
//        int B = rand() % 300;
//        sf::RectangleShape HpbarPP;
//        HpbarPP.setFillColor(sf::Color(R, G, B));
//
//        //speed01//
//        if (speed01 == 100)
//        {
//            animationFrameBird = 1;
//
//        }
//        if (speed01 == 300)
//        {
//            animationFrameBird = 0;
//        }
//        if (speed01 >= 400)
//        {
//            clockspeed01.restart();
//        }
//        //speed03//
//        if (speed03 == 290)
//        {
//            animationCloud = 0;
//
//        }
//        if (speed03 == 400)
//        {
//            animationCloud = 1;
//        }
//        if (speed03 >= 500)
//        {
//            animationCloud = 2;
//        }
//        if (speed03 >= 600)
//        {
//            animationCloud = 3;
//        }
//        if (speed03 >= 700)
//        {
//            animationCloud = 4;
//        }
//        if (speed03 >= 800)
//        {
//            animationCloud = 5;
//        }
//        if (speed03 > 800 && speed03 < 900)
//        {
//            Cloud01.setPosition(-10000.f, -10000.f);
//            Cloud02.setPosition(-10000.f, -10000.f);
//        }
//
//        if (time == 0)
//        {
//            animationFrameBat = 5;
//            animationFrameZombie = 1;
//            animationFrameSpider = 1;
//            animationFrameTrap = 1;
//            animationFrameBoss = 1;
//            animationFireBlack = 0;
//            animationCoin = 0;
//
//
//        }
//        if (time == 1)
//        {
//            animationFrameBat = 3;
//            animationFrameZombie = 0;
//            animationFrameSpider = 0;
//            animationFrameTrap = 0;
//            animationFrameBoss = 0;
//            animationFireBlack = 1;
//            animationCoin = 1;
//        }
//
//        if (time >= 2)
//        {
//            clock2.restart();
//        }
//        // sprite animation //
//        Enemy01.setTextureRect(sf::IntRect(spriteSizeX * animationFrameBat, spriteSizeY * 0, spriteSizeX, spriteSizeY));
//        Enemy02.setTextureRect(sf::IntRect(spriteSizeX * animationFrameBat, spriteSizeY * 0, spriteSizeX, spriteSizeY));
//        Enemy03.setTextureRect(sf::IntRect(ZspriteSizeX * animationFrameZombie, ZspriteSizeY * 0, ZspriteSizeX, ZspriteSizeY));
//        Enemy04.setTextureRect(sf::IntRect(ZspriteSizeX * animationFrameZombie, ZspriteSizeY * 0, ZspriteSizeX, ZspriteSizeY));
//        Enemy05.setTextureRect(sf::IntRect(ZspriteSizeX * animationFrameZombie, ZspriteSizeY * 0, ZspriteSizeX, ZspriteSizeY));
//        Enemy06.setTextureRect(sf::IntRect(SspriteSizeX * animationFrameSpider, SspriteSizeY * 0, SspriteSizeX, SspriteSizeY));
//        Enemy07.setTextureRect(sf::IntRect(SspriteSizeX * animationFrameSpider, SspriteSizeY * 0, SspriteSizeX, SspriteSizeY));
//        Enemy08.setTextureRect(sf::IntRect(BspriteSizeX * animationFrameBird, BspriteSizeY * 0, BspriteSizeX, BspriteSizeY));
//        Enemy09.setTextureRect(sf::IntRect(BspriteSizeX * animationFrameBird, BspriteSizeY * 0, BspriteSizeX, BspriteSizeY));
//        Enemy10.setTextureRect(sf::IntRect(BspriteSizeX * animationFrameBird, BspriteSizeY * 0, BspriteSizeX, BspriteSizeY));
//        EnemyB.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        Enemy11.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        Enemy12.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        Enemy13.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        Enemy14.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        Enemy15.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        Enemy16.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        logo1.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        logo2.setTextureRect(sf::IntRect(OspriteSizeX * animationFrameZombie, OspriteSizeY * 0, OspriteSizeX, OspriteSizeY));
//        trap01.setTextureRect(sf::IntRect(TspriteSizeX * animationFrameTrap, TspriteSizeY * 0, TspriteSizeX, TspriteSizeY));
//        trap02.setTextureRect(sf::IntRect(TspriteSizeX * animationFrameTrap, TspriteSizeY * 0, TspriteSizeX, TspriteSizeY));
//        fireblack01.setTextureRect(sf::IntRect(FspriteSizeX * animationFireBlack, FspriteSizeY * 0, FspriteSizeX, FspriteSizeY));
//        fireblack02.setTextureRect(sf::IntRect(FspriteSizeX * animationFireBlack, FspriteSizeY * 0, FspriteSizeX, FspriteSizeY));
//        fireblack03.setTextureRect(sf::IntRect(FspriteSizeX * animationFireBlack, FspriteSizeY * 0, FspriteSizeX, FspriteSizeY));
//        coin01.setTextureRect(sf::IntRect(CspriteSizeX * animationCoin, CspriteSizeY * 0, CspriteSizeX, CspriteSizeY));
//        Cloud01.setTextureRect(sf::IntRect(CCspriteSizeX * animationCloud, CCspriteSizeY * 0, CCspriteSizeX, CCspriteSizeY));
//        Cloud02.setTextureRect(sf::IntRect(CCspriteSizeX * animationCloud, CCspriteSizeY * 0, CCspriteSizeX, CCspriteSizeY));
//
//
//
//
//
//
//
//
//
//        // Enemy 01//
//
//        if (hitboxLeft.getGlobalbounds().intersects(Enemy01.getGlobalBounds()))
//        {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
//            {
//                a++;
//                if (a == 1)
//                {
//                    soundrun.play();
//                    std::cout << "HIT" << std::endl;
//                    hp1--;
//                    score++;
//
//                    Enemy01.move(-50, 0);
//                    if (hp1 < 1)
//                    {
//                        E = 1;
//                        if (E == 1)
//                        {
//                            clockE.restart();
//                            E += 1;
//                        }
//                        if (E == 2)
//                        {
//                            if (speedE >= 100 && speedE <= 500)
//                            {
//                                clockspeed03.restart();
//                                Enemy01.setColor(sf::Color::Transparent);
//                                Cloud01.setPosition(sf::Vector2f(Enemy01.getPosition().x, Enemy01.getPosition().y));
//                                clockE1.restart();
//                                if (speedE1 >= 0 && speedE1 <= 10000)
//                                {
//                                    Enemy01.setPosition(-10000.f, -10000.f);
//
//                                }
//                            }
//
//                        }
//
//                        flame += 10;
//                    }
//
//
//                }
//            }
//        }
//        if (hitboxRight.getGlobalbounds().intersects(Enemy01.getGlobalBounds()))
//        {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
//            {
//                a++;
//                if (a == 1)
//                {
//                    soundrun.play();
//                    std::cout << "HIT" << std::endl;
//                    hp1--;
//                    score++;
//                    Enemy01.move(50, 0);
//                    if (hp1 < 1)
//                    {
//                        E = 1;
//                        if (E == 1)
//                        {
//                            clockE.restart();
//                            E += 1;
//                        }
//                        if (E == 2)
//                        {
//                            if (speedE >= 100 && speedE <= 500)
//                            {
//                                clockspeed03.restart();
//                                Enemy01.setColor(sf::Color::Transparent);
//                                Cloud01.setPosition(sf::Vector2f(Enemy01.getPosition().x, Enemy01.getPosition().y));
//                                clockE1.restart();
//                                if (speedE1 >= 0 && speedE1 <= 10000)
//                                {
//                                    Enemy01.setPosition(-10000.f, -10000.f);
//
//                                }
//                            }
//
//                        }
//
//                        flame += 10;
//                    }
//
//
//                }
//            }
//        }
//
//        // Enemy 02//
//
//        if (hitboxLeft.getGlobalbounds().intersects(Enemy02.getGlobalBounds()))
//        {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
//            {
//                a++;
//
//                if (a == 1)
//                {
//
//                    soundrun.play();
//                    std::cout << "HIT" << std::endl;
//                    hp2--;
//                    score++;
//                    Enemy02.move(-50, 0);
//                    if (hp2 < 1)
//                    {
//                        E = 1;
//                        if (E == 1)
//                        {
//                            clockE.restart();
//                            E += 1;
//                        }
//                        if (E == 2)
//                        {
//                            if (speedE >= 100 && speedE <= 500)
//                            {
//                                clockspeed03.restart();
//                                Enemy02.setColor(sf::Color::Transparent);
//                                Cloud02.setPosition(sf::Vector2f(Enemy02.getPosition().x, Enemy02.getPosition().y));
//                                clockE1.restart();
//                                if (speedE1 >= 0 && speedE1 <= 10000)
//                                {
//                                    Enemy02.setPosition(-10000.f, -10000.f);
//
//                                }
//                            }
//
//                        }
//
//                        flame += 10;
//                    }
//
//
//                }
//            }
//        }
//
//        if (hitboxRight.getGlobalbounds().intersects(Enemy02.getGlobalBounds()))
//        {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
//            {
//                a++;
//
//                if (a == 1)
//                {
//
//                    soundrun.play();
//                    std::cout << "HIT" << std::endl;
//                    hp2--;
//                    score++;
//                    Enemy02.move(50, 0);
//                    if (hp2 < 1)
//                    {
//                        E = 1;
//                        if (E == 1)
//                        {
//                            clockE.restart();
//                            E += 1;
//                        }
//                        if (E == 2)
//                        {
//                            speedE >= 100 && speedE <= 500
//
//                        }
//
//                        flame += 10;
//                    }
//
//
//                }
//            }
//        }