﻿#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
//#include "C:\RedReborn\RedReborn\animation.h"
//#include "C:\RedReborn\RedReborn\Player.h"
//#include "C:\RedReborn\RedReborn\Platform.h"
//#include "C:\RedReborn\RedReborn\enemy.h"
//#include "C:\RedReborn\RedReborn\hitbox.h"
//#include "C:\RedReborn\RedReborn\Bullet.h"
//#include "C:\RedReborn\RedReborn\Item.h"
//#include "C:\RedReborn\RedReborn\Background.h"
//#include "C:\RedReborn\RedReborn\Menu.h"
//#include "C:\RedReborn\RedReborn\Bitmap.h"
//#include "C:\RedReborn\RedReborn\Flag.h"
//#include "C:\RedReborn\RedReborn\RestartMenu.h"
#include "animation.h"
#include "Player.h"
#include "Platform.h"
#include "enemy.h"
#include "hitbox.h"
#include "Bullet.h"
#include "Item.h"
#include "Background.h"
#include "Menu.h"
#include "Bitmap.h"
#include "Flag.h"
#include "RestartMenu.h"
#include "Boss.h"
#include "enemyDeath.h"
#include "animationEnemyDeath.h"
static const float VIEW_HEIGHT = 720.0f;
static const float VIEW_WIDTH = 1080.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	////////// Endgame status //////////
	int pokeball = 0;
	int flower = 0;


	////////// State Count //////////
	int state = 5;

	////////// Render Window //////////
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Adventure", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

	////////// Player //////////
	sf::Texture texture;
	if (!texture.loadFromFile("asset/BGMenu.JPG")) {
		//handle error
	}

	sf::Sprite background;
	background.setTexture(texture);


	///////////////////////////////////////Item/////////////////////////////////
	/********************************** Chest ********************************/
	std::vector<Item> chest;
	sf::Texture chest_texture;
	if (!chest_texture.loadFromFile("asset/object/ChestRed.png"))
	{

	}
	sf::Clock chestTime;
	float chestT = 0.0f; //เป็นตัวเก็บค่า เวลาของ bullet
	sf::Clock spawnItem;
	float spawnItemf = 0.0f;

	srand(time(NULL));
	int ranChestX = rand() % 1000;
	int ranChestY = rand() % 620;
	float ranChestx = ranChestX / 10.f;
	float ranChesty = ranChestY / 10.f;

	//printf("chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
	chest.push_back(Item(&chest_texture, sf::Vector2f(rand() % 2000 + 1000, rand() % 300 + 300), sf::Vector2f(0, 1)));



	/**********************************Player Heart********************************/
	//sf::RectangleShape heartPlayer;
	sf::Sprite heartPlayer1;
	sf::Texture heartplayerTexture;
	if (!heartplayerTexture.loadFromFile("asset/object/HeartRed.png"));
	heartPlayer1.setScale(5.0f, 5.0f);
	heartPlayer1.setTexture(heartplayerTexture);

	sf::Sprite heartPlayer2;
	heartPlayer2.setScale(5.0f, 5.0f);
	heartPlayer2.setTexture(heartplayerTexture);

	sf::Sprite heartPlayer3;

	heartPlayer3.setScale(5.0f, 5.0f);
	heartPlayer3.setTexture(heartplayerTexture);
	/**********************************Health Potion********************************/

	/*sf::Sprite hpPotion;
	sf::Texture hpPotionTexture;
	if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
	hpPotion.setScale(3.0f, 3.0f);
	hpPotion.setTexture(hpPotionTexture);*/


	/**********************************Health Potion Vector********************************/
	std::vector<Item> hpPotion;
	sf::Texture hpPotionTexture;
	if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
	sf::Clock hpPotionTime;
	float potionT = 0.0f; //เป็นตัวเก็บค่า เวลาของ bullet
	/*sf::Clock spawnItem;
	float spawnItemf = 0.0f;

	srand(time(NULL));*/
	int ranhpPotionX = rand() % 1000;
	int ranhpPotionY = rand() % 620;
	float ranhpPotionx = ranhpPotionX / 10.f;
	float ranhpPotiony = ranhpPotionY / 10.f;

	//printf("potion spawn at x: %f y : %f\n", ranhpPotionx, ranhpPotionY);
	//hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1050, rand() % 300 + 310), sf::Vector2f(0, 1)));
	hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1100, rand() % 300 + 305), sf::Vector2f(0, 1)));
	/**************************************************************************************/
	//heartPlayer.setSize(sf::Vector2f(100,100)); 
	//srand(time(NULL));
	int ranHeartPotionX = rand() % 1000;
	int ranHeartPotionY = rand() % 620;
	float ranHpX = ranHeartPotionX / 10.f;
	float ranHpY = ranHeartPotionY / 10.f;

	//////////////////////////score////////////////////
	int scoreCount = 0;
	sf::Font font;
	if (font.loadFromFile("asset/FSEX300.ttf")) {}
	sf::Text scoreText;
	sf::Text scoreString;
	//////////////////////////stamina////////////////////

	sf::Text staminaText;
	sf::Text staminaString;
	sf::RectangleShape staminaBar;
	////////////////////////////////////////////////
	//sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Adventure", sf::Style::Close | sf::Style::Resize);
	//////////////////////////enemies//////////////////////////
	sf::Clock spawnTime;
	float spawnT = 0.0f;
	sf::Texture enemyBlack;
	sf::Texture enemyGrey;
	sf::Texture enemyGolden;

	//////////////////////////////////////bullet declare//////////////////////////
	std::vector<Bullet> bullet;
	sf::Texture bullet_texture;
	if (!bullet_texture.loadFromFile("asset/Adventurer-Bow/Individual Sprites/adventurer-bow-00.png"))
	{

	}
	sf::Clock bullTime;
	float bull = 0.0f; //เป็นตัวเก็บค่า เวลาของ bullet
	//////////////////////////////////////////////////////////////////////

	sf::RectangleShape bound;
	bound.setSize(sf::Vector2f(100.0, 74.0));
	bound.setOrigin(bound.getSize() / 2.0f);
	bound.setPosition(350.0f, 250.0f);
	bound.setFillColor(sf::Color::Red);

	sf::RectangleShape boundE;
	boundE.setSize(sf::Vector2f(100.0, 74.0));
	boundE.setOrigin(boundE.getSize() / 2.0f);
	boundE.setPosition(350.0f, 250.0f);
	boundE.setFillColor(sf::Color::Green);

	sf::Texture bgTexture[4];
	bgTexture[0].loadFromFile("asset/CloudsBack.png");
	bgTexture[1].loadFromFile("asset/CloudsFront.png");
	bgTexture[2].loadFromFile("asset/BGBack.png");
	bgTexture[3].loadFromFile("asset/BGFront.png");



	std::vector<Background> backgrounds;
	backgrounds.push_back(Background(&bgTexture[0], -5.f));
	backgrounds.push_back(Background(&bgTexture[1], -10.f));
	backgrounds.push_back(Background(&bgTexture[2], -15.f));
	backgrounds.push_back(Background(&bgTexture[3], -20.f));



	sf::Texture playerTexture;
	//playerTexture.loadFromFile("asset/Adventurer/Individual Sprites/adventurer-idle-00.PNG");
	//playerTexture.loadFromFile("asset/v2.1/adventurer-1.3-Sheet.PNG");
	playerTexture.loadFromFile("asset/adventurer-Sheet1.png");
	//playerTexture.loadFromFile("WALK_RUN_RedStroke.PNG");
	Player player(&playerTexture, sf::Vector2u(8, 12), 0.1f, 100.0f, 100.0f);

	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("asset/16x16 knight 4 v3.PNG");
	enemy enemy1(&enemyTexture, sf::Vector2u(8, 8), 0.2f, 100.0f, 500.0f, 500.0f);


	//load enemy texture//
	enemyBlack.loadFromFile("asset/enemy/black.PNG");//16x16 knight 3 v3

	enemyGolden.loadFromFile("asset/enemy/16x16 knight 1 v3.PNG");

	enemyGrey.loadFromFile("asset/enemy/16x16 knight 2 v3.PNG");

	//initialize platform
	std::vector<Platform> platforms;
	//Ground && platform
	///*platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(1000.0f, 400.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(800.0f, 525.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(100.0f, 625.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 1000.0f), sf::Vector2f(-100.0f, 200.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 150.0f), sf::Vector2f(50.0f, 300.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(1500.0f, 575.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 75.0f), sf::Vector2f(1400.0f, 375.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 200.0f), sf::Vector2f(500.0f, 775.0f)));*/

	int ammo = 5;

	//hitbox//  sf::Vector2f(44.0f + 28.0f, 58.0f)
	hitbox
		hitboxMid(0, 0, sf::Vector2f(22, player.GetSize().y), player.GetPosition());
	hitbox
		hitboxLeft(-28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());
	hitbox
		hitboxRight(+28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());

	hitbox
		hitboxEnemy(0, 0, sf::Vector2f(30, 48), enemy1.GetPosition());

	//attack
	int cooldown = 0;

	//enemy.GetSize().y = 48


	float deltaTime = 0.0f;
	sf::Clock clockW;



	////////// state obj //////////
	bool check_state2 = false;
	//////////    Manu State    //////////
	Menu menu(window.getSize().x, window.getSize().y);
	bool checkGameOpen = false;
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::KeyReleased:
				switch (evnt.key.code) {
				case sf::Keyboard::W:
					menu.MoveUp();
					break;
				case sf::Keyboard::S:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem()) {
					case 0:
						std::cout << "Play has been preesed" << std::endl;
						state = 2;
						checkGameOpen = true;
						break;
					case 1:
						std::cout << "Leaderboard has been preesed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}
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
		if (checkGameOpen == true)
			break;
	}
	
	bool checkRestart = false;
	bool restartGame = false;
	
	
	while(1)
	{
	jumperState:
		//status state
		//bool boxstate2_1 = false;

		printf("We are in loop while (1)\n");
		//state 1//
		if (state == 1)
		{

			printf("We are in state == 1 \n");
			/////////////////////////Render window ////////////////
			//sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Adventure", sf::Style::Close | sf::Style::Resize);
			///////////////////////////////////////Item/////////////////////////////////
			
			/********************************** Flag ********************************/
			std::vector<Flag> flag;
			sf::Texture flag_texture;
			if (!flag_texture.loadFromFile("asset/flag.png")) {}
		
			flag.push_back(Flag(&flag_texture, sf::Vector2f(6183, 200), sf::Vector2f(0, 1)));
			/********************************** Chest ********************************/
			std::vector<Item> chest;
			sf::Texture chest_texture;
			if (!chest_texture.loadFromFile("asset/object/ChestRed.png"))
			{}
			sf::Clock chestTime;
			float chestT = 0.0f; //?????????????? ??????? bullet
			sf::Clock spawnItem;
			float spawnItemf = 0.0f;

			srand(time(NULL));
			int ranChestX = rand() % 1000;
			int ranChestY = rand() % 620;
			float ranChestx = ranChestX / 10.f;
			float ranChesty = ranChestY / 10.f;

			//printf("chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
			chest.push_back(Item(&chest_texture, sf::Vector2f(rand() % 2000 + 1000, rand() % 300 + 300), sf::Vector2f(0, 1)));



			/**********************************Player Heart********************************/
			//sf::RectangleShape heartPlayer;
			sf::Sprite heartPlayer1;
			sf::Texture heartplayerTexture;
			if (!heartplayerTexture.loadFromFile("asset/object/HeartRed.png"));
			heartPlayer1.setScale(5.0f, 5.0f);
			heartPlayer1.setTexture(heartplayerTexture);

			sf::Sprite heartPlayer2;
			heartPlayer2.setScale(5.0f, 5.0f);
			heartPlayer2.setTexture(heartplayerTexture);

			sf::Sprite heartPlayer3;

			heartPlayer3.setScale(5.0f, 5.0f);
			heartPlayer3.setTexture(heartplayerTexture);
	
			
			/**********************************Health Potion********************************/


			/*sf::Sprite hpPotion;
			sf::Texture hpPotionTexture;
			if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
			hpPotion.setScale(3.0f, 3.0f);
			hpPotion.setTexture(hpPotionTexture);*/


			/**********************************Health Potion Vector********************************/
			std::vector<Item> hpPotion;
			sf::Texture hpPotionTexture;
			if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
			//sf::Clock hpPotionTime;
			//float potionT = 0.0f; //?????????????? ??????? bullet
			//
			//int potionSpawn=0 ; // 0 = can't create ???????? ,1= ready to create , 2= create ????
			//
			sf::Clock Clockspawn;
			float itemCooldown = 0;

			int ranhpPotionX = rand() % 2880;
			int ranhpPotionY = rand() % 620;
			float ranhpPotionx = ranhpPotionX / 10.f;
			float ranhpPotiony = ranhpPotionY / 10.f;

			//printf("potion spawn at x: %f y : %f\n", ranhpPotionx, ranhpPotionY);
			//hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1050, rand() % 300 + 310), sf::Vector2f(0, 1)));
			//hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1100, rand() % 300 + 305), sf::Vector2f(0, 1)));
			hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(ranhpPotionX, ranhpPotionY), sf::Vector2f(0, 1)));
			/**************************************************************************************/
			//heartPlayer.setSize(sf::Vector2f(100,100)); 
			//srand(time(NULL));
			int ranHeartPotionX = rand() % 1000;
			int ranHeartPotionY = rand() % 620;
			float ranHpX = ranHeartPotionX / 10.f;
			float ranHpY = ranHeartPotionY / 10.f;

			//////////////////////////score////////////////////
			//int scoreCount = 0;
			sf::Font font;
			if (font.loadFromFile("asset/FSEX300.ttf")) {}
			sf::Text scoreText;
			sf::Text scoreString;
			//////////////////////////stamina////////////////////

			sf::Text staminaText;
			sf::Text staminaString;
			sf::RectangleShape staminaBar;
			
			//End Game Restart//
			sf::Text Youdie;
			sf::Text Restart;
			//////////////////////////enemies//////////////////////////
			sf::Clock spawnTime;
			float spawnT = 0.0f;
		
			sf::Texture enemyBlack;
			sf::Texture enemyGrey;
			sf::Texture enemyGolden;
			
			//////////////////////////////////////bullet declare//////////////////////////
			std::vector<Bullet> bullet;
			sf::Texture bullet_texture;
			if (!bullet_texture.loadFromFile("asset/arrow2.png"))
			{

			}
			sf::Clock bullTime;
			float bull = 0.0f; //?????????????? ??????? bullet

			//int ammo = 5;
			sf::Text BulletX;
			sf::Text BulletCount;
			sf::Sprite ammo1;
			sf::Texture ammoTexture;
			if (!ammoTexture.loadFromFile("asset/bullet.png"));
			ammo1.setScale(0.15f, 0.15f);
			ammo1.setTexture(ammoTexture);

			//////////////////////////////////////////////////////////////////////

			sf::RectangleShape bound;
			bound.setSize(sf::Vector2f(100.0, 74.0));
			bound.setOrigin(bound.getSize() / 2.0f);
			bound.setPosition(350.0f, 250.0f);
			bound.setFillColor(sf::Color::Red);

			sf::RectangleShape boundE;
			boundE.setSize(sf::Vector2f(100.0, 74.0));
			boundE.setOrigin(boundE.getSize() / 2.0f);
			boundE.setPosition(350.0f, 250.0f);
			boundE.setFillColor(sf::Color::Green);

			sf::Texture bgTexture[4];
			bgTexture[0].loadFromFile("asset/CloudsBack.png");
			bgTexture[1].loadFromFile("asset/CloudsFront.png");
			bgTexture[2].loadFromFile("asset/BGBack.png");
			bgTexture[3].loadFromFile("asset/BGFront.png");


			std::vector<Background> backgrounds;
			backgrounds.push_back(Background(&bgTexture[0], -5.f));
			backgrounds.push_back(Background(&bgTexture[1], -10.f));
			backgrounds.push_back(Background(&bgTexture[2], -15.f));
			backgrounds.push_back(Background(&bgTexture[3], -20.f));

			sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

			sf::Texture playerTexture;
			//playerTexture.loadFromFile("asset/Adventurer/Individual Sprites/adventurer-idle-00.PNG");
			//playerTexture.loadFromFile("asset/v2.1/adventurer-1.3-Sheet.PNG");
			playerTexture.loadFromFile("asset/adventurer-Sheet1.png");
			//playerTexture.loadFromFile("WALK_RUN_RedStroke.PNG");
			Player player(&playerTexture, sf::Vector2u(8, 12), 0.1f, 100.0f, 100.0f);

			sf::Texture enemyTexture;
			enemyTexture.loadFromFile("asset/16x16 knight 4 v3.PNG");
			enemy enemy1(&enemyTexture, sf::Vector2u(8, 8), 0.2f, 100.0f, 500.0f, 500.0f);
			sf::Texture BlackEnemy;
			sf::Texture KnightEnemy;
			sf::Texture GreyEnemy;
			sf::Texture GoldenEnemy;
			//load enemy texture//
			enemyBlack.loadFromFile("asset/enemy/black.PNG");//16x16 knight 3 v3

			enemyGolden.loadFromFile("asset/enemy/16x16 knight 1 v3.PNG");

			enemyGrey.loadFromFile("asset/enemy/16x16 knight 2 v3.PNG");

			//initialize platform
			std::vector<Platform> platforms;
			//Ground && platform
		////	/*platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(1000.0f, 400.0f)));
		////	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(800.0f, 525.0f)));
		////	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(100.0f, 625.0f)));
		////	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 1000.0f), sf::Vector2f(-100.0f, 200.0f)));
		////	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 150.0f), sf::Vector2f(50.0f, 300.0f)));
		////	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(1500.0f, 575.0f)));
		////	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 75.0f), sf::Vector2f(1400.0f, 375.0f)));
		////	platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 200.0f), sf::Vector2f(500.0f, 775.0f)));
		////*/



			//Background
			sf::Texture backgroundState5Texture;
			backgroundState5Texture.loadFromFile("asset/tilemap512.png");
			Platform Background1(&backgroundState5Texture, sf::Vector2f(960 * 48 / 16, 512 * 48 / 16), sf::Vector2f(960 * 48 / 32, 512 * 48 / 32));
			// BitMap Init
			std::vector<Bitmap> block0;
			int outdoor[32][60] = {
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},

			};
			// DrawBitMap
			for (int mapX = 0; mapX < 60; mapX++)
			{
				for (int mapY = 0; mapY < 32; mapY++)
				{
					if (outdoor[mapY][mapX] == 1)
					{
						Bitmap outdoor(nullptr, sf::Vector2f(((mapX) * 48) + 24, ((mapY) * 48) + 24), sf::Vector2f(48.f, 48.f));
						block0.push_back(outdoor);
					}
				}
			}
			//hitbox//  sf::Vector2f(44.0f + 28.0f, 58.0f)
			hitbox
				hitboxMid(0, 0, sf::Vector2f(22, player.GetSize().y), player.GetPosition());
			hitbox
				hitboxLeft(-28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());
			hitbox
				hitboxRight(+28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());

			hitbox
				hitboxEnemy(0, 0, sf::Vector2f(30, 48), enemy1.GetPosition());

			//attack
			int cooldown = 0;

			


			float deltaTime = 0.0f;
			sf::Clock clockW;


			while (window.isOpen()) {
				deltaTime = clockW.restart().asSeconds();
				if (deltaTime > 1.0f / 60.0f)
					deltaTime = 1.0f / 60.0f;
				sf::Event evnt;
				while (window.pollEvent(evnt))
				{
					switch (evnt.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::Resized:
						ResizeView(window, view);

						break;

					}
				}
				bull = bullTime.getElapsedTime().asMilliseconds();
				if (ammo > 0) {
					if (bull > 800)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
						{
							player.velocity.x = 0;
							player.shootState = 1;
							player.animation.finishShoot == false;
							player.animation.shoot = true;
							player.start = clock();
							ammo--;
							if (player.faceRight == true)
							{
								bullet.push_back(Bullet(&bullet_texture, sf::Vector2u(1, 1), 0/*imageCOunt*/, sf::Vector2f(player.GetPosition().x + 10/* +10 ??????????????????????????????*/, player.GetPosition().y), sf::Vector2f(500, 0)));
								bullTime.restart();
							}
							else if (player.faceRight == false)
							{
								bullet.push_back(Bullet(&bullet_texture, sf::Vector2u(1, 1), 0/*imageCOunt*/, sf::Vector2f(player.GetPosition().x - 10/* +10 ??????????????????????????????*/, player.GetPosition().y), sf::Vector2f(-500, 0)));
								bullTime.restart();
							}

						}
					}
				}

				for (Bullet& bullet : bullet) {
					//printf("Update!\n");
					bullet.Update(deltaTime);
				}
				if (player.attackState > 0)
				{
					if (player.attackState == 1)
					{
						if (hitboxMid.getGlobalbounds().intersects(enemy1.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									//scoreCount += 10;
									enemy1.hp--;
									printf(" Hit Sword enemy hp : %d  \n", enemy1.hp);

									if (enemy1.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}
					}
					double dif = (double)(player.end - player.start) / CLOCKS_PER_SEC; // ??????????????? //0.6  0.4  0.4

					if (dif > 0.6f)//??????? ??????? k ??????
					{
						cooldown = 0;
						player.shootState = 0;

					}
					else if (dif > 0.4f)//??????????????
					{
						player.animation.shoot = false;
						player.shootState = 2;

					}

					else if (dif <= 0.4f)
					{
						//printf("%lf    ", dif);

						// std::cout << "Cooldown" << std::endl;
					}

				}
				//printf("   hp : %d   ", player.hpPlayer);
					//////////////////////////////////////////////////Item in loop//////////////////////////////////////////

					//////////////////////////////////////////Chest Item///////////////////////////////////////////////////////////

				chestT = chestTime.getElapsedTime().asMilliseconds();
				for (Item& chest : chest) {
					//printf("Update!\n");
					chest.Update(deltaTime);
				}

				Collider tempChest = player.GetColliderHitbox();
				for (Item& chest : chest)
				{
					if (chest.GetCollider().CheckCollisionAttack(tempChest)) {

						chest.setDestroy(true);
						printf(" Hit the chest !!\n");
						ammo += rand() % 3 + 3;
						//float ranChestX = rand() % 2000 + 1000;
						//float ranChestY = rand() % 300 + 300;
						player.immortalTime = 10.0f;
						chest.setSpawn(true);
						player.immortal = true;
						spawnItemf = spawnItem.getElapsedTime().asSeconds();
						player.imCl.restart();

					}
				}
				//printf("%f\nd", spawnItemf);

				/*if (spawnItemf > 10.0f)
				{*/
				for (int i = 0;i < chest.size();i++)
				{
					if (chest[i].isSpawn())
					{
						printf("New chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
						//				chest.push_back(Item(&chest_texture, sf::Vector2f(ranChestX, ranChestY), sf::Vector2f(0, 0)));

						chest.push_back(Item(&chest_texture, sf::Vector2f(rand() % 2000 + 1000, rand() % 300 + 300), sf::Vector2f(0, 0)));
						spawnItem.restart();
						spawnItemf = 0.0f;
						chest[i].setSpawn(false);
					}

					//	}
				}
				//printf("player immortal : %s\n", player.immortal ? "true  " : "false");


				//printf("%f\n", chestT);
				for (int i = 0;i < chest.size();i++)
				{
					if (chest[i].isDestroy())
					{
						chest.erase(chest.begin() + i);
					}

				}
				/////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////Hp potion Item///////////////////////////////////////////////////////////
				sf::Time time = Clockspawn.getElapsedTime();
				Clockspawn.restart();


				for (Item& hpPotion : hpPotion) {
					//printf("Update!\n");
					hpPotion.Update(deltaTime);
				}

				Collider tempPotion = player.GetColliderHitbox();
				for (Item& hpPotion : hpPotion)
				{
					if (hpPotion.GetCollider().CheckCollisionAttack(tempPotion)) {

						hpPotion.setDestroy(true);
						printf(" Hit the Potion !!\n");
						hpPotion.setSpawn(true);
						//potionSpawn = 1;
						if (player.hpPlayer < 3)
						{
							int randompotion;
							randompotion = rand() % 2 + 1;
							if (player.hpPlayer == 2)
							{
								randompotion = 1;
							}
							player.hpPlayer += randompotion;
						}
						printf("hp player %d ", player.hpPlayer);
					}
				}

				std::cout << itemCooldown << std::endl;
				if (itemCooldown > 5)
				{

					for (int i = 0;i < hpPotion.size();i++)
					{
						if (hpPotion[i].isSpawn())
						{

							printf("New hpPotion spawn at \n");
							//chest.push_back(Item(&chest_texture, sf::Vector2f(ranChestX, ranChestY), sf::Vector2f(0, 0)));

							hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1100, rand() % 300 + 305), sf::Vector2f(0, 0)));
							//hpPotionTime.restart();
							//potionT = 0.0f;
							//potionSpawn = 2;
							hpPotion[i].setSpawn(false);
							itemCooldown = 0;

						}
					}

				}
				//printf("%f\n", chestT);
				for (int i = 0;i < hpPotion.size();i++)
				{
					if (hpPotion[i].isDestroy())
					{
						hpPotion.erase(hpPotion.begin() + i);
					}

				}

				////////////////////////////////////////Flag collision action////////////////////////////////////////////
				for (Flag& flag : flag) {
					//printf("Update!\n");
					flag.Update(deltaTime);
				}

				Collider tempFlag = player.GetColliderHitbox();
				for (Flag& flag : flag)
				{
					if (flag.GetCollider().CheckCollisionAttack(tempFlag)) {

						flag.setDestroy(true);
						printf(" Hit the flag !!\n");
						state = 2;
						goto jumperState;
					}
				}

				//restart//
				if (player.hpPlayer <= 0)
				{
					state = 66;
					goto jumperState;

				}
				/////////////////////////////////////////////////score Update////////////////////////////////////////////////

				scoreText.setPosition(player.GetPosition().x - 300, player.GetPosition().y - 300);
				scoreText.setFillColor(sf::Color::Red);
				scoreText.setFont(font);
				scoreText.setString(std::to_string(scoreCount));
				scoreText.setOutlineThickness(5.f);
				scoreText.setOutlineColor(sf::Color::White);
				scoreString.setPosition(scoreText.getPosition().x - 120, scoreText.getPosition().y - 1);
				scoreString.setFillColor(sf::Color::Red);
				scoreString.setFont(font);
				scoreString.setString("Score : ");
				scoreString.setOutlineThickness(5.f);
				scoreString.setOutlineColor(sf::Color::White);
				//////////////////////////////////////////////////////////////////////////////////////////////////////

				/////////////////////////////////////////////////score Update////////////////////////////////////////////////
				float staminaCount = (player.stamina / 1500.0) * 100;
				staminaBar.setSize(sf::Vector2f(staminaCount, 15));
				staminaBar.setPosition(player.GetPosition().x + 380, player.GetPosition().y - 310);
				staminaBar.setFillColor(sf::Color::Red);
				staminaBar.setOutlineThickness(5.f);
				staminaBar.setOutlineColor(sf::Color::Yellow);
				staminaString.setPosition(staminaBar.getPosition().x - 150, staminaBar.getPosition().y - 15);
				staminaString.setFillColor(sf::Color::Red);
				staminaString.setFont(font);
				staminaString.setString("Stamina : ");
				staminaString.setOutlineThickness(5.f);
				staminaString.setOutlineColor(sf::Color::Yellow);

				////////////////////////////////////////////////Bullet string/////////////////////////////////////////////
				BulletCount.setPosition(player.GetPosition().x + 450, player.GetPosition().y - 200);
				BulletCount.setFillColor(sf::Color::Red);
				BulletCount.setOutlineThickness(5.f);
				BulletCount.setOutlineColor(sf::Color::Yellow);
				BulletCount.setFont(font);
				BulletCount.setString(std::to_string(ammo));

				//////////////////////////////////////////////////////Heart player////////////////////////////////////////////////////// 
				heartPlayer1.setPosition(player.GetPosition().x - 100, player.GetPosition().y - 300);
				heartPlayer2.setPosition(player.GetPosition().x - 70, player.GetPosition().y - 300);
				heartPlayer3.setPosition(player.GetPosition().x - 40, player.GetPosition().y - 300);

				/////////////////////////////////////////////////////ammo player////////////////////////////////////////////////////// 
				ammo1.setPosition(player.GetPosition().x + 400, player.GetPosition().y - 200);


				/////////////////////////////////////////player && enemy Update && hitboxupdate/////////////////////////////////////////
				sf::Vector2f direction;
				player.Update(deltaTime);
				enemy1.Update(deltaTime);

				hitboxMid.Update(0, 0, player.GetPosition());
				hitboxLeft.Update(-28, 0, player.GetPosition());
				hitboxRight.Update(+28, 0, player.GetPosition());
				hitboxEnemy.Update(0, 0, enemy1.GetPosition());







				//COLLISION BULLET WITH ENEMY01//
				Collider temp = enemy1.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp)) {

						//printf("Bullet Destroy!!\n");
						bullet.setDestroy(true);
						enemy1.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", enemy1.hp);

					}
				}
				if (enemy1.GetHp() <= 0)
				{
					enemy1.setDie(true);

				}
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}

				if (enemy1.isDie() == true)
				{

					//srand(time(NULL));
					int ranPx = rand() % 10000;
					int ranPy = rand() % 6200;
					float ranPxf = ranPx / 10.f;
					float ranPyf = ranPy / 10.f;
					scoreCount += 100;
					spawnT = spawnTime.getElapsedTime().asMilliseconds();
					//	std::cout << spawnT << std::endl;
					if (spawnT > 2000.0)
					{
						printf("Enemy spwan!!\n");
						enemy1.hp = 5;
						enemy1.SetPosition(sf::Vector2f(rand() % 1000, rand() % 620));
						spawnTime.restart();
						enemy1.setDie(false);

					}
				}




				////////////////////////////////////////////////player collider with platform////////////////////////////////////////////////
				//BitMap Collision
			/*	Collider playerCollision = player.GetCollider();
				for (int i = 0; i < block0.size(); i++)
					block0[i].getCollider().CheckCollision(playerCollision, direction, 1.0f);*/

					////BitMap Collision WITH PLAYER ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						player.OnCollision(direction);

				////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy1.GetCollider(), direction, 1.0f))
						enemy1.OncollisionEnemy(direction);

				////BitMap Collision WITH CHEST ////
				for (Bitmap& block0 : block0)
				{
					for (Item& chest : chest)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(chest.GetCollider(), direction, 1.0f))
							chest.OnCollision(direction);
				}

				////BitMap Collision WITH HP POTION ////
				for (Bitmap& block0 : block0)
				{
					for (Item& hpPotion : hpPotion)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(hpPotion.GetCollider(), direction, 1.0f))
							hpPotion.OnCollision(direction);
				}
				////BitMap Collision WITH FLAG ////
				for (Bitmap& block0 : block0)
				{
					for (Flag& flag : flag)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(flag.GetCollider(), direction, 1.0f))
							flag.OnCollision(direction);
				}

				//for (Platform& platform : platforms)// == for(int i =0 ; i<platforms.size();i++)
				//	if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				//		player.OnCollision(direction);

				////enemy collider with platform
				//for (Platform& platform : platforms)
				//	if (platform.GetCollider().CheckCollision(enemy1.GetCollider(), direction, 1.0f))
				//		enemy1.OncollisionEnemy(direction);

				//for (Platform& platform : platforms)// == for(int i =0 ; i<platforms.size();i++)
				//{
				//	for (Item& chest : chest)// == for(int i =0 ; i<platforms.size();i++)

				//		if (platform.GetCollider().CheckCollision(chest.GetCollider(), direction, 1.0f))
				//			chest.OnCollision(direction);
				//}

				//for (Platform& platform : platforms)// == for(int i =0 ; i<platforms.size();i++)
				//{
				//	for (Item& hpPotion : hpPotion)// == for(int i =0 ; i<platforms.size();i++)

				//		if (platform.GetCollider().CheckCollision(hpPotion.GetCollider(), direction, 1.0f))
				//			hpPotion.OnCollision(direction);
				//}


				//IMMORTAL CLOCK//
				sf::Clock imCl;
				float immortalCl;
				immortalCl = imCl.getElapsedTime().asSeconds();
				//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy1.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{
					//printf("Collision! \n");

					enemy1.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy1.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 2.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;

						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}

				////////////////////////////////////////////////attack method//////////////////////////////////////////////
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && player.attackState == 0)
				{
					player.velocity.x = 0;
					player.attackState = 1;

					player.animation.attack1 = true;
					player.start = clock();

				}

				////////////////////////////////////////////////attack method cooldown ////////////////////////////////////////////////

				if (player.attackState > 0)
				{


					if (player.attackState == 1)
					{
						if (hitboxMid.getGlobalbounds().intersects(enemy1.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									enemy1.hp--;
									printf(" Hit enemy hp :%d    \n", enemy1.hp);

									if (enemy1.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}
					}
					double dif = (double)(player.end - player.start) / CLOCKS_PER_SEC; // ??????????????? //0.6  0.4  0.4

					if (dif > 0.6f)//??????? ??????? k ??????
					{
						cooldown = 0;
						player.attackState = 0;

					}
					else if (dif > 0.4f)//??????????????
					{
						player.animation.attack1 = false;
						player.attackState = 2;

					}

					else if (dif <= 0.4f)
					{
						//printf("%lf    ", dif);

						// std::cout << "Cooldown" << std::endl;
					}

				}
			
				////////////////////////////////////////////////setview (must follow Update)////////////////////////////////////////////////
				view.setCenter(player.GetPosition());

				////////////////////////////////////////////////set background slide////////////////////////////////////////////////
				for (Background& background : backgrounds)
					background.Update(deltaTime);






				///////////////////////////////////////////////////////////////////clear//////////////////////////////////////////////////////////////////////
				window.clear(sf::Color(150, 200, 200));
				for (Background& background : backgrounds)
					background.Draw(window);
				Background1.Draw(window);
				/////////////////////////////////////////bound around player && enemy/////////////////////////////////////////
				bound.setPosition(player.GetPosition().x, player.GetPosition().y);
				boundE.setPosition(enemy1.GetPosition().x, enemy1.GetPosition().y);

				/////////////////////////////////////////Draw bg/////////////////////////////////////////



				/////////////////////////////////////////set view/////////////////////////////////////////
				window.setView(view);


				/////////////////////////////////////////draw  everything/////////////////////////////////////////
				hitboxEnemy.Draw(window);
				hitboxMid.Draw(window);
				hitboxLeft.Draw(window);
				hitboxRight.Draw(window);


				player.Draw(window);
				if (enemy1.hp > 0) {
					enemy1.Draw(window);
				}

				////////////////////////////////////////////////draw platforms////////////////////////////////////////////////
				for (Platform& platform : platforms)
					platform.Draw(window);

				////////////////////////////////////////////////draw bullet////////////////////////////////////////////////
				for (Bullet& bullet : bullet) {

					bullet.Draw(window);
				}
				/////////////////////////////////////////draw Enemy vector///////////////////////////////////////

			
				////////////////////////////////////////////////Draw ITEM ////////////////////////////////////////////////////////////////////
				for (Item& hpPotion : hpPotion) {

					hpPotion.Draw(window);
				}
				for (Item& chest : chest) {

					chest.Draw(window);
				}
				for (Flag& flag : flag) {

					flag.Draw(window);
				}


				if (player.hpPlayer > 2)
				{
					window.draw(heartPlayer3);
				}
				if (player.hpPlayer > 1)
				{
					window.draw(heartPlayer2);
				}
				if (player.hpPlayer > 0)
				{
					window.draw(heartPlayer1);
				}



				window.draw(ammo1);

				//window.draw(hpPotion);
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				window.draw(scoreText);
				window.draw(scoreString);
				window.draw(staminaString);
				window.draw(staminaText);
				window.draw(staminaBar);
				window.draw(BulletCount);

				itemCooldown += time.asSeconds();
				//display//
				window.display();

				

				//window.display();
			}//while isOpen

		}
		//stage 2//
		if (state == 2)
		{

			printf("We are in state == 2 \n");
			/********************************** Clock ********************************/
			sf::Clock RuntimeClock;
			sf::Time RunTime;
			float RuntimeFloat;
			std::ostringstream showtime;
			sf::Text lbltTime;
			lbltTime.setPosition(0.0f, 0.0f);
			lbltTime.setCharacterSize(60);
			lbltTime.setFont(font);

			bool faceRightEnemy1Temp = 1;
			int faceRightEnemy1Count = 1;//ready , finish
			bool faceRightEnemy2Temp=1;
			int faceRightEnemy2Count = 1;//ready , finish
			bool faceRightEnemy3Temp = 1;
			int faceRightEnemy3Count = 1;//ready , finish
			
			/********************************** ClockHurt ********************************/
			sf::Clock clockHurt;
		
			float enemyHurtClock;
			enemyHurtClock = clockHurt.getElapsedTime().asSeconds();


			/********************************** Flag ********************************/
			std::vector<Flag> flag;
			sf::Texture flag_texture;
			if (!flag_texture.loadFromFile("asset/flag.png")) {}
			flag.push_back(Flag(&flag_texture, sf::Vector2f(6000,200), sf::Vector2f(0, 1)));

			/********************************** Chest ********************************/
			std::vector<Item> chest;
			sf::Texture chest_texture;
			if (!chest_texture.loadFromFile("asset/object/ChestRed.png"))
			{

			}
			sf::Clock chestTime;
			float chestT = 0.0f;
			sf::Clock spawnItem;
			float spawnItemf = 0.0f;

			srand(time(NULL));
			int ranChestX = rand() % 1000;
			int ranChestY = rand() % 620;
			float ranChestx = ranChestX / 10.f;
			float ranChesty = ranChestY / 10.f;

			printf("chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
			chest.push_back(Item(&chest_texture, sf::Vector2f(rand() % 2000 + 1000, rand() % 300 ), sf::Vector2f(0, 1)));

			/**********************************Player Heart********************************/

			sf::Sprite heartPlayer1;
			sf::Texture heartplayerTexture;
			if (!heartplayerTexture.loadFromFile("asset/object/HeartRed.png"));
			heartPlayer1.setScale(5.0f, 5.0f);
			heartPlayer1.setTexture(heartplayerTexture);

			sf::Sprite heartPlayer2;
			heartPlayer2.setScale(5.0f, 5.0f);
			heartPlayer2.setTexture(heartplayerTexture);

			sf::Sprite heartPlayer3;

			heartPlayer3.setScale(5.0f, 5.0f);
			heartPlayer3.setTexture(heartplayerTexture);

			/**********************************Enemy Heart********************************/
			sf::Sprite heartEnemy1;
			sf::Texture heartenemyTexture;
			if (!heartenemyTexture.loadFromFile("asset/object/HeartPurple.png"));
			//first = enemyN , second = heart N
		//Enemy1 heart
			heartEnemy1.setScale(2.0f, 2.0f);
			heartEnemy1.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy2;
			heartEnemy2.setScale(2.0f, 2.0f);
			heartEnemy2.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy3;
			heartEnemy3.setScale(2.0f, 2.0f);
			heartEnemy3.setTexture(heartenemyTexture);

		//Enemy2 heart
			sf::Sprite heartEnemy2_1;
			heartEnemy2_1.setScale(2.0f, 2.0f);
			heartEnemy2_1.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy2_2;
			heartEnemy2_2.setScale(2.0f, 2.0f);
			heartEnemy2_2.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy2_3;
			heartEnemy2_3.setScale(2.0f, 2.0f);
			heartEnemy2_3.setTexture(heartenemyTexture);

			//Enemy3 heart
			sf::Sprite heartEnemy3_1;
			heartEnemy3_1.setScale(2.0f, 2.0f);
			heartEnemy3_1.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy3_2;
			heartEnemy3_2.setScale(2.0f, 2.0f);
			heartEnemy3_2.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy3_3;
			heartEnemy3_3.setScale(2.0f, 2.0f);
			heartEnemy3_3.setTexture(heartenemyTexture);

		
			/**********************************Health Potion********************************/


			/*sf::Sprite hpPotion;
			sf::Texture hpPotionTexture;
			if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
			hpPotion.setScale(3.0f, 3.0f);
			hpPotion.setTexture(hpPotionTexture);*/


			/**********************************Health Potion Vector********************************/
			std::vector<Item> hpPotion;
			sf::Texture hpPotionTexture;
			if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
			
			sf::Clock Clockspawn;
			float itemCooldown = 0;

			int ranhpPotionX = rand() % 2880;
			int ranhpPotionY = 0;

			printf("potion spawn at x: %f y : %f\n", ranhpPotionX, ranhpPotionY);
			//hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1050, rand() % 300 + 310), sf::Vector2f(0, 1)));
			//hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1100, rand() % 300 + 305), sf::Vector2f(0, 1)));
			hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(ranhpPotionX, ranhpPotionY), sf::Vector2f(0, 1)));
			/**************************************************************************************/
			int ranHeartPotionX = rand() % 1000;
			int ranHeartPotionY = rand() % 620;
			float ranHpX = ranHeartPotionX / 10.f;
			float ranHpY = ranHeartPotionY / 10.f;

			//////////////////////////score////////////////////
			//int scoreCount = 0;
			sf::Font font;
			if (font.loadFromFile("asset/FSEX300.ttf")) {}
			sf::Text scoreText;
			sf::Text scoreString;
			//////////////////////////stamina////////////////////

			sf::Text staminaText;
			sf::Text staminaString;
			sf::RectangleShape staminaBar;

			//////////////////////////enemies//////////////////////////
			sf::Clock spawnTime;
			float spawnT = 0.0f;
			sf::Texture BlackEnemy;
			sf::Texture KnightEnemy;
			sf::Texture GreyEnemy;
			sf::Texture GoldenEnemy;
			//load enemy texture//
			GoldenEnemy.loadFromFile("asset/enemy/GoldenEnemy.PNG");

			BlackEnemy.loadFromFile("asset/enemy/BlackEnemy.PNG");//16x16 knight 3 v3

			GreyEnemy.loadFromFile("asset/enemy/GreyEnemy.PNG");

			KnightEnemy.loadFromFile("asset/enemy/KnightEnemy.PNG");

			//pushback enemies map03
			enemy enemy1(&GreyEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 1757.0f, 290.0f);
			enemy enemy2(&GreyEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 4325.0f, 500.0f);
			enemy enemy3(&GreyEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 5129.0f, 100.0f);

			enemyDeath enemyDeath1(&GreyEnemy, sf::Vector2u(8, 8), 0.2f, 0.0f,0.0f);
			enemyDeath enemyDeath2(&GreyEnemy, sf::Vector2u(8, 8), 0.2f, 40.0f, 300.0f);
			enemyDeath enemyDeath3(&GreyEnemy, sf::Vector2u(8, 8), 0.2f, 0.0f, 0.0f);
			sf::Vector2f enemyDeath1Temp;
			sf::Vector2f enemyDeath2Temp;
			sf::Vector2f enemyDeath3Temp;



			//Ground Collide will death platform
			sf::RectangleShape groundDeath(sf::Vector2f(200000.0f, 25.0f)); //size
			groundDeath.setPosition(sf::Vector2f(-2000.0f, 1000.0f));//position

			//////////////////////////////////////bullet declare//////////////////////////
			std::vector<Bullet> bullet;
			sf::Texture bullet_texture;
			if (!bullet_texture.loadFromFile("asset/arrow2.png"))
			{
			}
			sf::Texture bullet_textureRight;
			if (!bullet_textureRight.loadFromFile("asset/arrow2Right.png"))
			{
			}
			sf::Clock bullTime;
			float bull = 0.0f; //?????????????? ??????? bullet
			sf::Clock anibullTime;
			float anibull = 0.0f; //?????????????? ??????? bullet


			//int ammo = 5;
			sf::Text BulletX;
			sf::Text BulletCount;
			sf::Sprite ammo1;
			sf::Texture ammoTexture;
			if (!ammoTexture.loadFromFile("asset/bullet.png"));
			ammo1.setScale(0.15f, 0.15f);
			ammo1.setTexture(ammoTexture);

			//////////////////////////////////////////////////////////////////////

			std::vector<Background> backgrounds;
			backgrounds.push_back(Background(&bgTexture[0], -5.f));
			backgrounds.push_back(Background(&bgTexture[1], -10.f));
			backgrounds.push_back(Background(&bgTexture[2], -15.f));
			backgrounds.push_back(Background(&bgTexture[3], -20.f));

			sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

			sf::Texture playerTexture;
			playerTexture.loadFromFile("asset/v2.1/adventurerSheet.PNG");
			Player player(&playerTexture, sf::Vector2u(8, 12), 0.1f, 100.0f, 100.0f);




			//initialize platform
			//std::vector<Platform> platforms;

			//Background
			sf::Texture backgroundState1Texture;
			backgroundState1Texture.loadFromFile("asset/map/map1/map_01.png");
			Platform BackgroundState1(&backgroundState1Texture, sf::Vector2f(3840 * 48 / 16, 256 * 48 / 16), sf::Vector2f(3840 * 48 / 32, 256 * 48 / 32));
			sf::Texture backgroundState1ExpandTexture;
			backgroundState1ExpandTexture.loadFromFile("asset/map/map1/Expand1.png");
			//left
			Platform Background1ExpandLeft(&backgroundState1ExpandTexture, sf::Vector2f(640 * 48 / 16, 256 * 48 / 16), sf::Vector2f((640 * 48 / 32) - 1920, 256 * 48 / 32));
			//left
			Platform Background1ExpandRight(&backgroundState1ExpandTexture, sf::Vector2f(640 * 48 / 16, 256 * 48 / 16), sf::Vector2f((640 * 48 / 32) - 1920, 256 * 48 / 32));

			// BitMap Init
			std::vector<Bitmap> block0;
			int outdoor[16][240] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,00,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

			};
			// DrawBitMap
			for (int mapX = 0; mapX < 240; mapX++)
			{
				for (int mapY = 0; mapY < 16; mapY++)
				{
					if (outdoor[mapY][mapX] == 1)
					{
						Bitmap outdoor(nullptr, sf::Vector2f(((mapX) * 48) + 24, ((mapY) * 48) + 24), sf::Vector2f(48.f, 48.f));
						block0.push_back(outdoor);
					}
				}
			}
			//BitmapEnemy collinder
			std::vector<Bitmap> blockEnemy;
			int outdoorEnemy[16][240] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,00,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

			};
			// DrawBitMap
			for (int mapX = 0; mapX < 240; mapX++)
			{
				for (int mapY = 0; mapY < 16; mapY++)
				{
					if (outdoorEnemy[mapY][mapX] == 1)
					{
						Bitmap outdoorEnemy(nullptr, sf::Vector2f(((mapX) * 48) + 24, ((mapY) * 48) + 24), sf::Vector2f(48.f, 48.f));
						blockEnemy.push_back(outdoorEnemy);
					}
				}
			}
			//hitbox//  sf::Vector2f(44.0f + 28.0f, 58.0f)
			hitbox
				hitboxMid(0, 0, sf::Vector2f(22, player.GetSize().y), player.GetPosition());
			hitbox
				hitboxLeft(-28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());
			hitbox
				hitboxRight(+28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());

			hitbox
				hitboxEnemy(0, 0, sf::Vector2f(30, 48), enemy1.GetPosition());

			hitbox
				hitboxEnemy2(0, 0, sf::Vector2f(30, 48), enemy2.GetPosition());

			hitbox
				hitboxEnemy3(0, 0, sf::Vector2f(30, 48), enemy3.GetPosition());

			//attack
			int cooldown = 0;


			float deltaTime = 0.0f;
			sf::Clock clockW;


			while (window.isOpen()) {
				deltaTime = clockW.restart().asSeconds();
				if (deltaTime > 1.0f / 60.0f)
					deltaTime = 1.0f / 60.0f;
				sf::Event evnt;
				while (window.pollEvent(evnt))
				{
					switch (evnt.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::Resized:
						ResizeView(window, view);

						break;

					}
				}
				//////////////////////////////////////////////////Clock Runtime/////////////////////////////////////////

				//RunTime = RuntimeClock.getElapsedTime();
				RunTime = RuntimeClock.getElapsedTime();
				showtime << RunTime.asSeconds();
				lbltTime.setString(showtime.str());
				showtime.str("");
				lbltTime.setPosition(view.getCenter().x + 200, view.getCenter().y - 210);

				
				//printf("   player hp : %d   ", player.hpPlayer);
				



				//////////////////////////////////////////////////Item in loop//////////////////////////////////////////

				//////////////////////////////////////////Chest Item///////////////////////////////////////////////////////////

				chestT = chestTime.getElapsedTime().asMilliseconds();
				for (Item& chest : chest) {
					//printf("Update!\n");
					chest.Update(deltaTime);
				}

				Collider tempChest = player.GetColliderHitbox();
				for (Item& chest : chest)
				{
					if (chest.GetCollider().CheckCollisionAttack(tempChest)) {

						chest.setDestroy(true);
						printf(" Hit the chest !!\n");
						ammo += rand() % 3 + 3;
						float ranChestX = rand() % 2000 + 1000;
						float ranChestY = rand() % 300 + 300;
						player.immortalTime = 10.0f;
						chest.setSpawn(true);
						player.immortal = true;
						spawnItemf = spawnItem.getElapsedTime().asSeconds();
						player.imCl.restart();
					}
				}

				for (int i = 0;i < chest.size();i++)
				{
					if (chest[i].isSpawn())
					{
						printf("New chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
						//				chest.push_back(Item(&chest_texture, sf::Vector2f(ranChestX, ranChestY), sf::Vector2f(0, 0)));

						chest.push_back(Item(&chest_texture, sf::Vector2f(rand() % 9737, 0), sf::Vector2f(0, 0)));

						chest[i].setSpawn(false);
					}


				}

				for (int i = 0;i < chest.size();i++)
				{
					if (chest[i].isDestroy())
					{
						chest.erase(chest.begin() + i);
					}
				}
				/////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////Hp potion Item///////////////////////////////////////////////////////////
				//sf::Time time = Clockspawn.getElapsedTime();
				Clockspawn.restart();

				for (Item& hpPotion : hpPotion) {
					//printf("Update!\n");
					hpPotion.Update(deltaTime);
				}

				Collider tempPotion = player.GetColliderHitbox();
				for (Item& hpPotion : hpPotion)
				{
					if (hpPotion.GetCollider().CheckCollisionAttack(tempPotion)) {

						hpPotion.setDestroy(true);
						printf(" Hit the Potion !!\n");
						hpPotion.setSpawn(true);
						//potionSpawn = 1;
						if (player.hpPlayer < 3)
						{
							int randompotion;
							randompotion = rand() % 2 + 1;
							if (player.hpPlayer == 2)
							{
								randompotion = 1;
							}
							player.hpPlayer += randompotion;
						}
						printf("hp player %d ", player.hpPlayer);
					}
				}

				//std::cout << itemCooldown << std::endl;

				for (int i = 0;i < hpPotion.size();i++)
				{
					if (hpPotion[i].isSpawn())
					{

						printf("New hpPotion spawn at \n");
						hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 9737, 0), sf::Vector2f(0, 0)));
						hpPotion[i].setSpawn(false);

					}
				}

				//printf("%f\n", chestT);
				for (int i = 0;i < hpPotion.size();i++)
				{
					if (hpPotion[i].isDestroy())
					{
						hpPotion.erase(hpPotion.begin() + i);
					}
				}
				////////////////////////////////////////Flag collision action////////////////////////////////////////////
				for (Flag& flag : flag) {
					//printf("Update!\n");
					flag.Update(deltaTime);
				}

				Collider tempFlag = player.GetColliderHitbox();
				for (Flag& flag : flag)
				{
					if (flag.GetCollider().CheckCollisionAttack(tempFlag)) {

						flag.setDestroy(true);
						printf(" Hit the flag !!\n");
						state = 3;
						goto jumperState;
					}
				}
				//restart//
				if (player.hpPlayer <= 0)
				{
					state = 66;//restart
					goto jumperState;

				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////

				/////////////////////////////////////////////////score Update////////////////////////////////////////////////


				scoreText.setPosition(view.getCenter().x - 300, view.getCenter().y - 300);
				scoreText.setFillColor(sf::Color::Red);
				scoreText.setFont(font);
				scoreText.setString(std::to_string(scoreCount));
				scoreText.setOutlineThickness(5.f);
				scoreText.setOutlineColor(sf::Color::White);
				scoreString.setPosition(scoreText.getPosition().x - 120, scoreText.getPosition().y - 1);

				scoreString.setFillColor(sf::Color::Red);
				scoreString.setFont(font);
				scoreString.setString("Score : ");
				scoreString.setOutlineThickness(5.f);
				scoreString.setOutlineColor(sf::Color::White);
				//////////////////////////////////////////////////////////////////////////////////////////////////////

				/////////////////////////////////////////////////score Update////////////////////////////////////////////////
				float staminaCount = (player.stamina / 1500.0) * 100;
				staminaBar.setSize(sf::Vector2f(staminaCount, 15));

				staminaBar.setPosition(view.getCenter().x + 380, view.getCenter().y - 310);
				staminaBar.setFillColor(sf::Color::Red);
				staminaBar.setOutlineThickness(5.f);
				staminaBar.setOutlineColor(sf::Color::Yellow);
				staminaString.setPosition(staminaBar.getPosition().x - 150, staminaBar.getPosition().y - 15);
				staminaString.setFillColor(sf::Color::Red);
				staminaString.setFont(font);
				staminaString.setString("Stamina : ");
				staminaString.setOutlineThickness(5.f);
				staminaString.setOutlineColor(sf::Color::Yellow);

				////////////////////////////////////////////////Bullet string/////////////////////////////////////////////
				//printf("hP :  %d\n", player.hpPlayer);
				BulletCount.setPosition(view.getCenter().x + 450, view.getCenter().y - 200);
				BulletCount.setFillColor(sf::Color::Red);
				BulletCount.setOutlineThickness(5.f);
				BulletCount.setOutlineColor(sf::Color::Yellow);
				BulletCount.setFont(font);
				BulletCount.setString(std::to_string(ammo));

				//////////////////////////////////////////////////////Heart player////////////////////////////////////////////////////// 
				heartPlayer1.setPosition(view.getCenter().x - 100, view.getCenter().y - 300);
				heartPlayer2.setPosition(view.getCenter().x - 70, view.getCenter().y - 300);
				heartPlayer3.setPosition(view.getCenter().x - 40, view.getCenter().y - 300);
				//////////////////////////////////////////////////////Heart Enemy1////////////////////////////////////////////////////// 
				heartEnemy1.setPosition(enemy1.GetPosition().x - 20, enemy1.GetPosition().y - 20);
				heartEnemy2.setPosition(enemy1.GetPosition().x, enemy1.GetPosition().y - 20);
				heartEnemy3.setPosition(enemy1.GetPosition().x + 20, enemy1.GetPosition().y - 20);

				//////////////////////////////////////////////////////Heart Enemy2////////////////////////////////////////////////////// 
				heartEnemy2_1.setPosition(enemy2.GetPosition().x - 20, enemy2.GetPosition().y - 20);
				heartEnemy2_2.setPosition(enemy2.GetPosition().x, enemy2.GetPosition().y - 20);
				heartEnemy2_3.setPosition(enemy2.GetPosition().x + 20, enemy2.GetPosition().y - 20);

				//////////////////////////////////////////////////////Heart Enemy3////////////////////////////////////////////////////// 
				heartEnemy3_1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				heartEnemy3_2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				heartEnemy3_3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////////Heart Enemy3////////////////////////////////////////////////////// 
				////heartEnemy1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				////heartEnemy2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				////heartEnemy3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////////Heart Enemy4////////////////////////////////////////////////////// 
				////heartEnemy1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				////heartEnemy2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				////heartEnemy3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////////Heart Enemy5////////////////////////////////////////////////////// 
				////heartEnemy1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				////heartEnemy2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				////heartEnemy3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////Heart Enemy1////////////////////////////////////////////////////// 
				//heartEnemy1.setPosition(enemy1.GetPosition().x - 20, enemy1.GetPosition().y - 40);
				//heartEnemy2.setPosition(enemy1.GetPosition().x, enemy1.GetPosition().y - 40);
				//heartEnemy3.setPosition(enemy1.GetPosition().x + 20, enemy1.GetPosition().y - 40);

				/////////////////////////////////////////////////////ammo player////////////////////////////////////////////////////// 
				ammo1.setPosition(view.getCenter().x + 400, view.getCenter().y - 200);


				/////////////////////////////////////////player && enemy Update && hitboxupdate/////////////////////////////////////////
				sf::Vector2f direction;
				player.Update(deltaTime);
				enemy1.Update(deltaTime);
				enemy2.Update(deltaTime);
				enemy3.Update(deltaTime);
				enemyDeath1.Update(deltaTime);
				enemyDeath2.Update(deltaTime);
				enemyDeath3.Update(deltaTime);



				hitboxMid.Update(0, 0, player.GetPosition());
				hitboxLeft.Update(-28, 0, player.GetPosition());
				hitboxRight.Update(+28, 0, player.GetPosition());

				//enemy
				hitboxEnemy.Update(0, 0, enemy1.GetPosition());
				hitboxEnemy2.Update(0, 0, enemy2.GetPosition());
				hitboxEnemy3.Update(0, 0, enemy3.GetPosition());
				
				////touch groundDeath////
				/*Player*/
				if (player.GetColliderHitbox().CheckCollisionAttack(groundDeath))
				{
					state = 66;
					goto jumperState;
					//player.SetPosition(sf::Vector2f(200.0f, 0.0f));
				}
				//potion
				for (Item& hpPotion : hpPotion)
				{
					if (hpPotion.GetCollider().CheckCollisionAttack(groundDeath))
					{
						hpPotion.setDestroy(true);
						printf("Spawnnnn Potion ground death !!\n");
						hpPotion.setSpawn(true);
					}
				}
				//chest
				for (Item& chest : chest)
				{
					if (chest.GetCollider().CheckCollisionAttack(groundDeath))
					{
						chest.setDestroy(true);
						printf("Spawnnnnn chest fround death !!\n");
						chest.setSpawn(true);
					}
				}

				//printf(" x : %f y : %f\n", player.GetPosition().x, player.GetPosition().y);

				
				
				////////////////////////////////////////////////player collider with platform////////////////////////////////////////////////

				////BitMap Collision WITH PLAYER ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						player.OnCollision(direction);
				//Enemy1
					////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy1.GetCollider(), direction, 1.0f))
						enemy1.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(enemy1.GetCollider(), direction, 1.0f))
					{
						enemy1.OncollisionEnemy(direction);
						enemy1.velocity.x = -enemy1.velocity.x;
						enemy1.velocity.x = 0.0f;
					}
				//Enemy2
						////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy2.GetCollider(), direction, 1.0f))
						enemy2.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(enemy2.GetCollider(), direction, 1.0f))
					{
						enemy2.OncollisionEnemy(direction);
						enemy2.velocity.x = -enemy2.velocity.x;
						enemy2.velocity.x = 0.0f;
					}

				//Enemy3
									////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy3.GetCollider(), direction, 1.0f))
						enemy3.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(enemy3.GetCollider(), direction, 1.0f))
					{
						enemy3.OncollisionEnemy(direction);
						enemy3.velocity.x = -enemy3.velocity.x;
						enemy3.velocity.x = 0.0f;
					}
				
				////BitMap Collision WITH CHEST ////
				for (Bitmap& block0 : block0)
				{
					for (Item& chest : chest)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(chest.GetCollider(), direction, 1.0f))
							chest.OnCollision(direction);
				}

				////BitMap Collision WITH HP POTION ////
				for (Bitmap& block0 : block0)
				{
					for (Item& hpPotion : hpPotion)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(hpPotion.GetCollider(), direction, 1.0f))
							hpPotion.OnCollision(direction);
				}
				////BitMap Collision WITH Flag ////
				for (Bitmap& block0 : block0)
				{
					for (Flag& flag : flag)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(flag.GetCollider(), direction, 1.0f))
							flag.OnCollision(direction);
				}
				//IMMORTAL CLOCK//
				sf::Clock imCl;
				float immortalCl;
				immortalCl = imCl.getElapsedTime().asSeconds();
				//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy1.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{
					enemy1.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy1.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;
						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}
				//enemy2
						//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy2.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{

					enemy2.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy2.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;

						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}
				//enemy3
						//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy3.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{

					enemy3.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy3.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;

						player.animation.crashEnemy = false;
						//player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}


				////////////////////////////////////////////////attack method//////////////////////////////////////////////
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && player.attackState == 0)
				{
					player.velocity.x = 0;
					player.attackState = 1;

					player.animation.attack1 = true;
					player.start = clock();
				}

				////////////////////////////////////////////////attack method cooldown ////////////////////////////////////////////////
				
				//printf("%f\n", enemyHurtClock);
				if (player.attackState > 0)
				{
					if (player.attackState == 1)
					{
						if (hitboxMid.getGlobalbounds().intersects(enemy1.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									
									enemyHurtClock = 5.0f;
									//enemyHurtClock = clockHurt.getElapsedTime().asSeconds();

									if(enemyHurtClock <= 200.0)
										enemy1.animationEnemy.shieldBlocking == true;
									
									enemy1.SetPositionBounce(20.0);
									enemy1.hp--;
									printf(" Hit enemy hp :%d    \n", enemy1.hp);

									if (enemy1.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}
						}
						//enemy2
						if (hitboxMid.getGlobalbounds().intersects(enemy2.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									enemy2.hp--;
									printf(" Hit enemy hp :%d    \n", enemy2.hp);

									if (enemy2.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}

						//enemy3
						if (hitboxMid.getGlobalbounds().intersects(enemy3.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									enemy3.hp--;
									printf(" Hit enemy hp :%d    \n", enemy3.hp);

									if (enemy3.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}
					}
					double dif = (double)(player.end - player.start) / CLOCKS_PER_SEC; // ??????????????? //0.6  0.4  0.4
					if (dif > 0.6f)
					{
						cooldown = 0;
						player.attackState = 0;

					}
					else if (dif > 0.4f)
					{
						player.animation.attack1 = false;
						player.attackState = 2;

					}
					else if (dif <= 0.4f)
					{
						//printf("%lf    ", dif);

						// std::cout << "Cooldown" << std::endl;
					}

					
				}
				////////////////////////////////////////////////attack method//////////////////////////////////////////////
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && player.attackState == 0)
				{
					player.velocity.x = 0;
					player.attackState = 1;

					player.animation.attack1 = true;
					player.start = clock();

				}
				/////////////////////////////////////////////////////bullet update /////////////////////////////////////////////////////
				anibull = anibullTime.getElapsedTime().asSeconds();
				if (ammo > 0) {
					if (anibull > 0.4)
					{
						bull = bullTime.getElapsedTime().asMilliseconds();
						if (bull > 900)
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
							{
								player.velocity.x = 0;
								player.shootState = 1;
								player.animation.finishShoot == false;
								player.animation.shoot = true;
								player.start = clock();
								ammo--;
								if (player.faceRight == true)
								{
									bullet.push_back(Bullet(&bullet_texture, sf::Vector2u(1, 1), 0, sf::Vector2f(player.GetPosition().x + 25, player.GetPosition().y), sf::Vector2f(500, 0)));
									bullTime.restart();
									anibullTime.restart();
								}
								else if (player.faceRight == false)
								{
									bullet.push_back(Bullet(&bullet_textureRight, sf::Vector2u(1, 1), 0/*imageCOunt*/, sf::Vector2f(player.GetPosition().x - 25/* +10 ??????????????????????????????*/, player.GetPosition().y), sf::Vector2f(-500, 0)));
									bullTime.restart();
									anibullTime.restart();
								}

							}
						}
					}

				}
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}
				for (Bullet& bullet : bullet) {
					//printf("Update!\n");
					bullet.Update(deltaTime);
				}
				////////////////////////////////////////////////shoot method cooldown ////////////////////////////////////////////////
				if (player.shootState > 0)
				{
					if (player.shootState == 1)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
						{

							cooldown++;
							if (cooldown == 1 || cooldown == 2 || cooldown == 3)
							{
								player.velocity.x = 0;
								player.shootState = 2;
							}
						}
					}

					double dif = (double)(player.end - player.start) / CLOCKS_PER_SEC;

					if (dif > 0.8f)
					{
						cooldown = 0;
						player.shootState = 0;

					}
					else if (dif > 0.6f)
					{
						player.animation.attack1 = false;
						player.shootState = 2;

					}

					else if (dif <= 0.6f)
					{
					}
				}

				//Enemy2
					//COLLISION BULLET WITH ENEMY02//
				Collider temp2 = enemy2.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp2)) {

						bullet.setDestroy(true);
						enemy2.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", enemy2.hp);
					}
				}

				//COLLISION BULLET WITH ENEMY01//
				Collider temp = enemy1.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp)) {

						//printf("Bullet Destroy!!\n");
						bullet.setDestroy(true);
						enemy1.setHp(bullet.GetDmg());
						enemy1.SetPositionBounce(20.0);
						printf(" Hit Gun enemy hp : %d  \n", enemy1.hp);

					}
				}
				//enemy1 set die
				if (enemy1.GetHp() <= 0)
				{
					enemy1.setDie(true);
					enemyDeath1.setDie(true);
					faceRightEnemy1Count = 0;


				}
				//bullet disapear//
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}
				//printf("player x:%f y: %f\n", player.GetPosition().x, player.GetPosition().y);

				if (enemy1.isDie() == true)
				{


					enemyDeath1Temp = enemy1.GetPosition();
					enemyDeath1.SetPosition(enemyDeath1Temp);

					if (faceRightEnemy1Count == 0)
					{
						faceRightEnemy1Temp = enemy1.faceRight;
						faceRightEnemy1Count = 99;
					}

					printf("\n  We are in animation dead enemy ");
					enemy1.animationEnemy.dead = true;
					enemy1.row = 7;

					printf("Enemy spwan!!\n");
					enemy1.setDie(false);
					enemy1.setDieSpawn(true);

					scoreCount += 100;
					enemy1.hp = 3;
					//enemy2.SetPosition(sf::Vector2f(enemy2.GetPosition()));

					enemy1.SetPosition(sf::Vector2f(11400.0f, 90.0f));

				}


				

				//enemy set die

				if (enemy2.GetHp() <= 0)
				{
					enemy2.setDie(true);
					enemyDeath2.setDie(true);
					faceRightEnemy2Count = 0;
				}

				if (enemy2.isDie() == true )
				{
					enemyDeath2Temp = enemy2.GetPosition();
					enemyDeath2.SetPosition(enemyDeath2Temp);
					
					if (faceRightEnemy2Count == 0)
					{
						faceRightEnemy2Temp = enemy2.faceRight;
						faceRightEnemy2Count=99;
					}

						printf("\n  We are in animation dead enemy ");
						enemy2.animationEnemy.dead = true;
						enemy2.row = 7;

						printf("Enemy spwan!!\n");
						enemy2.setDie(false);
						enemy2.setDieSpawn(true);
					
						scoreCount += 100;
						enemy2.hp = 3;
						//enemy2.SetPosition(sf::Vector2f(enemy2.GetPosition()));
						
						enemy2.SetPosition(sf::Vector2f(11400.0f, 90.0f));
					
				}
				//printf("aniDeathEny2   = %d           ", aniDeathEny2);
				//printf("%f\n", RuntimeFloat);
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}

				//Enemy3
				//COLLISION BULLET WITH ENEMY02//
				Collider temp3 = enemy3.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp3)) {

						bullet.setDestroy(true);
						enemy3.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", enemy3.hp);
					}
				}
				//enemy set die
				if (enemy3.GetHp() <= 0)
				{
					enemy3.setDie(true);
					enemyDeath3.setDie(true);
					faceRightEnemy3Count = 0;
				}
				//bullet disapear//
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}

				if (enemy3.isDie() == true)
				{


					enemyDeath3Temp = enemy3.GetPosition();
					enemyDeath3.SetPosition(enemyDeath3Temp);

					if (faceRightEnemy1Count == 0)
					{
						faceRightEnemy3Temp = enemy1.faceRight;
						faceRightEnemy3Count = 99;
					}

					printf("\n  We are in animation dead enemy ");
					enemy3.animationEnemy.dead = true;
					enemy3.row = 7;

					printf("Enemy spwan!!\n");
					enemy3.setDie(false);
					enemy3.setDieSpawn(true);

					scoreCount += 100;
					enemy3.hp = 3;
					//enemy2.SetPosition(sf::Vector2f(enemy2.GetPosition()));

					enemy3.SetPosition(sf::Vector2f(11400.0f, 90.0f));


				}


				////////////////////////////////////////////////setview (must follow Update)////////////////////////////////////////////////
				view.setCenter(player.GetPosition().x, 380);
				////////////////////////////////////////////////set background slide////////////////////////////////////////////////
				for (Background& background : backgrounds)
					background.Update(deltaTime);
				///////////////////////////////////////////////////////////////////clear//////////////////////////////////////////////////////////////////////
				window.clear(sf::Color(150, 200, 200));
				/////////////////////////////////////////Draw bg/////////////////////////////////////////
				//for (Background& background : backgrounds)
				//	background.Draw(window);
				
				
				/////////////////////////////////////////bound around player && enemy/////////////////////////////////////////
				bound.setPosition(player.GetPosition().x, player.GetPosition().y);
				boundE.setPosition(enemy1.GetPosition().x, enemy1.GetPosition().y);



				/*for (Bitmap& blockEnemy : blockEnemy)
					blockEnemy.draw(window);*/

				/////////////////////////////////////////set view/////////////////////////////////////////
				window.setView(view);
				BackgroundState1.Draw(window);
				Background1ExpandLeft.Draw(window);
				Background1ExpandRight.Draw(window);
				
				/////////////////////////////////////////draw  everything/////////////////////////////////////////
				//hitboxEnemy.Draw(window);
				//hitboxMid.Draw(window);
				//hitboxLeft.Draw(window);
				//hitboxRight.Draw(window);
			
				//Draw player

				//Draw player heart
				if (player.hpPlayer > 2)
				{
					window.draw(heartPlayer3);
				}
				if (player.hpPlayer > 1)
				{
					window.draw(heartPlayer2);
				}
				if (player.hpPlayer > 0)
				{
					window.draw(heartPlayer1);
				}
				player.Draw(window);
				//draw Enemy1
				if (enemy1.isDieSpawn() == false)
				{

					if (enemy1.hp > 0 ) {
						enemy1.Draw(window);
						//Draw enemy1 heart
						if (enemy1.hp > 2)
						{
							window.draw(heartEnemy3);
						}
						if (enemy1.hp > 1)
						{
							window.draw(heartEnemy2);
						}
						if (enemy1.hp > 0)
						{
							window.draw(heartEnemy1);
						}

					}
				}
				//draw enemy3 Death
				enemyDeath1.faceRight = faceRightEnemy1Temp;

				if (enemyDeath1.isDie() == true)
				{
					//enemyDeath2.faceRight = enemy2.faceRight;
					enemyDeath1.animationEnemyDeath.play = true;
					enemyDeath1.Draw(window);
				}

				//draw Enemy2
				if (enemy2.isDieSpawn() == false )
				{ 
					
					if (enemy2.hp > 0) {
						enemy2.Draw(window);
						//Draw enemy2 heart
						if (enemy2.hp > 2)
						{
							window.draw(heartEnemy2_3);
						}
						if (enemy2.hp > 1)
						{
							window.draw(heartEnemy2_2);
						}
						if (enemy2.hp > 0)
						{
							window.draw(heartEnemy2_1);
						}
					}

				}
				//draw enemy2 Death
						enemyDeath2.faceRight = faceRightEnemy2Temp;
					
						if (enemyDeath2.isDie() == true)
						{
							//enemyDeath2.faceRight = enemy2.faceRight;
							enemyDeath2.animationEnemyDeath.play = true;
							enemyDeath2.Draw(window);
						}

				//draw Enemy3
				if (enemy3.isDieSpawn() == false)
				{
					if (enemy3.hp > 0) {
						enemy3.Draw(window);
						//Draw enemy2 heart
						if (enemy3.hp > 2)
						{
							window.draw(heartEnemy3_3);
						}
						if (enemy3.hp > 1)
						{
							window.draw(heartEnemy3_2);
						}
						if (enemy3.hp > 0)
						{
							window.draw(heartEnemy3_1);
						}
					}

				}
				//draw enemy3 Death
				enemyDeath3.faceRight = faceRightEnemy3Temp;

				if (enemyDeath3.isDie() == true)
				{
					//enemyDeath2.faceRight = enemy2.faceRight;
					enemyDeath3.animationEnemyDeath.play = true;
					enemyDeath3.Draw(window);
				}
				

				////////////////////////////////////////////////draw platforms////////////////////////////////////////////////
				//for (Platform& platform : platforms)
				//	platform.Draw(window);

				////////////////////////////////////////////////draw bullet////////////////////////////////////////////////
				for (Bullet& bullet : bullet) {

					bullet.Draw(window);
				}

				////////////////////////////////////////////////Draw ITEM ////////////////////////////////////////////////////////////////////
				for (Item& hpPotion : hpPotion) {

					hpPotion.Draw(window);
				}
				for (Item& chest : chest) {

					chest.Draw(window);
				}
				for (Flag& flag : flag) {

					flag.Draw(window);
				}
				window.draw(groundDeath);
				window.draw(ammo1);

				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				window.draw(scoreText);
				window.draw(scoreString);
				window.draw(staminaString);
				window.draw(staminaText);
				window.draw(staminaBar);
				window.draw(BulletCount);

				window.draw(lbltTime);

				//display//
				window.display();
			}//while isOpen



		}//if(state ==2)
		
		if (state == 3)
		{
		
			///////////////////////////////////////Item/////////////////////////////////
			/********************************** Chest ********************************/
			std::vector<Item> chest;
			sf::Texture chest_texture;
			if (!chest_texture.loadFromFile("asset/object/ChestRed.png"))
			{

			}
			sf::Clock chestTime;
			float chestT = 0.0f;
			sf::Clock spawnItem;
			float spawnItemf = 0.0f;

			srand(time(NULL));
			int ranChestX = rand() % 1000;
			int ranChestY = rand() % 620;
			float ranChestx = ranChestX / 10.f;
			float ranChesty = ranChestY / 10.f;

			//printf("chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
			chest.push_back(Item(&chest_texture, sf::Vector2f(rand() % 2000 + 1000, rand() % 300 + 300), sf::Vector2f(0, 1)));

			/**********************************Player Heart********************************/

			sf::Sprite heartPlayer1;
			sf::Texture heartplayerTexture;
			if (!heartplayerTexture.loadFromFile("asset/object/HeartRed.png"));
			heartPlayer1.setScale(5.0f, 5.0f);
			heartPlayer1.setTexture(heartplayerTexture);

			sf::Sprite heartPlayer2;
			heartPlayer2.setScale(5.0f, 5.0f);
			heartPlayer2.setTexture(heartplayerTexture);

			sf::Sprite heartPlayer3;

			heartPlayer3.setScale(5.0f, 5.0f);
			heartPlayer3.setTexture(heartplayerTexture);

			/**********************************Enemy Heart********************************/
			sf::Sprite heartEnemy1;
			sf::Texture heartenemyTexture;
			if (!heartenemyTexture.loadFromFile("asset/object/HeartPurple.png"));
			//first = enemyN , second = heart N
		//Enemy1 heart
			heartEnemy1.setScale(2.0f, 2.0f);
			heartEnemy1.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy2;
			heartEnemy2.setScale(2.0f, 2.0f);
			heartEnemy2.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy3;
			heartEnemy3.setScale(2.0f, 2.0f);
			heartEnemy3.setTexture(heartenemyTexture);

			//Enemy2 heart
			sf::Sprite heartEnemy2_1;
			heartEnemy2_1.setScale(2.0f, 2.0f);
			heartEnemy2_1.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy2_2;
			heartEnemy2_2.setScale(2.0f, 2.0f);
			heartEnemy2_2.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy2_3;
			heartEnemy2_3.setScale(2.0f, 2.0f);
			heartEnemy2_3.setTexture(heartenemyTexture);

			//Enemy3 heart
			sf::Sprite heartEnemy3_1;
			heartEnemy3_1.setScale(2.0f, 2.0f);
			heartEnemy3_1.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy3_2;
			heartEnemy3_2.setScale(2.0f, 2.0f);
			heartEnemy3_2.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy3_3;
			heartEnemy3_3.setScale(2.0f, 2.0f);
			heartEnemy3_3.setTexture(heartenemyTexture);

			//Semi boss heart
			sf::Sprite heartEnemy4_1;
			heartEnemy4_1.setScale(2.0f, 2.0f);
			heartEnemy4_1.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy4_2;
			heartEnemy4_2.setScale(2.0f, 2.0f);
			heartEnemy4_2.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy4_3;
			heartEnemy4_3.setScale(2.0f, 2.0f);
			heartEnemy4_3.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy4_4;
			heartEnemy4_4.setScale(2.0f, 2.0f);
			heartEnemy4_4.setTexture(heartenemyTexture);
			sf::Sprite heartEnemy4_5;
			heartEnemy4_5.setScale(2.0f, 2.0f);
			heartEnemy4_5.setTexture(heartenemyTexture);

			//Boss heart  //first = enemyN , second = heart N
			sf::Sprite heartBoss1;
			heartBoss1.setScale(2.0f, 2.0f);
			heartBoss1.setTexture(heartenemyTexture);
			sf::Sprite heartBoss2;
			heartBoss2.setScale(2.0f, 2.0f);
			heartBoss2.setTexture(heartenemyTexture);
			sf::Sprite heartBoss3;
			heartBoss3.setScale(2.0f, 2.0f);
			heartBoss3.setTexture(heartenemyTexture);
			sf::Sprite heartBoss4;
			heartBoss4.setScale(2.0f, 2.0f);
			heartBoss4.setTexture(heartenemyTexture);
			sf::Sprite heartBoss5;
			heartBoss5.setScale(2.0f, 2.0f);
			heartBoss5.setTexture(heartenemyTexture);
			sf::Sprite heartBoss6;
			heartBoss6.setScale(2.0f, 2.0f);
			heartBoss6.setTexture(heartenemyTexture);
			sf::Sprite heartBoss7;
			heartBoss7.setScale(2.0f, 2.0f);
			heartBoss7.setTexture(heartenemyTexture);
			sf::Sprite heartBoss8;
			heartBoss8.setScale(2.0f, 2.0f);
			heartBoss8.setTexture(heartenemyTexture);
			sf::Sprite heartBoss9;
			heartBoss9.setScale(2.0f, 2.0f);
			heartBoss9.setTexture(heartenemyTexture);
			sf::Sprite heartBoss10;
			heartBoss10.setScale(2.0f, 2.0f);
			heartBoss10.setTexture(heartenemyTexture);
			/**********************************Health Potion********************************/


			/*sf::Sprite hpPotion;
			sf::Texture hpPotionTexture;
			if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
			hpPotion.setScale(3.0f, 3.0f);
			hpPotion.setTexture(hpPotionTexture);*/


			/**********************************Health Potion Vector********************************/
			std::vector<Item> hpPotion;
			sf::Texture hpPotionTexture;
			if (!hpPotionTexture.loadFromFile("asset/object/PotionRed.png"));
			//sf::Clock hpPotionTime;
			//float potionT = 0.0f; //?????????????? ??????? bullet
			//
			//int potionSpawn=0 ; // 0 = can't create ???????? ,1= ready to create , 2= create ????
			//
			sf::Clock Clockspawn;
			float itemCooldown = 0;

			int ranhpPotionX = rand() % 2880;
			int ranhpPotionY = 0;

			//printf("potion spawn at x: %f y : %f\n", ranhpPotionX, ranhpPotionY);
			//hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1050, rand() % 300 + 310), sf::Vector2f(0, 1)));
			//hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 2000 + 1100, rand() % 300 + 305), sf::Vector2f(0, 1)));
			hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(ranhpPotionX, ranhpPotionY), sf::Vector2f(0, 1)));
			/**************************************************************************************/
			//heartPlayer.setSize(sf::Vector2f(100,100)); 
			//srand(time(NULL));
			int ranHeartPotionX = rand() % 1000;
			int ranHeartPotionY = rand() % 620;
			float ranHpX = ranHeartPotionX / 10.f;
			float ranHpY = ranHeartPotionY / 10.f;

			//////////////////////////score////////////////////
			//int scoreCount = 0;
			sf::Font font;
			if (font.loadFromFile("asset/FSEX300.ttf")) {}
			sf::Text scoreText;
			sf::Text scoreString;
			//////////////////////////stamina////////////////////

			sf::Text staminaText;
			sf::Text staminaString;
			sf::RectangleShape staminaBar;

			//////////////////////////enemies//////////////////////////
			sf::Clock spawnTime;
			float spawnT = 0.0f;
			sf::Texture BlackEnemy;
			sf::Texture KnightEnemy;
			sf::Texture GreyEnemy;
			sf::Texture GoldenEnemy;
			//load enemy texture//
			GoldenEnemy.loadFromFile("asset/enemy/GoldenEnemy.PNG");

			BlackEnemy.loadFromFile("asset/enemy/BlackEnemy.PNG");//16x16 knight 3 v3

			GreyEnemy.loadFromFile("asset/enemy/GreyEnemy.PNG");

			KnightEnemy.loadFromFile("asset/enemy/KnightEnemy.PNG");

			//pushback enemies map03
			enemy enemy1(&GoldenEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 1030.0f, 290.0f);
			enemy enemy2(&GoldenEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 2354.0f, 500.0f);
			// enemy3(&GoldenEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 7200.0f, 390.0f);
			//enemy enemy4(&KnightEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 6190.0f, 270.0f);

			enemy enemy3(&GoldenEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 6190.0f, 270.0f);
			enemy enemy4(&KnightEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 7200.0f, 390.0f);
			enemy4.hp = 5;
			//enemy Boss(&BlackEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 10000.0f, 270.0f);
			Boss boss(&BlackEnemy, sf::Vector2u(8, 8), 0.2f, 100.0f, 10000.0f, 270.0f);
			//Ground Collide will death platform
			sf::RectangleShape groundDeath(sf::Vector2f(200000.0f, 25.0f)); //size
			groundDeath.setPosition(sf::Vector2f(-2000.0f, 1000.0f));//position

			//////////////////////////////////////bullet declare//////////////////////////
			std::vector<Bullet> bullet;
			sf::Texture bullet_texture;
			if (!bullet_texture.loadFromFile("asset/arrow2.png"))
			{
			}
			sf::Texture bullet_textureRight;
			if (!bullet_textureRight.loadFromFile("asset/arrow2Right.png"))
			{
			}
			sf::Clock bullTime;
			float bull = 0.0f; //?????????????? ??????? bullet
			sf::Clock anibullTime;
			float anibull = 0.0f; //?????????????? ??????? bullet


			//int ammo = 5;
			sf::Text BulletX;
			sf::Text BulletCount;
			sf::Sprite ammo1;
			sf::Texture ammoTexture;
			if (!ammoTexture.loadFromFile("asset/bullet.png"));
			ammo1.setScale(0.15f, 0.15f);
			ammo1.setTexture(ammoTexture);

			//////////////////////////////////////////////////////////////////////

			sf::RectangleShape bound;
			bound.setSize(sf::Vector2f(100.0, 74.0));
			bound.setOrigin(bound.getSize() / 2.0f);
			bound.setPosition(350.0f, 250.0f);
			bound.setFillColor(sf::Color::Red);

			sf::RectangleShape boundE;
			boundE.setSize(sf::Vector2f(100.0, 74.0));
			boundE.setOrigin(boundE.getSize() / 2.0f);
			boundE.setPosition(350.0f, 250.0f);
			boundE.setFillColor(sf::Color::Green);

			sf::Texture bgTexture[4];
			bgTexture[0].loadFromFile("asset/CloudsBack.png");
			bgTexture[1].loadFromFile("asset/CloudsFront.png");
			bgTexture[2].loadFromFile("asset/BGBack.png");
			bgTexture[3].loadFromFile("asset/BGFront.png");


			std::vector<Background> backgrounds;
			backgrounds.push_back(Background(&bgTexture[0], -5.f));
			backgrounds.push_back(Background(&bgTexture[1], -10.f));
			backgrounds.push_back(Background(&bgTexture[2], -15.f));
			backgrounds.push_back(Background(&bgTexture[3], -20.f));

			sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

			sf::Texture playerTexture;
			playerTexture.loadFromFile("asset/v2.1/adventurerSheet.PNG");
			Player player(&playerTexture, sf::Vector2u(8, 12), 0.1f, 100.0f, 100.0f);




			//initialize platform
			//std::vector<Platform> platforms;

			//Background

			sf::Texture backgroundState2Texture;
			backgroundState2Texture.loadFromFile("asset/map/map3/map_03.png");
			Platform Background3(&backgroundState2Texture, sf::Vector2f(3840 * 48 / 16, 256 * 48 / 16), sf::Vector2f(3840 * 48 / 32, 256 * 48 / 32));
			//Background Expand
			sf::Texture backgroundState3ExpandTexture;
			backgroundState3ExpandTexture.loadFromFile("asset/map/map3/Expand3.png");
			//left
			Platform Background3ExpandLeft(&backgroundState3ExpandTexture, sf::Vector2f(640 * 48 / 16, 256 * 48 / 16), sf::Vector2f((640 * 48 / 32) - 1920, 256 * 48 / 32));

			//right
			Platform Background3ExpandRight(&backgroundState3ExpandTexture, sf::Vector2f(640 * 48 / 16, 256 * 48 / 16), sf::Vector2f((640 * 48 / 32) + 11520, 256 * 48 / 32));

			// BitMap Init
			std::vector<Bitmap> block0;
			int outdoor[16][240] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,},

		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,},
			};
			// DrawBitMap
			for (int mapX = 0; mapX < 240; mapX++)
			{
				for (int mapY = 0; mapY < 16; mapY++)
				{
					if (outdoor[mapY][mapX] == 1)
					{
						Bitmap outdoor(nullptr, sf::Vector2f(((mapX) * 48) + 24, ((mapY) * 48) + 24), sf::Vector2f(48.f, 48.f));
						block0.push_back(outdoor);
					}
				}
			}
			//BitmapEnemy collinder
			std::vector<Bitmap> blockEnemy;
			int outdoorEnemy[16][240] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},

		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,},

		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,}, };
			// DrawBitMap
			for (int mapX = 0; mapX < 240; mapX++)
			{
				for (int mapY = 0; mapY < 16; mapY++)
				{
					if (outdoorEnemy[mapY][mapX] == 1)
					{
						Bitmap outdoorEnemy(nullptr, sf::Vector2f(((mapX) * 48) + 24, ((mapY) * 48) + 24), sf::Vector2f(48.f, 48.f));
						blockEnemy.push_back(outdoorEnemy);
					}
				}
			}
			//hitbox//  sf::Vector2f(44.0f + 28.0f, 58.0f)
			hitbox
				hitboxMid(0, 0, sf::Vector2f(22, player.GetSize().y), player.GetPosition());
			hitbox
				hitboxLeft(-28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());
			hitbox
				hitboxRight(+28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());

			hitbox
				hitboxEnemy(0, 0, sf::Vector2f(30, 48), enemy1.GetPosition());

			hitbox
				hitboxEnemy2(0, 0, sf::Vector2f(30, 48), enemy2.GetPosition());

			hitbox
				hitboxEnemy3(0, 0, sf::Vector2f(30, 48), enemy3.GetPosition());

			hitbox
				hitboxEnemy4(0, 0, sf::Vector2f(30, 48), enemy4.GetPosition());

			hitbox
				hitboxBoss(0, 0, sf::Vector2f(60, 96), boss.GetPosition());
			//attack
			int cooldown = 0;


			float deltaTime = 0.0f;
			sf::Clock clockW; // clock deltatime


			while (window.isOpen()) {
				deltaTime = clockW.restart().asSeconds();
				if (deltaTime > 1.0f / 60.0f)
					deltaTime = 1.0f / 60.0f;
				sf::Event evnt;
				while (window.pollEvent(evnt))
				{
					switch (evnt.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::Resized:
						ResizeView(window, view);

						break;

					}
				}


				//////////////////////////////////////////////////Item in loop//////////////////////////////////////////

				//////////////////////////////////////////Chest Item///////////////////////////////////////////////////////////

				chestT = chestTime.getElapsedTime().asMilliseconds();
				for (Item& chest : chest) {
					//printf("Update!\n");
					chest.Update(deltaTime);
				}

				Collider tempChest = player.GetColliderHitbox();
				for (Item& chest : chest)
				{
					if (chest.GetCollider().CheckCollisionAttack(tempChest)) {

						chest.setDestroy(true);
						printf(" Hit the chest !!\n");
						ammo += rand() % 3 + 3;
						float ranChestX = rand() % 2000 + 1000;
						float ranChestY = rand() % 300 + 300;
						player.immortalTime = 10.0f;
						chest.setSpawn(true);
						player.immortal = true;
						spawnItemf = spawnItem.getElapsedTime().asSeconds();
						player.imCl.restart();
					}
				}

				for (int i = 0;i < chest.size();i++)
				{
					if (chest[i].isSpawn())
					{
						printf("New chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
						//				chest.push_back(Item(&chest_texture, sf::Vector2f(ranChestX, ranChestY), sf::Vector2f(0, 0)));

						chest.push_back(Item(&chest_texture, sf::Vector2f(rand() % 9737, 0), sf::Vector2f(0, 0)));

						chest[i].setSpawn(false);
					}


				}

				for (int i = 0;i < chest.size();i++)
				{
					if (chest[i].isDestroy())
					{
						chest.erase(chest.begin() + i);
					}
				}
				/////////////////////////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////Hp potion Item///////////////////////////////////////////////////////////
				//sf::Time time = Clockspawn.getElapsedTime();
				Clockspawn.restart();

				for (Item& hpPotion : hpPotion) {
					//printf("Update!\n");
					hpPotion.Update(deltaTime);
				}

				Collider tempPotion = player.GetColliderHitbox();
				for (Item& hpPotion : hpPotion)
				{
					if (hpPotion.GetCollider().CheckCollisionAttack(tempPotion)) {

						hpPotion.setDestroy(true);
						printf(" Hit the Potion !!\n");
						hpPotion.setSpawn(true);
						//potionSpawn = 1;
						if (player.hpPlayer < 3)
						{
							int randompotion;
							randompotion = rand() % 2 + 1;
							if (player.hpPlayer == 2)
							{
								randompotion = 1;
							}
							player.hpPlayer += randompotion;
						}
						printf("hp player %d ", player.hpPlayer);
					}
				}

				//std::cout << itemCooldown << std::endl;

				for (int i = 0;i < hpPotion.size();i++)
				{
					if (hpPotion[i].isSpawn())
					{

						printf("New hpPotion spawn at \n");
						hpPotion.push_back(Item(&hpPotionTexture, sf::Vector2f(rand() % 9737, 0), sf::Vector2f(0, 0)));
						hpPotion[i].setSpawn(false);

					}
				}

				//printf("%f\n", chestT);
				for (int i = 0;i < hpPotion.size();i++)
				{
					if (hpPotion[i].isDestroy())
					{
						hpPotion.erase(hpPotion.begin() + i);
					}
				}

				//////////////////////////////////////////////////////////////////////////////////////////////////////
				//restart//
				if (player.hpPlayer <= 0)
				{
					state = 66;
					goto jumperState;

				}
				/////////////////////////////////////////////////score Update////////////////////////////////////////////////


				scoreText.setPosition(view.getCenter().x - 300, view.getCenter().y - 300);
				scoreText.setFillColor(sf::Color::Red);
				scoreText.setFont(font);
				scoreText.setString(std::to_string(scoreCount));
				scoreText.setOutlineThickness(5.f);
				scoreText.setOutlineColor(sf::Color::White);
				scoreString.setPosition(scoreText.getPosition().x - 120, scoreText.getPosition().y - 1);

				scoreString.setFillColor(sf::Color::Red);
				scoreString.setFont(font);
				scoreString.setString("Score : ");
				scoreString.setOutlineThickness(5.f);
				scoreString.setOutlineColor(sf::Color::White);
				//////////////////////////////////////////////////////////////////////////////////////////////////////

				/////////////////////////////////////////////////score Update////////////////////////////////////////////////
				float staminaCount = (player.stamina / 1500.0) * 100;
				staminaBar.setSize(sf::Vector2f(staminaCount, 15));

				staminaBar.setPosition(view.getCenter().x + 380, view.getCenter().y - 310);
				staminaBar.setFillColor(sf::Color::Red);
				staminaBar.setOutlineThickness(5.f);
				staminaBar.setOutlineColor(sf::Color::Yellow);
				staminaString.setPosition(staminaBar.getPosition().x - 150, staminaBar.getPosition().y - 15);
				staminaString.setFillColor(sf::Color::Red);
				staminaString.setFont(font);
				staminaString.setString("Stamina : ");
				staminaString.setOutlineThickness(5.f);
				staminaString.setOutlineColor(sf::Color::Yellow);

				////////////////////////////////////////////////Bullet string/////////////////////////////////////////////
				//printf("hP :  %d\n", player.hpPlayer);
				BulletCount.setPosition(view.getCenter().x + 450, view.getCenter().y - 200);
				BulletCount.setFillColor(sf::Color::Red);
				BulletCount.setOutlineThickness(5.f);
				BulletCount.setOutlineColor(sf::Color::Yellow);
				BulletCount.setFont(font);
				BulletCount.setString(std::to_string(ammo));

				//////////////////////////////////////////////////////Heart player////////////////////////////////////////////////////// 
				heartPlayer1.setPosition(view.getCenter().x - 100, view.getCenter().y - 300);
				heartPlayer2.setPosition(view.getCenter().x - 70, view.getCenter().y - 300);
				heartPlayer3.setPosition(view.getCenter().x - 40, view.getCenter().y - 300);
				//////////////////////////////////////////////////////Heart Enemy1////////////////////////////////////////////////////// 
				heartEnemy1.setPosition(enemy1.GetPosition().x - 20, enemy1.GetPosition().y - 20);
				heartEnemy2.setPosition(enemy1.GetPosition().x, enemy1.GetPosition().y - 20);
				heartEnemy3.setPosition(enemy1.GetPosition().x + 20, enemy1.GetPosition().y - 20);

				//////////////////////////////////////////////////////Heart Enemy2////////////////////////////////////////////////////// 
				heartEnemy2_1.setPosition(enemy2.GetPosition().x - 20, enemy2.GetPosition().y - 20);
				heartEnemy2_2.setPosition(enemy2.GetPosition().x, enemy2.GetPosition().y - 20);
				heartEnemy2_3.setPosition(enemy2.GetPosition().x + 20, enemy2.GetPosition().y - 20);

				//////////////////////////////////////////////////////Heart Enemy3////////////////////////////////////////////////////// 
				heartEnemy3_1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				heartEnemy3_2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				heartEnemy3_3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////Heart Enemy4////////////////////////////////////////////////////// 
				heartEnemy4_1.setPosition(enemy4.GetPosition().x - 20, enemy4.GetPosition().y - 20);
				heartEnemy4_2.setPosition(enemy4.GetPosition().x, enemy4.GetPosition().y - 20);
				heartEnemy4_3.setPosition(enemy4.GetPosition().x + 20, enemy4.GetPosition().y - 20);
				heartEnemy4_4.setPosition(enemy4.GetPosition().x - 40, enemy4.GetPosition().y - 20);
				heartEnemy4_5.setPosition(enemy4.GetPosition().x + 40, enemy4.GetPosition().y - 20);
				//////////////////////////////////////////////////////Heart Boss////////////////////////////////////////////////////// 
				heartBoss1.setPosition(boss.GetPosition().x - 40, boss.GetPosition().y - 20);
				heartBoss2.setPosition(boss.GetPosition().x - 20, boss.GetPosition().y - 20);
				heartBoss3.setPosition(boss.GetPosition().x, boss.GetPosition().y - 20);
				heartBoss4.setPosition(boss.GetPosition().x + 20, boss.GetPosition().y - 20);
				heartBoss5.setPosition(boss.GetPosition().x + 40, boss.GetPosition().y - 20);
				heartBoss6.setPosition(boss.GetPosition().x - 40, boss.GetPosition().y - 38);
				heartBoss7.setPosition(boss.GetPosition().x - 20, boss.GetPosition().y - 38);
				heartBoss8.setPosition(boss.GetPosition().x, boss.GetPosition().y - 38);
				heartBoss9.setPosition(boss.GetPosition().x + 20, boss.GetPosition().y - 38);
				heartBoss10.setPosition(boss.GetPosition().x + 40, boss.GetPosition().y - 38);
				//////////////////////////////////////////////////////////Heart Enemy3////////////////////////////////////////////////////// 
				////heartEnemy1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				////heartEnemy2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				////heartEnemy3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////////Heart Enemy4////////////////////////////////////////////////////// 
				////heartEnemy1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				////heartEnemy2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				////heartEnemy3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////////Heart Enemy5////////////////////////////////////////////////////// 
				////heartEnemy1.setPosition(enemy3.GetPosition().x - 20, enemy3.GetPosition().y - 20);
				////heartEnemy2.setPosition(enemy3.GetPosition().x, enemy3.GetPosition().y - 20);
				////heartEnemy3.setPosition(enemy3.GetPosition().x + 20, enemy3.GetPosition().y - 20);

				//////////////////////////////////////////////////////Heart Enemy1////////////////////////////////////////////////////// 
				//heartEnemy1.setPosition(enemy1.GetPosition().x - 20, enemy1.GetPosition().y - 40);
				//heartEnemy2.setPosition(enemy1.GetPosition().x, enemy1.GetPosition().y - 40);
				//heartEnemy3.setPosition(enemy1.GetPosition().x + 20, enemy1.GetPosition().y - 40);

				/////////////////////////////////////////////////////ammo player////////////////////////////////////////////////////// 
				ammo1.setPosition(view.getCenter().x + 400, view.getCenter().y - 200);


				/////////////////////////////////////////player && enemy Update && hitboxupdate/////////////////////////////////////////
				sf::Vector2f direction;
				player.Update(deltaTime);
				enemy1.Update(deltaTime);
				enemy2.Update(deltaTime);
				enemy3.Update(deltaTime);
				enemy4.Update(deltaTime);
				boss.Update(deltaTime);

				hitboxMid.Update(0, 0, player.GetPosition());
				hitboxLeft.Update(-28, 0, player.GetPosition());
				hitboxRight.Update(+28, 0, player.GetPosition());

				//enemy
				hitboxEnemy.Update(0, 0, enemy1.GetPosition());
				hitboxEnemy2.Update(0, 0, enemy2.GetPosition());
				hitboxEnemy3.Update(0, 0, enemy3.GetPosition());
				hitboxEnemy4.Update(0, 0, enemy4.GetPosition());
				hitboxBoss.Update(0, 0, boss.GetPosition());
				//COLLISION BULLET WITH ENEMY01//
				Collider temp = enemy1.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp)) {

						//printf("Bullet Destroy!!\n");
						bullet.setDestroy(true);
						enemy1.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", enemy1.hp);

					}
				}
				////touch groundDeath////
				/*Player*/
				if (player.GetColliderHitbox().CheckCollisionAttack(groundDeath))
				{
					state = 66;
					goto jumperState;
					//player.SetPosition(sf::Vector2f(200.0f, 0.0f));
				}
				//potion
				for (Item& hpPotion : hpPotion)
				{
					if (hpPotion.GetCollider().CheckCollisionAttack(groundDeath))
					{
						hpPotion.setDestroy(true);
						printf("Spawnnnn Potion ground death !!\n");
						hpPotion.setSpawn(true);
					}
				}
				//chest
				for (Item& chest : chest)
				{
					if (chest.GetCollider().CheckCollisionAttack(groundDeath))
					{
						chest.setDestroy(true);
						printf("Spawnnnnn chest fround death !!\n");
						chest.setSpawn(true);
					}
				}



				//enemy set die
				if (enemy1.GetHp() <= 0)
				{
					enemy1.setDie(true);
				}
				//bullet disapear//
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}
				//printf("player x:%f y: %f\n", player.GetPosition().x, player.GetPosition().y);
				if (enemy1.isDie() == true)
				{
					scoreCount += 100;
					spawnT = spawnTime.getElapsedTime().asMilliseconds();
					if (spawnT > 2000.0)
					{
						printf("Enemy spwan!!\n");
						enemy1.hp = 3;
						enemy1.SetPosition(sf::Vector2f(11400.0f, 90.0f));
						spawnTime.restart();
						enemy1.setDieSpawn(true);
						enemy1.setDie(false);
					}
				}

				//Enemy2
					//COLLISION BULLET WITH ENEMY02//
				Collider temp2 = enemy2.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp2)) {

						bullet.setDestroy(true);
						enemy2.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", enemy2.hp);
					}
				}
				//enemy set die
				if (enemy2.GetHp() <= 0)
				{
					enemy2.animationEnemy.dead = true;
					enemy2.setDie(true);
				}
				//bullet disapear//
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}

				if (enemy2.isDie() == true)
				{

					scoreCount += 100;

					spawnT = spawnTime.getElapsedTime().asMilliseconds();
					if (spawnT > 2000.0)
					{
						printf("Enemy spwan!!\n");
						enemy2.hp = 3;
						enemy2.SetPosition(sf::Vector2f(11400.0f, 90.0f));
						enemy2.setDie(false);
						enemy2.setDieSpawn(true);
						spawnTime.restart();
					}
				}

				//Enemy3
				//COLLISION BULLET WITH ENEMY02//
				Collider temp3 = enemy3.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp3)) {

						bullet.setDestroy(true);
						enemy3.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", enemy3.hp);
					}
				}
				//enemy set die
				if (enemy3.GetHp() <= 0)
				{
					enemy3.animationEnemy.dead = true;
					enemy3.setDie(true);
				}
				//bullet disapear//
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}

				if (enemy3.isDie() == true)
				{

					scoreCount += 100;

					spawnT = spawnTime.getElapsedTime().asMilliseconds();
					if (spawnT > 2000.0)
					{
						printf("Enemy spwan!!\n");
						enemy3.hp = 3;
						enemy3.SetPosition(sf::Vector2f(11400.0f, 90.0f));
						enemy3.setDie(false);
						enemy3.setDieSpawn(true);
						spawnTime.restart();
					}
				}
				//Enemy4
						//COLLISION BULLET WITH ENEMY02//
				Collider temp4 = enemy4.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(temp4)) {

						bullet.setDestroy(true);
						enemy4.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", enemy4.hp);
					}
				}
				//enemy set die
				if (enemy4.GetHp() <= 0)
				{
					enemy4.animationEnemy.dead = true;
					enemy4.setDie(true);
				}
				//bullet disapear//
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}

				if (enemy4.isDie() == true)
				{

					scoreCount += 100;

					spawnT = spawnTime.getElapsedTime().asMilliseconds();
					if (spawnT > 2000.0)
					{
						printf("Enemy spwan!!\n");
						enemy4.hp = 5;
						enemy4.SetPosition(sf::Vector2f(11400.0f, 90.0f));
						enemy4.setDie(false);
						enemy4.setDieSpawn(true);
						spawnTime.restart();
					}
				}


				//Boss
					//COLLISION BULLET WITH ENEMY02//
				Collider tempBoss = boss.GetColliderHitbox();
				for (Bullet& bullet : bullet)
				{
					if (bullet.GetCollider().CheckCollisionAttack(tempBoss)) {

						bullet.setDestroy(true);
						boss.setHp(bullet.GetDmg());
						printf(" Hit Gun enemy hp : %d  \n", boss.hp);
					}
				}
				//enemy set die
				if (boss.GetHp() <= 0)
				{
					boss.animationEnemy.dead = true;
					boss.setDie(true);
				}
				//bullet disapear//
				for (int i = 0;i < bullet.size();i++)
				{
					if (bullet[i].isDestroy())
					{
						bullet.erase(bullet.begin() + i);
					}
				}

				if (boss.isDie() == true)
				{

					scoreCount += 100;

					spawnT = spawnTime.getElapsedTime().asMilliseconds();
					if (spawnT > 2000.0)
					{
						printf("Enemy spwan!!\n");
						boss.hp = 3;
						boss.SetPosition(sf::Vector2f(11400.0f, 90.0f));
						boss.setDie(false);
						boss.setDieSpawn(true);
						spawnTime.restart();
					}
				}
				////////////////////////////////////////////////player collider with platform////////////////////////////////////////////////

				////BitMap Collision WITH PLAYER ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						player.OnCollision(direction);
				//Enemy1
					////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy1.GetCollider(), direction, 1.0f))
						enemy1.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(enemy1.GetCollider(), direction, 1.0f))
					{
						enemy1.OncollisionEnemy(direction);
						enemy1.velocity.x = -enemy1.velocity.x;
						enemy1.velocity.x = 0.0f;
					}
				//Enemy2
						////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy2.GetCollider(), direction, 1.0f))
						enemy2.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(enemy2.GetCollider(), direction, 1.0f))
					{
						enemy2.OncollisionEnemy(direction);
						enemy2.velocity.x = -enemy2.velocity.x;
						enemy2.velocity.x = 0.0f;
					}

				//Enemy3
									////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy3.GetCollider(), direction, 1.0f))
						enemy3.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(enemy3.GetCollider(), direction, 1.0f))
					{
						enemy3.OncollisionEnemy(direction);
						enemy3.velocity.x = -enemy3.velocity.x;
						enemy3.velocity.x = 0.0f;
					}
				//Enemy4
							////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(enemy4.GetCollider(), direction, 1.0f))
						enemy4.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(enemy4.GetCollider(), direction, 1.0f))
					{
						enemy4.OncollisionEnemy(direction);
						enemy4.velocity.x = -enemy4.velocity.x;
						enemy4.velocity.x = 0.0f;
					}

				//Boss
							////BitMap Collision WITH ENEMY ////
				for (Bitmap& block0 : block0)
					if (block0.getCollider().CheckCollision(boss.GetCollider(), direction, 1.0f))
						boss.OncollisionEnemy(direction);
				////BitMapEnemy Collision WITH ENEMY ////
				for (Bitmap& blockEnemy : blockEnemy)
					if (blockEnemy.getCollider().CheckCollision(boss.GetCollider(), direction, 1.0f))
					{
						boss.OncollisionEnemy(direction);
						boss.velocity.x = -boss.velocity.x;
						boss.velocity.x = 0.0f;
					}

				////BitMap Collision WITH CHEST ////
				for (Bitmap& block0 : block0)
				{
					for (Item& chest : chest)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(chest.GetCollider(), direction, 1.0f))
							chest.OnCollision(direction);
				}

				////BitMap Collision WITH HP POTION ////
				for (Bitmap& block0 : block0)
				{
					for (Item& hpPotion : hpPotion)// == for(int i =0 ; i<platforms.size();i++)

						if (block0.getCollider().CheckCollision(hpPotion.GetCollider(), direction, 1.0f))
							hpPotion.OnCollision(direction);
				}
				//IMMORTAL CLOCK//
				sf::Clock imCl;
				float immortalCl;
				immortalCl = imCl.getElapsedTime().asSeconds();
				//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy1.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{
					enemy1.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy1.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;
						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}
				//enemy2
						//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy2.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{

					enemy2.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy2.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;

						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}
				//enemy3
						//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy3.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{

					enemy3.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy3.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;

						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}

				//enemy4
						//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (enemy4.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{

					enemy4.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					enemy4.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;

						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}
				//Boss
						//COLLISION ENEMY WITH PLAYER HURT HP--//
				if (boss.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
				{

					boss.OncollisionEnemy(direction);
					player.velocity.x = 0.0f;
					boss.velocity.x = 0.0f;
					player.currentHp = player.hpPlayer;
					player.immortalTime = 1.0f;
					if (player.immortal == false)
					{
						/*player.hpLock = 1;*/
						player.hpPlayer--;
						player.immortal = true;

						player.velocity.x = 0.0f;
						player.animation.run = false;
						player.animation.idle = false;
						player.animation.jump = false;
						player.animation.attack1 = false;
						player.animation.crashEnemy = true;
						player.animation.hurt = true;
						player.animation.currentImage.x = 3;
					}

					if (player.immortal == true && immortalCl > 0.5)
					{
						player.animation.hurt = false;

						player.animation.crashEnemy = false;
						player.hpPlayer = player.currentHp;
						player.immortal = false;

					}
				}

				////////////////////////////////////////////////attack method//////////////////////////////////////////////
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && player.attackState == 0)
				{
					player.velocity.x = 0;
					player.attackState = 1;

					player.animation.attack1 = true;
					player.start = clock();

				}

				////////////////////////////////////////////////attack method cooldown ////////////////////////////////////////////////

				if (player.attackState > 0)
				{
					if (player.attackState == 1)
					{
						if (hitboxMid.getGlobalbounds().intersects(enemy1.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									enemy1.hp--;
									printf(" Hit enemy hp :%d    \n", enemy1.hp);

									if (enemy1.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}
						}
						//enemy2
						if (hitboxMid.getGlobalbounds().intersects(enemy2.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									enemy2.hp--;
									printf(" Hit enemy hp :%d    \n", enemy2.hp);

									if (enemy2.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}

						//enemy3
						if (hitboxMid.getGlobalbounds().intersects(enemy3.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									enemy3.hp--;
									printf(" Hit enemy hp :%d    \n", enemy3.hp);

									if (enemy3.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}
						//enemy4
						if (hitboxMid.getGlobalbounds().intersects(enemy4.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									enemy4.hp--;
									printf(" Hit enemy hp :%d    \n", enemy4.hp);

									if (enemy4.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}
						//Boss
						if (hitboxMid.getGlobalbounds().intersects(boss.GetGlobalbounds()))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
							{

								cooldown++;
								if (cooldown == 1 || cooldown == 2 || cooldown == 3)
								{
									//player.attackState = 1;
									player.velocity.x = 0;
									player.attackState = 2;
									//std::cout << "Hit" << std::endl;
									scoreCount += 10;
									boss.hp--;
									printf(" Hit enemy hp :%d    \n", boss.hp);

									if (boss.hp <= 0)
									{
										//std::cout << "Score " << std::endl;
									}
								}
							}

						}
			}
			double dif = (double)(player.end - player.start) / CLOCKS_PER_SEC; // ??????????????? //0.6  0.4  0.4
			if (dif > 0.6f)
			{
				cooldown = 0;
				player.attackState = 0;

			}
			else if (dif > 0.4f)
			{
				player.animation.attack1 = false;
				player.attackState = 2;

			}
			else if (dif <= 0.4f)
			{
				//printf("%lf    ", dif);

				// std::cout << "Cooldown" << std::endl;
			}
		}
		////////////////////////////////////////////////attack method//////////////////////////////////////////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && player.attackState == 0)
		{
			player.velocity.x = 0;
			player.attackState = 1;

			player.animation.attack1 = true;
			player.start = clock();

		}
		/////////////////////////////////////////////////////bullet update /////////////////////////////////////////////////////
		anibull = anibullTime.getElapsedTime().asSeconds();
		if (ammo > 0) {
			if (anibull > 0.4)
			{
				bull = bullTime.getElapsedTime().asMilliseconds();
				if (bull > 900)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
					{
						player.velocity.x = 0;
						player.shootState = 1;
						player.animation.finishShoot == false;
						player.animation.shoot = true;
						player.start = clock();
						ammo--;
						if (player.faceRight == true)
						{
							bullet.push_back(Bullet(&bullet_texture, sf::Vector2u(1, 1), 0, sf::Vector2f(player.GetPosition().x + 25, player.GetPosition().y), sf::Vector2f(500, 0)));
							bullTime.restart();
							anibullTime.restart();
						}
						else if (player.faceRight == false)
						{
							bullet.push_back(Bullet(&bullet_textureRight, sf::Vector2u(1, 1), 0/*imageCOunt*/, sf::Vector2f(player.GetPosition().x - 25/* +10 ??????????????????????????????*/, player.GetPosition().y), sf::Vector2f(-500, 0)));
							bullTime.restart();
							anibullTime.restart();
						}

					}
				}
			}

		}
		for (int i = 0;i < bullet.size();i++)
		{
			if (bullet[i].isDestroy())
			{
				bullet.erase(bullet.begin() + i);
			}
		}
		for (Bullet& bullet : bullet) {
			//printf("Update!\n");
			bullet.Update(deltaTime);
		}
		////////////////////////////////////////////////shoot method cooldown ////////////////////////////////////////////////
		if (player.shootState > 0)
		{
			if (player.shootState == 1)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
				{

					cooldown++;
					if (cooldown == 1 || cooldown == 2 || cooldown == 3)
					{
						player.velocity.x = 0;
						player.shootState = 2;
					}
				}
			}

			double dif = (double)(player.end - player.start) / CLOCKS_PER_SEC;

			if (dif > 0.8f)
			{
				cooldown = 0;
				player.shootState = 0;

			}
			else if (dif > 0.6f)
			{
				player.animation.attack1 = false;
				player.shootState = 2;

			}

			else if (dif <= 0.6f)
			{
			}
		}
		////////////////////////////////////////////////setview (must follow Update)////////////////////////////////////////////////
		view.setCenter(player.GetPosition().x, 380);
		////////////////////////////////////////////////set background slide////////////////////////////////////////////////
		for (Background& background : backgrounds)
			background.Update(deltaTime);
		///////////////////////////////////////////////////////////////////clear//////////////////////////////////////////////////////////////////////
		window.clear(sf::Color(150, 200, 200));
		/////////////////////////////////////////Draw bg/////////////////////////////////////////
		for (Background& background : backgrounds)
			background.Draw(window);
		Background3.Draw(window);
		Background3ExpandLeft.Draw(window);
		Background3ExpandRight.Draw(window);
		/////////////////////////////////////////bound around player && enemy/////////////////////////////////////////
		bound.setPosition(player.GetPosition().x, player.GetPosition().y);
		boundE.setPosition(enemy1.GetPosition().x, enemy1.GetPosition().y);



		/*for (Bitmap& blockEnemy : blockEnemy)
			blockEnemy.draw(window);*/

			/////////////////////////////////////////set view/////////////////////////////////////////
		window.setView(view);


		/////////////////////////////////////////draw  everything/////////////////////////////////////////
		//hitboxEnemy.Draw(window);
		//hitboxMid.Draw(window);
		//hitboxLeft.Draw(window);
		//hitboxRight.Draw(window);
		//hitboxBoss.Draw(window);
		//Draw player

		//Draw player heart
		if (player.hpPlayer > 2)
		{
			window.draw(heartPlayer3);
		}
		if (player.hpPlayer > 1)
		{
			window.draw(heartPlayer2);
		}
		if (player.hpPlayer > 0)
		{
			window.draw(heartPlayer1);
		}

		player.Draw(window);
		//draw Enemy1
		if (enemy1.isDieSpawn() == false)
		{
			if (enemy1.hp > 0) {
				enemy1.Draw(window);
				//Draw enemy1 heart
				if (enemy1.hp > 2)
				{
					window.draw(heartEnemy3);
				}
				if (enemy1.hp > 1)
				{
					window.draw(heartEnemy2);
				}
				if (enemy1.hp > 0)
				{
					window.draw(heartEnemy1);
				}

			}
		}
		//draw Enemy2
		if (enemy2.isDieSpawn() == false)
		{
			if (enemy2.hp > 0 ) {
				enemy2.Draw(window);
				//Draw enemy2 heart
				if (enemy2.hp > 2)
				{
					window.draw(heartEnemy2_3);
				}
				if (enemy2.hp > 1)
				{
					window.draw(heartEnemy2_2);
				}
				if (enemy2.hp > 0)
				{
					window.draw(heartEnemy2_1);
				}
			}

		}
		//draw Enemy3
		if (enemy3.isDieSpawn() == false)
		{
			if (enemy3.hp > 0) {
				enemy3.Draw(window);
				//Draw enemy2 heart
				if (enemy3.hp > 2)
				{
					window.draw(heartEnemy3_3);
				}
				if (enemy3.hp > 1)
				{
					window.draw(heartEnemy3_2);
				}
				if (enemy3.hp > 0)
				{
					window.draw(heartEnemy3_1);
				}
			}

		}
		//draw semi boss
		if (enemy4.isDieSpawn() == false)
		{
			if (enemy4.hp > 0) {
				enemy4.Draw(window);
				//Draw enemy1 heart

				if (enemy4.hp > 4)
				{
					window.draw(heartEnemy4_5);
				}
				if (enemy4.hp > 3)
				{
					window.draw(heartEnemy4_4);
				}
				if (enemy4.hp > 2)
				{
					window.draw(heartEnemy4_3);
				}
				if (enemy4.hp > 1)
				{
					window.draw(heartEnemy4_2);
				}
				if (enemy4.hp > 0)
				{
					window.draw(heartEnemy4_1);
				}

			}
		}

		//draw Boss
		if (boss.isDieSpawn() == false)
		{
			if (boss.hp > 0) {
				boss.Draw(window);
				//Draw enemy1 heart
				if (boss.hp > 9)
				{
					window.draw(heartBoss10);
				}
				if (boss.hp > 8)
				{
					window.draw(heartBoss9);
				}
				if (boss.hp > 7)
				{
					window.draw(heartBoss8);
				}
				if (boss.hp > 6)
				{
					window.draw(heartBoss7);
				}
				if (boss.hp > 5)
				{
					window.draw(heartBoss6);
				}
				if (boss.hp > 4)
				{
					window.draw(heartBoss5);
				}
				if (boss.hp > 3)
				{
					window.draw(heartBoss4);
				}
				if (boss.hp > 2)
				{
					window.draw(heartBoss3);
				}
				if (boss.hp > 1)
				{
					window.draw(heartBoss2);
				}
				if (boss.hp > 0)
				{
					window.draw(heartBoss1);
				}

			}
		}

		////////////////////////////////////////////////draw platforms////////////////////////////////////////////////
		//for (Platform& platform : platforms)
		//	platform.Draw(window);

		////////////////////////////////////////////////draw bullet////////////////////////////////////////////////
		for (Bullet& bullet : bullet) {

			bullet.Draw(window);
		}

		////////////////////////////////////////////////Draw ITEM ////////////////////////////////////////////////////////////////////
		for (Item& hpPotion : hpPotion) {

			hpPotion.Draw(window);
		}
		for (Item& chest : chest) {

			chest.Draw(window);
		}
		window.draw(groundDeath);
		window.draw(ammo1);

		//window.draw(hpPotion);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		window.draw(scoreText);
		window.draw(scoreString);
		window.draw(staminaString);
		window.draw(staminaText);
		window.draw(staminaBar);
		window.draw(BulletCount);

		//itemCooldown += time.asSeconds();


		//display//
		window.display();
		}//while isOpen
		
}//if (state ==3)
		
		//state restart
		if (state == 66)
	{
		//////////    Manu State    //////////
		//sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Journey");
		RestartMenu Remenu(window.getSize().x, window.getSize().y);
		sf::Texture textureRe;
		if (!textureRe.loadFromFile("asset/RestartDeath.png")) {
			//handle error
		}
		sf::Sprite backgroundRestart;
		backgroundRestart.setTexture(textureRe);
		backgroundRestart.setPosition(VIEW_WIDTH / 2-255, VIEW_HEIGHT / 2-370);
		backgroundRestart.scale(0.09, 0.09);
		view.setCenter(VIEW_WIDTH / 1.5f, VIEW_HEIGHT / 2.f);
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::KeyReleased:
					switch (evnt.key.code) {
					case sf::Keyboard::W:
						Remenu.MoveUp();
						break;
					case sf::Keyboard::S:
						Remenu.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (Remenu.GetPressedItem()) {
						case 0:
							std::cout << "Restart has been preesed" << std::endl;
							state = 2;
							checkRestart = true;
							break;
						case 1:
							window.close();
							break;

						}
					}
					break;

				case sf::Event::Closed:
					window.close();
					break;
				}

			}
			window.clear();

			////////////////////////////////////////////////setview (must follow Update)////////////////////////////////////////////////
			view.setCenter(player.GetPosition());
			window.setView(view);
			window.draw(backgroundRestart);
			//Background1.Draw(window);
			Remenu.draw(window);
			window.display();
			//Restart 
			if (checkRestart == true)
			{
				checkRestart = false;
				break;
			}
		}//while isOpen

	}// if state (66)
	
	}// while (1)
	return 0;
}
