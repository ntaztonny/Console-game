#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "DrawEngine.h"

class Level;

enum
{
	Sprite_CLASSID,
	Character_CLASSID,
	Enemy_CLASSID,
	Fireball_CLASSID,
	Mage_CLASSID
};
struct vector
{
	float x;
	float y;
};

class Sprite
{
public:
	Sprite(Level *l, DrawEngine *de, int index, float x = 1.0, float y = 1.0, int numLives = 1);
	~Sprite();

	vector getPosXY(void);
	float getY(void);
	float getX(void);   
	bool isAlive(void);
	int getLives(void);
	virtual void addLivies(int addValue = 1);
	void removeLivies(int removeValue = 1);
	void SpriteDraw(float x, float y);
	void SpriteErase(float x, float y);

	virtual void idleUpdate(void);

	virtual bool move(float x,float y);
	int classID;
	Level* spriteLevel;


protected:

	DrawEngine * drawSprite;
	int SpriteIndex;
	vector  position;
	int Lives;
	vector facingDirection;
	bool isvalidLevelMove(int xpos, int ypos);


};

#endif