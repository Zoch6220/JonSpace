#pragma once
#include <cmath>
#include<iostream>
#include<algorithm>

//screen size 
constexpr unsigned short SCREEN_HEIGHT = 180*2;
constexpr unsigned short SCREEN_WIDTH   =320*2;

// size of the sprite

constexpr unsigned short PLAYER_SIZE  = 16*2;
constexpr unsigned char PLAYER_SPEED_MOVE = 2*4;

constexpr unsigned short ENEMY_SIZE = 16*2;
constexpr unsigned char ENEMY_SPEED_MOVE_X = 1;
constexpr unsigned char ENEMY_SPEED_MOVE_Y = 1;
constexpr unsigned short BLOCK_SIZE = 1;
;
constexpr unsigned short ENEMY_ANIMATION_DUR = 60;

constexpr unsigned short BULLET_SPEED=2;
constexpr unsigned short BULLET_SIZE_X = 2*2;
constexpr unsigned short BULLET_SIZE_Y = 1;
constexpr unsigned short RELOAD_DUR =15;
constexpr unsigned short ENEMY_RELOAD_DUR = 50;
constexpr unsigned short MOVE_DUR = 1;
