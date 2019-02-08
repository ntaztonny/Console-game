#include "stdafx.h"
#include"Sprite.h"
#include "Level.h"



Sprite::Sprite(Level *l, DrawEngine *de, int index, float x, float y, int numLives)
{
	spriteLevel = l;
	drawSprite = de;
	Lives = numLives;
	SpriteIndex = index;
	position.x = x;
	position.y = y;
	facingDirection.x = 1;
	facingDirection.y = 1;

	classID = Sprite_CLASSID;

}
Sprite::~Sprite()
{
		//erase the sprite
	SpriteErase(position.x, position.y);
}

vector Sprite::getPosXY(void)
{
	return position;
}

float Sprite::getY(void)
{
	return position.y;

}
float Sprite::getX(void)
{
	return position.x;
}
bool Sprite::isAlive(void)
{
	return (Lives > 0);
}

int Sprite::getLives(void)
{
	return Lives;
}

void Sprite::addLivies(int addValue)
{
	Lives += addValue;
}

void Sprite::removeLivies(int addValue)
{
	Lives -= addValue;
}

void Sprite::SpriteDraw(float x, float y)
{
	drawSprite->DrawSprite(SpriteIndex, (int)x, (int)y);
}
void Sprite::SpriteErase(float x, float y)
{
	drawSprite->eraseSprite((int)x, (int)y);
}

bool Sprite::move(float x, float y)
{	
	int xpos = int (position.x + x);
	int ypos = int (position.y + y);

	if (isvalidLevelMove(xpos, ypos))
	{
		SpriteErase(position.x, position.y);

		position.x += x;
		position.y += y;

		facingDirection.x = x;
		facingDirection.y = y;
		SpriteDraw(position.x, position.y);

		return true;
	}
	return false;
}

bool Sprite::isvalidLevelMove(int xpos, int ypos)
{
	if (spriteLevel->level[xpos][ypos] != TILE_WALL)
	   return true;
	
	return false;
}

void Sprite::idleUpdate(void)
{
	
}

