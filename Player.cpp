#include "Player.h"

Player::Player() {
	reset();
	texture.loadFromFile("Player.png");
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	bulletTexture.loadFromFile("PlayerBullet.png");
	bulletSprite.setTexture(bulletTexture);
	reload_timer = 0;
	score = 0;
}

void Player::reset() {
	if(dead==true)
		score = 0;
	dead = false;
	posX = (SCREEN_WIDTH -PLAYER_SIZE)/ 2;
	posY = SCREEN_HEIGHT - 2*PLAYER_SIZE;
	bullets.clear();
}

void Player::draw(sf::RenderWindow& window) {
	if (!dead) {
		sprite.setPosition(posX, posY);
		window.draw(sprite);

		for (Bullet& bull : bullets) {
			bulletSprite.setPosition(bull.x, bull.y);

			window.draw(bulletSprite);

		}
}

}
bool Player::getDead() const {
	return dead;
}
int Player::getBulletsize() {
	return bullets.size();
}
void Player::update() {
	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && posX > 0-PLAYER_SIZE)
		posX = std::max<int>(posX - PLAYER_SPEED_MOVE, PLAYER_SIZE);
	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && posX < SCREEN_WIDTH - PLAYER_SIZE)
		posX = std::min<int>(PLAYER_SPEED_MOVE+posX,SCREEN_WIDTH-2*PLAYER_SIZE);
if(reload_timer==0){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		reload_timer = RELOAD_DUR;
		bullets.push_back(Bullet(0, -BULLET_SPEED, posX+(PLAYER_SIZE/2), posY - (PLAYER_SIZE / 2)));
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
		i.y -= BULLET_SPEED;
	}


}
void Player::checkEnemyHit(std::vector<Enemy>& lst_enemy) {
	bool hit = false;
	for (auto& enemy : lst_enemy) {
		for (auto& bullet : bullets) {
			hit = enemy.checkHit(bullet);
			if (hit) {
				setScore();
			}
		}
			
	
	}
	
	lst_enemy.erase(std::remove_if(lst_enemy.begin(), lst_enemy.end(), [](Enemy& enem) {return enem.getDeath(); }) ,lst_enemy.end());
}
void Player::checkPlayerHit(std::vector<Bullet>& lst_bullet) {
	
	for (auto& bullet : lst_bullet) {
		checkHit(bullet);
	}
}


void Player::checkEnemyHitEnd(std::vector<Enemy>& lst_enemy)
{
	for (auto& enemy : lst_enemy) {
		if (enemy.getY() > SCREEN_HEIGHT - PLAYER_SIZE) {
			dead = true;
			break;
		}
		
	}

}
void Player::checkHit(Bullet& p_bullet) {
	int hitboxSize = 8;
	int offSet = 0;
	int hitBoxX = posX + offSet;
	int hitBoxY = posY + offSet;
	int hitBoxW = hitboxSize;
	int hitBoxH = hitboxSize;

	if (!dead && !p_bullet.death && sf::IntRect(hitBoxX, hitBoxY, PLAYER_SIZE, PLAYER_SIZE).intersects(sf::IntRect(p_bullet.x, p_bullet.y, BULLET_SIZE_X, BULLET_SIZE_Y)))
	{
		dead = true;
		p_bullet.death = true;
	}
	}
short Player::getScore()  {
return score;
}

void Player::setScore() {
	 score+=10;
}