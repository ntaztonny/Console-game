#pragma once

#include "DrawEngine.h"
#include "Sprite.h"
#include "Level.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character: public Sprite
{
public:
	Character(Level *l, DrawEngine *de, int index, float x = 1, float y = 1, int characterLives = 1, char Up = 'w', char Down = 's', char Left = 'a', char Right = 'd');
	virtual void addLivies(int addValue = 1);


	virtual bool keyPress(char c);

protected:
	char UpKey;
	char DownKey;
	char LeftKey;
	char RightKey;
};

#endif
