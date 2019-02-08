#pragma once

#ifndef DRAW_ENGINE_H
#define DRAW_ENGINE_H

class DrawEngine 
{
public: DrawEngine(int sizex = 100, int sizey =30);
		~DrawEngine();

		 int CreateSprite(int index, char c);
		 void deleteSprite(void);
		 void DrawSprite(int index, int posx, int posy);
		 void eraseSprite(int posx, int posy);
		 void setMap(char**);
		 void createMapImage(int index, char c);
		 void drawBackground(void);
		 char **map;


private: void gotoxy(int posx, int posy);
		 void cursorVisibility(bool visible);

protected:
	int sizex, sizey;
	char spriteArray[16];
	char mapArray[16];


};

#endif
