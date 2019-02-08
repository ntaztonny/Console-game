#include "stdafx.h"
#include "DrawEngine.h"
#include <Windows.h>
#include <iostream>

DrawEngine::DrawEngine(int x, int y)
{
	sizex = x;
	sizey = y;
	cursorVisibility(false);

	map = 0;
}
DrawEngine::~DrawEngine()
{
	cursorVisibility(true);
	gotoxy(0, sizey);

}

int DrawEngine::CreateSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		spriteArray[index] = c;
		return index;
	}

	return -1;
}

void DrawEngine::deleteSprite(void)
{
	// implement this later
	
}

void  DrawEngine::DrawSprite(int index, int posx, int posy)
{
	gotoxy(posx, posy);
	std::cout << spriteArray[index];
}
		   
void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	std::cout << ' ';
}

void DrawEngine::gotoxy(int posx, int posy)
{
	HANDLE OutputHandle;
	COORD coordpos;

	OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordpos.X = posx;
	coordpos.Y = posy;

	SetConsoleCursorPosition(OutputHandle, coordpos);
}

void DrawEngine::cursorVisibility(bool visible)
{
	HANDLE VisibleHandle;

	VisibleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO CursorvisibilityInfo;

	CursorvisibilityInfo.bVisible = visible;
	CursorvisibilityInfo.dwSize = 1;

	SetConsoleCursorInfo(VisibleHandle, &CursorvisibilityInfo);
}

void DrawEngine::setMap(char **data)
{
	map = data;
}

void DrawEngine::createMapImage(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		mapArray[index] = c;
	}

}


void DrawEngine::drawBackground(void)
{	
	if (map)
	{
		for (int j = 0; j < sizey; j++)
		{	
			gotoxy(0, j);

			for (int i = 0; i < sizex; i++)
			{
				std::cout << mapArray[map[i][j]];

			}
		}
	}
}