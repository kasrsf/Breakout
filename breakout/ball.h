#ifndef BALL_H
#define BALL_H

#include "constants.h"
#include "texture.h"
#include "bar.h"
#include "brickList.h"

class Ball
{
public:
	static const int BALL_WIDTH = 10;
	static const int BALL_HEIGHT = 10;

	static const int BALL_START_VEL = 2;

	static const int BALL_STARTX = ( SCREEN_WIDTH - BALL_WIDTH ) / 2;

	Ball(Bar*, BrickList*);
	~Ball();

	bool load();

	void move();

	void render(); 

	bool check_collision();

private:
	Texture texture;

	SDL_Rect ballAtts;
	double velX, velY;

	Bar *player;
	BrickList *brickSet;
};

#endif