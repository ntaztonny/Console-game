#include "stdafx.h"
#include"Mage.h"
#include"Fireball.h"
#include"Sprite.h"

Mage::Mage(Level *l, DrawEngine *de, int index, float x, float y, int characterLives, char keySpell, char Up, char Down, char Left, char Right) :
	Character(l, de, index, x, y, characterLives, Up, Down, Left, Right)
{

	spellKey = keySpell;
	classID = Mage_CLASSID;

}

bool Mage::keyPress(char c)
{
	bool val = Character::keyPress(c);  

	if (val == false)
	{
		if ( c == spellKey)
		{
			castSpell();
			return true;
		}
	}

	return val;
}

void Mage::castSpell(void)
{
	Fireball* temp;

	temp = new Fireball(spriteLevel, drawSprite, SPRITE_FIREBALL, facingDirection.x + position.x, facingDirection.y + position.y, facingDirection.x, facingDirection.y);
	spriteLevel->addNPC(temp);



}

