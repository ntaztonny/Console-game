
#include "stdafx.h"
#include "Enemy.h"
#include"Level.h"
#include"Character.h"
#include <math.h>
#include <stdlib.h>

Enemy::Enemy(Level *l, DrawEngine *de, int s_index, float x, float y, int i_lives):
	Sprite(l,de,s_index,x,y,i_lives)
{
	goal = 0;
	classID = Enemy_CLASSID;


}
Enemy::~Enemy()
{
}

void Enemy::addGoal(Character *g)
{
	goal = g;
}
bool Enemy::move(float x, float y)
{
	int xpos = (int)(position.x + x);
	int ypos = (int)(position.y + y);

	if (isvalidLevelMove(xpos, ypos))
	{
		//sprite dont run into each other!
		std::list <Sprite *>::iterator Iter;
		for (Iter = spriteLevel->npc.begin(); Iter != spriteLevel->npc.end(); Iter ++)
		{
			if ((*Iter) != this  && (int)(*Iter)->getX() == xpos && (int)(*Iter)->getY() == ypos)
			{
				return false;
			}
		}
		//-----------------------------------------------
		SpriteErase(position.x, position.y);

		position.x += x;
		position.y += y;

		facingDirection.x = x;
		facingDirection.y = y;
		SpriteDraw(position.x, position.y);

		if ((int)goal->Character::getX() == position.x && (int)goal->Character::getY() == position.y)
		{
			goal->Character::addLivies(-1);

		}

		return true;
	}
	return false;
}
void Enemy::idleUpdate(void)
{
	if (goal)
		simulateAI();
}

void Enemy::simulateAI(void)
{
	vector goal_pos = goal->getPosXY();
	vector direction;

	direction.x = goal_pos.x - position.x;
	direction.y = goal_pos.y - position.y;

	float mag = float(sqrt(direction.x*direction.x + direction.y*direction.y ))+5;

	direction.x = direction.x / mag;
	direction.y = direction.y / mag; 

	if (!move(direction.x, direction.y))
	{
		while (!move(float(rand()%3 -1), float(rand()%3 - 1)))
		{

		}
	}



}