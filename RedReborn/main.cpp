#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
//#include "C:\RedReborn\RedReborn\Background.h"
#include "animation.h"
#include "Platform.h"
#include "Player.h"
#include "enemy.h"
#include "Bullet.h"
#include "hitbox.h"
#include "Item.h"
#include "Background.h"
#include "Bitmap.h"

static const float VIEW_HEIGHT = 720.0f;
static const float VIEW_WIDTH = 1080.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{	
	/////////////////////////Render window ////////////////
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Adventure", sf::Style::Close | sf::Style::Resize);
	///////////////////////////////////////Item/////////////////////////////////
	/********************************** Chest ********************************/
	std::vector<Item> chest;
	sf::Texture chest_texture;
	if (!chest_texture.loadFromFile("asset/object/ChestRed.png"))
	{

	}
	sf::Clock chestTime;
	float chestT = 0.0f; //?????????????? ??????? bullet
	sf::Clock spawnItem;
	float spawnItemf = 0.0f;

	srand(time(NULL));
	int ranChestX = rand() % 1000;
	int ranChestY = rand() % 620;
	float ranChestx = ranChestX / 10.f;
	float ranChesty = ranChestY / 10.f;

	printf("chest spawn at x: %f y : %f\n", ranChestx, ranChestY);
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

	printf("potion spawn at x: %f y : %f\n", ranhpPotionx, ranhpPotionY);
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
	int scoreCount = 0;
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
	std::vector<enemy> enemies;
	sf::Texture enemyBlack;
	sf::Texture enemyGrey;
	sf::Texture enemyGolden;
	enemies.push_back(enemy(&enemyGolden, sf::Vector2u(8, 8), 0.2f, 100.0f, 1000.0f, 620.0f));
	enemies.push_back(enemy(&enemyGrey, sf::Vector2u(8, 8), 0.2f, 100.0f, 1200.0f, 620.0f));
	//////////////////////////////////////bullet declare//////////////////////////
	std::vector<Bullet> bullet;
	sf::Texture bullet_texture;
	if (!bullet_texture.loadFromFile("asset/arrow2.png"))
	{

	}
	sf::Clock bullTime;
	float bull = 0.0f; //?????????????? ??????? bullet

	int ammo = 5;
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
//Background
	sf::Texture backgroundState2Texture;
	backgroundState2Texture.loadFromFile("asset/map1.png");
	Platform Background1(&backgroundState2Texture, sf::Vector2f(3840 * 48 / 16, 256 * 48 / 16), sf::Vector2f(3840 * 48 / 32, 256 * 48 / 32));
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

		/////////////////////////////////////////////////////bullet update /////////////////////////////////////////////////////
		////////bull = bullTime.getElapsedTime().asMilliseconds();
		////////if(bull > 800)
		////////{
		////////	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		////////	{
		////////		/*player.velocity.x = 0;
		////////		player.attackState = 1;

		////////		player.animation.attack1 = true;
		////////		player.start = clock();*/
		////////		if (player.faceRight == true)
		////////		{
		////////			bullet.push_back(Bullet(&bullet_texture, sf::Vector2u(1, 1), 0/*imageCOunt*/, sf::Vector2f(player.GetPosition().x + 10/* +10 ??????????????????????????????*/, player.GetPosition().y),sf::Vector2f(500,0)));
		////////			bullTime.restart();
		////////		}
		////////		else if (player.faceRight == false)
		////////		{
		////////			bullet.push_back(Bullet(&bullet_texture, sf::Vector2u(1, 1), 0/*imageCOunt*/, sf::Vector2f(player.GetPosition().x - 10/* +10 ??????????????????????????????*/, player.GetPosition().y), sf::Vector2f(-500, 0)));
		////////			bullTime.restart();
		////////		}
		////////		
		////////	}
		////////}
		////////for (Bullet& bullet : bullet) {
		////////	//printf("Update!\n");
		////////	bullet.Update(deltaTime);
		////////}
		/*for (enemy& enemy : enemies) {
			enemy.Update(deltaTime);
		}*/
		//////////////////////////////////////////////////////////////////////////////////////////////////////
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
				float ranChestX = rand() % 2000 + 1000;
				float ranChestY = rand() % 300 + 300;
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

		//////////////////////////////////////////////////////////////////////////////////////////////////////

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

		if (enemies.size() > 0)
		{
			enemies[0].Draw(window);
			enemies[1].Draw(window);
		}
		////////////////////////////////////////////////Draw ITEM ////////////////////////////////////////////////////////////////////
		for (Item& hpPotion : hpPotion) {

			hpPotion.Draw(window);
		}
		for (Item& chest : chest) {

			chest.Draw(window);
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

		//Background1.Draw(window);

	}
	return 0;

}
