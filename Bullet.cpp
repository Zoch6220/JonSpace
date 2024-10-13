#include "Bullet.h"

Bullet::Bullet(float p_step_x,float p_step_y,short p_x,short p_y)
{
	death = false;
	step_x = p_step_x;
	step_y = p_step_y;
	x = p_x;
	y = p_y;
	
		
	
}

void Bullet::update(){
	if (!death) {
		x += step_x;
		y += step_y;

		

if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
			death = true;
	
	
	}

}
