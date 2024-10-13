#pragma once
#include"Enemy.h"

class EnemyManager
{
private:
	std::vector<Enemy> enemies;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Sprite enemySprite;
	sf::Sprite bulletSprite;
	sf::Texture bulletTexture;
	std::vector<Bullet> bullets;
	int move_timer;
	int reload_timer;
	bool directionX;
	bool directionY;
	short difficulty;
	
	public:
		EnemyManager();
		EnemyManager(sf::Texture& texture1,sf::Texture& texture2);
		void update(sf::RenderWindow& renderWindow);
		std::vector<Bullet>& getBullets();
		std::vector<Enemy>& getEnemies();
		void reset();

		void raiseDifficuly();

		short getDifficuly();
		

};

