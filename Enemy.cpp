#include "Enemy.h"



Enemy::Enemy(sf::Texture& texture1, sf::Texture& texture2,short p_x, short p_y)
{
	death = false;
	directionX = true;
	direction= direction = 0 == (y / PLAYER_SIZE) % 2 ? -1 : 1;
	x = p_x;
	y = p_y;
    move_timer = 0;
    isFrame1 = true;
	this->texture1 = texture1;
	this->texture2 = texture2;
	timeranimation = 0;
	sprite.setTexture(texture1);
	
}
short Enemy::getX()
{
	return x;
}

void Enemy::draw(sf::RenderWindow& window)
{	
	if (timeranimation == 0)
	{
		timeranimation = ENEMY_ANIMATION_DUR;
		if (isFrame1)
		{
			sprite.setTexture(texture1);
			isFrame1 = false;
		}
		else
		{
			sprite.setTexture(texture2);
			isFrame1 = true;
		}
	}
	else
	{
		timeranimation--;
	}
	sprite.setPosition(x, y);
	

	window.draw(sprite);

	
}

void Enemy::move(short p_X,short p_Y) {

	x=p_X;
	y=p_Y;

}
void Enemy::moveDown() {
	y+=ENEMY_SPEED_MOVE_Y;
}
bool Enemy::checkHit(Bullet& p_bullet) {
	int hitboxSize = 16;
	int offSet=(PLAYER_SIZE-hitboxSize)/2;
	int hitBoxX=x+offSet;
	int hitBoxY=y+offSet;
	int hitBoxW=hitboxSize;
	int hitBoxH = hitboxSize;

	if (!death && !p_bullet.death && sf::IntRect(hitBoxX, hitBoxY, hitBoxW, hitBoxH).intersects(sf::IntRect(p_bullet.x, p_bullet.y, BULLET_SIZE_X, BULLET_SIZE_Y)))
	{

		death = true;
		p_bullet.death = true;
		return true;
	}
	return false;
}
bool Enemy::getDeath()
{
	return death;
}
short Enemy::getY()
{
	return y;
}

