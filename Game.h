#pragma once
#include"SFML/Graphics.hpp"
#include"GlobalVariable.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyManager.h"
class Game
{
private:
	sf::Text text;
	sf::Font font;
	//texture
	sf::Texture starshipTexture;
	sf::Texture backTexture;
	sf::Texture laserTexture;
	sf::Texture alienTexture;
	sf::Texture enemytexture1;
	sf::Texture enemytexture2;
	sf::Vector2u windowSize;
	sf::Vector2u starshipSize;
	sf::Texture logo;
	sf::Sprite logoSprite;
	sf::Sprite backGround;
	sf::Texture playTexture;
	sf::Sprite playSprite;
	sf::Texture exitTexture;
	sf::Sprite exitSprite;
	sf::Text scoreText;
	Player player;
	EnemyManager enemyManager;
	bool gameStart;
	public:
	Game();
	
	void run();
};

