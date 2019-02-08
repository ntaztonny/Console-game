#pragma once
#include "DrawEngine.h"
#include "Character.h"
#include "Level.h"
#include"Mage.h"



#ifndef GAMELOOP_H
#define GAMELOOP_H


class Gameloop
{
public:		
	bool gameRun(void);


protected:
	bool getInput(char * c);
	void timerUpdate(void);

private:
	double startTime;
	double endTime;
	double frameCount;

	DrawEngine gameEngine;
	Mage* player;
	Enemy* enemy;
	Level * lvl;
	

};



#endif