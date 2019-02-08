#pragma once

#include"Level.h"
#include "DrawEngine.h"
#include"Sprite.h"
#include "Character.h"

#ifndef FIREBALL_H
#define FIREBALL_H

class Fireball : public Sprite
{
public:

	Fireball(Level *lvl, DrawEngine *engine, int index, float x, float y, float xDir, float yDir, int lifeNum = 1);
protected:

	void idleUpdate(void);
private:


};
#endif
