#pragma once
#include "GlobalVariable.h"
#include"SFML/Graphics.hpp"
#include"Bullet.h"
#include "Enemy.h"
class Player
{
	bool dead;
	short reload_timer;
	unsigned short posX;
	unsigned short posY;
	std::vector<Bullet> bullets;

	sf::Sprite bulletSprite;
	sf::Texture bulletTexture;
	sf::Sprite sprite;
	sf::Texture texture;
	short score;
	


	public:
		Player();

		void reset();

		bool getDead() const;



		
		void draw(sf::RenderWindow& window);
		
		int getBulletsize();

		
		void update();
		void checkEnemyHit(std::vector<Enemy>& lst_enemy);
		void checkPlayerHit(std::vector<Bullet>& lst_bullet);
		void checkEnemyHitEnd(std::vector<Enemy>& lst_enemy);
		void checkHit(Bullet& p_bullet);
		short getScore();
		void setScore();
};

