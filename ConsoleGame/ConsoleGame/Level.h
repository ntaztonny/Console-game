#pragma once
#include "DrawEngine.h"
#include "Sprite.h"
#include <list>
#include"Enemy.h"

#ifndef LEVEL_H
#define LEVEL_H

class Character;


enum
{
	SPRITE_ENEMY,
	SPRITE_PLAYER,
	SPRITE_FIREBALL

};
enum
{
	TILE_EMPTY,
	TILE_WALL
};

class Level
{
public:

	Level(DrawEngine *de, int width = 100, int height = 30);
	~Level();

	void addPlayer(Character *player);
	bool keyDown(char c);
	void drawLevel(void);
	void update(void);

	void addEnemies(int num);
	void addNPC(Sprite *spr);

	char **level;

protected:
	
	void createLevel(void);

private:
	int width;
	int height;
	DrawEngine *engine;
	Character *player;
	friend class Sprite;

	
public:
	std::list<Sprite *> npc;
	std::list<Sprite *>::iterator iter;
	


};

#endif 
