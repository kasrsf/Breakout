#include "brick.h"
#include "constants.h"
//#include "globals.h"
#include "texture.h"
#include <SDL2/SDL.h>

Brick::Brick( int x, int y, int t )
{
	next = NULL;
	prev = NULL;

	brickAtts.x = x;
	brickAtts.y = y;
	brickAtts.w = BRICK_WIDTH;
	brickAtts.h = BRICK_HEIGHT;

	type = t; 
}

void Brick::render(Texture* t, SDL_Rect clip)
{
	t->render( brickAtts.x, brickAtts.y, &clip );
}

int Brick::get_type()
{
	return type;
}

Brick* Brick::get_next()
{
	return next;
}

Brick* Brick::get_prev()
{
	return prev;
}

void Brick::set_next(Brick* b)
{
	next = b;
}

void Brick::set_prev(Brick* b)
{
	prev = b;
}

bool Brick::has_collided(SDL_Rect ball)
{
	if (brickAtts.y + brickAtts.h <= ball.y)
	{
		return false;
	}

	if (brickAtts.y >= ball.y + ball.h)
	{
		return false;
	}

	if (brickAtts.x + brickAtts.w <= ball.x)
	{
		return false;
	}

	if (brickAtts.x >= ball.x + ball.w)
	{
		return false;
	}

	return true;
}