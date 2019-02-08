#include "stdafx.h"


#include <stdlib.h>

#include "Level.h"
#include "Character.h"


Level::Level(DrawEngine *de, int w, int h)
{
	engine = de;
	width = w;
	height = h;

	player = 0;

	level = new char* [width];

	for (int i = 0; i < width; i++)
		level[i] = new char[height];
	
	createLevel();

	 engine->setMap(level);
}
Level::~Level()
{
	for (int i = 0; i < width; i++)
		delete [] level[i];

	delete[] level;

	for (iter = npc.begin(); iter != npc.end(); iter++)
		delete *iter;
}

void Level::createLevel(void)
{
	for (int w = 0; w < width; w++)
	{
		for (int h = 0; h < height; h++)
		{	
			if(h == 0 || h == (height-1) || w == 0 || w == (width -1))
				level[w][h] = TILE_WALL;
			
			else
			{
				int random = rand() % 100;

				if (random < 90 || ((height < 3) && (width < 3)))
				{
					level[w][h] = TILE_EMPTY;
				}

				else
					level[w][h] = TILE_WALL;
			}

		}
	}
}
void Level::addPlayer(Character *p)
{
	
	player = p;

}
bool Level::keyDown(char c)
{
	if (player)
	{
		player->keyPress(c);
	}
	
	return false;
}
void Level::drawLevel(void)
{
	engine->drawBackground();
}

void Level::update(void)
{
	for (iter = npc.begin(); iter != npc.end(); iter++)
	{
		(*iter)->idleUpdate();

		if ((*iter)->isAlive() == false)
		{
			Sprite *temp = *iter;

			iter--;
			delete temp;

			npc.remove(temp);
		}
	}
}

void Level::addEnemies(int num)
{
	int i = num;


	while (i > 0)
	{
		
		int xpos = int(float(rand() % width) + 1);
		int ypos = int(float(rand() % height) + 1);

		if (level[xpos][ypos] != TILE_WALL)
		{
			Enemy *temp = new Enemy(this, engine, SPRITE_ENEMY, float(xpos), float(ypos));
			temp->addGoal(player);

			addNPC((Sprite *)temp);

			i--;
		}


	}
}
void Level::addNPC(Sprite *spr)
{
	npc.push_back(spr);

}
