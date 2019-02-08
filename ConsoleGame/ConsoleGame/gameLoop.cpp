#include "stdafx.h"
#include "gameLoop.h"
#include <iostream>
#include<conio.h>
#include <windows.h>

#define FrameRateControl 180



  bool Gameloop::gameRun(void)
{	
	


	gameEngine.createMapImage(TILE_EMPTY, ' ');
	gameEngine.createMapImage(TILE_WALL, 254);

	gameEngine.CreateSprite(SPRITE_PLAYER, 1);
	gameEngine.CreateSprite(SPRITE_ENEMY, '$');
	gameEngine.CreateSprite(SPRITE_FIREBALL, '*');


	lvl = new Level(&gameEngine, 100, 30);

	player = new Mage(lvl, &gameEngine, SPRITE_PLAYER);
	enemy = new Enemy(lvl, &gameEngine, SPRITE_ENEMY);

	lvl->drawLevel();
	lvl->addPlayer(player);
	player->move(0, 0);
	lvl->addEnemies(5);

	char key = ' ';
	frameCount = 0;
	startTime = timeGetTime();
	endTime = 0;

	

	while (key != 'q')
	{	
		while (!getInput(&key))
		{	
			timerUpdate();

		}

		//key = 'd';
		lvl->keyDown(key);
		//std::cout << std::endl;
		//std::cout<< "you have pressed " << key << std::endl;
		
	}

	delete lvl;

	//std::cout << frameCount/((timeGetTime() - startTime)/1000) << " fps" << std::endl;

	//std::cout << "You have ended the game!" << std::endl;
	return true;
}

bool Gameloop::getInput(char * c)
{
	if (_kbhit())
	{ 
		*c = _getch();
		return true;
	}
	return false;
}


void Gameloop::timerUpdate(void)
{
	double currentTime = timeGetTime() - endTime;

	if (currentTime < FrameRateControl) // want to control the game at 60fps
		return;


	lvl-> update();

	frameCount++;

	endTime = timeGetTime();

}