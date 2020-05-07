#ifndef BRICK_H
#define BRICK_H

#include <SDL2/SDL.h>
#include "texture.h"

class Brick
{
public:
	Brick( int x, int y, int t );

	void render(Texture* t, SDL_Rect clip);

	int get_type();

	Brick* get_next();
	Brick* get_prev();
	
	void set_next(Brick* b);
	void set_prev(Brick*);

	bool has_collided(SDL_Rect);
private:
	SDL_Rect brickAtts;

	int type;

	Brick *next, *prev;
};

#endif