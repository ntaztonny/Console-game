#include"stdafx.h"
#include"Character.h"


Character::Character(Level *lvl,  DrawEngine *de, int index, float x, float y, int characterLives, char Up, char Down, char Left, char Right) :
	Sprite(lvl, de, index, x, y, characterLives)
{
	 UpKey = Up;
	 DownKey = Down;
	 LeftKey = Left;
	 RightKey = Right;

	 classID = Character_CLASSID;
}

void Character::addLivies(int addValue)
{
	Sprite::addLivies(addValue);

	if (Sprite::isAlive())
	{	
		position.x = 1;
		position.y = 1;
		move(5, 5);
	}
		
}

bool Character::keyPress(char c)
{
	if (c == UpKey || c == 065)
	{
		return move(0, -1);
	}
	else if (c == DownKey || c == 066)
	{
		return move(0, 1);

	}
	else if (c == LeftKey || c == 067)
	{
		return move(-1, 0);
		
	}
	else if (c == RightKey )
	{
		return move(1, 0);
	}
	return false;
}