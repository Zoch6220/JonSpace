#include "EnemyManager.h"
EnemyManager::EnemyManager() {
	bulletTexture.loadFromFile("EnemyBullet.png");
	bulletSprite.setTexture(bulletTexture);
	enemySprite.setTexture(texture1);
	directionX = true;
	directionY = false;
	reset();
	difficulty = 1;
}
EnemyManager::EnemyManager(sf::Texture& texture1, sf::Texture& texture2) {
	bulletTexture.loadFromFile("EnemyBullet.png");
	bulletSprite.setTexture(bulletTexture);
	this->texture1=texture1;
	this->texture2=texture2;
	enemySprite.setTexture(texture1);
	directionX = true;
	directionY = false;
	reset();
	difficulty= 1;
	
}

void EnemyManager::update(sf::RenderWindow& renderWindow) {


	move_timer = MOVE_DUR;

	bool hitEdge = false;

	// First, check if any enemy hits the screen edge
	for (auto& enemy : enemies) {
		int x = enemy.getX();
		int y = enemy.getY();
		if ((directionX && x > SCREEN_WIDTH - PLAYER_SIZE) || (!directionX && x < 0)) {
			hitEdge = true;
			break;
		}
	}

	// If any enemy hit the screen edge, reverse X direction and move down
	if (hitEdge) {
		directionX = !directionX;
		directionY = true;
	}
	else {
		directionY = false;
	}

	// Then, update all enemies' positions
	for (auto& enemy : enemies) {
		int x = enemy.getX();
		int y = enemy.getY();
		if (directionX) {
			x += ENEMY_SPEED_MOVE_X+difficulty;
		}
		else {
			x -= ENEMY_SPEED_MOVE_X + difficulty;
		}
		if (directionY) {
			y += ENEMY_SPEED_MOVE_Y + difficulty;
		}
		enemy.move(x, y);
		enemy.draw(renderWindow);
	}
	if (reload_timer <= 0) {
		reload_timer = ENEMY_RELOAD_DUR/difficulty;
		if (enemies.size() != 0) {
			int test = rand() % enemies.size();

			bullets.push_back(Bullet(0, +BULLET_SPEED, enemies[test].getX() + (PLAYER_SIZE / 2), enemies[test].getY() - (PLAYER_SIZE / 2)));
			
		}

	}
	else {
		reload_timer--;
	}

	bullets.erase(
		std::remove_if(
			bullets.begin(),
			bullets.end(),
			[](Bullet& bul) {
				bul.update();
				return bul.death == 1;
			}
		),
		bullets.end()
				);
	for (auto& i : bullets) {
		i.y += BULLET_SPEED;
	}
	for (auto& i : bullets) {
		
		bulletSprite.setPosition(i.x, i.y);
		renderWindow.draw(bulletSprite);
	}

}
std::vector<Bullet>& EnemyManager::getBullets() {
	return bullets;
}

std::vector<Enemy>& EnemyManager::getEnemies()
{
	return enemies;
}
void EnemyManager::reset() {
	enemies.clear();
	bullets.clear();
	int idx = 0;
	int idy = 0;
	int enemySpacing =5;
	move_timer = 0;
	for (int i = 0; i < 60; i++) {
		if (i % 15 == 0) {
			idx = 0;
			idy++;
		}
		int enemyX = idx * (PLAYER_SIZE + enemySpacing);
		int enemyY = idy * (PLAYER_SIZE + enemySpacing);
		Enemy enemy(texture1,texture2 ,enemyX, enemyY);
		enemies.push_back(enemy);
		idx++;
	}
}
void EnemyManager::raiseDifficuly() {
	difficulty++;
}
short EnemyManager::getDifficuly() {
	return difficulty;
}

