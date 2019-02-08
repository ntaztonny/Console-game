#pragma once
#include "Character.h"

#ifndef MAGE_H
#define MAGE_H


class Mage: public Character
{
public:
	Mage (Level *l, DrawEngine *de, int index, float x = 1, float y = 1, int characterLives = 1, char keySpell = ' ',char Up = 'w', char Down = 's', char Left = 'a', char Right = 'd');
protected:

	bool keyPress(char c);
private:

	void castSpell(void);
	char spellKey;


};

#endif
