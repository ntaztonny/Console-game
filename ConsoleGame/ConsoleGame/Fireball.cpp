#include"stdafx.h"

#include "Fireball.h"

Fireball::Fireball(Level *lvl, DrawEngine *engine, int index, float x, float y, float xDir, float yDir, int lifeNum) :
	Sprite(lvl, engine, index, x, y, lifeNum)
{
	facingDirection.x = xDir;
	facingDirection.y = yDir;

	classID = Fireball_CLASSID;

}

void Fireball::idleUpdate(void)
{
	std::list<Sprite* >::iterator Iter;

	if (Sprite::move(facingDirection.x, facingDirection.y))
	{
		for (Iter = spriteLevel->npc.begin(); Iter != spriteLevel->npc.end(); Iter++)
		{
			if ((*Iter)->classID != classID && (int)(*Iter)->Sprite::getX() == (int)position.x && (int)(*Iter)->Sprite::getY() == (int)position.y)
			{
				(*Iter)->addLivies(-1);
				addLivies(-1);
			}
			
		}
	}

	else 
	{
		Sprite::Lives = 0;
	}


	
}