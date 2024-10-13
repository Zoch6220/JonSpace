#pragma once
#include"SFML/Graphics.hpp"
#include "GlobalVariable.h"
#include "Bullet.h"
#include<algorithm>
class Enemy
{
	bool directionX;
	bool directionY;
	short direction;
	short x;
	short y;
	sf::Sprite sprite;
	short timeranimation;
	short move_timer;
	bool death;
	bool isFrame1;
	sf::Texture texture1;
	sf::Texture texture2;

public:
	Enemy(sf::Texture& texture, sf::Texture& texture2,short p_x, short p_y);
	void draw(sf::RenderWindow& window);
	
	void move(short p_X, short p_Y);
	void moveDown();
	bool checkHit(Bullet& p_bullet);
	bool getDeath();
	short getY();
	short getX();
	
};

