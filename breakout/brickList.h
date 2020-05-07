#ifndef BRICKLIST_H
#define BRICKLIST_H

#include <SDL2/SDL.h>
#include "brick.h"
#include "constants.h"
#include "texture.h"

class BrickList
{
public:
	static const int NUM_OF_BRICKS = 80;

	static const int BRICK_COLORS = 4;
	static const int BRICK_RED = 0;
	static const int BRICK_GREEN = 1;
	static const int BRICK_YELLOW = 2;
	static const int BRICK_ORANGE = 3;

	static const int BRICKS_STARTX = 15;
	static const int BRICKS_ENDX = ( 10 * BRICK_WIDTH );

	static const int BRICKS_STARTY = 50;

	static const int DIST_BET_BRICKS = 1;

	BrickList();
	~BrickList();

	bool load();
	bool set_bricks();
	
	void add_brick(int x, int y, int type);

	void render();

	bool has_collided(SDL_Rect);
private:
	Brick *first, *last;

	Texture texture;
	SDL_Rect brickClips[ BRICK_COLORS ];
};

#endif