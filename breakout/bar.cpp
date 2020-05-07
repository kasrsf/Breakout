#include "bar.h"
#include "constants.h"
#include <SDL2/SDL.h>

Bar::Bar()
{
	if ( !load() )
	{
		printf("Failed To Load Bar Texture!\n");
		return;
	}

	posX = BAR_STARTX;
	posY = BAR_STARTY;

	velX = 0;
}

bool Bar::load()
{
	return texture.load_from_file( "./Textures/bar.bmp" );
}

void Bar::handle_event( SDL_Event &e )
{
	// if a key was pressed
	if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_RIGHT: velX += BAR_VEL; break;
			case SDLK_LEFT: velX -= BAR_VEL; break;
		}
	}

	// if a key was released
	if ( e.type == SDL_KEYUP && e.key.repeat == 0 )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_RIGHT: velX -= BAR_VEL; break;
			case SDLK_LEFT: velX += BAR_VEL; break;
		}
	}
}

void Bar::move()
{
	posX += velX;
	if ( ( posX < BOUNDS_OFFSET ) || ( posX + BAR_WIDTH > SCREEN_WIDTH - BOUNDS_OFFSET ) )
		posX -= velX;
}

void Bar::render()
{
	SDL_Rect scaleRect = { 0, 0, BAR_WIDTH, BAR_HEIGHT };
	texture.render( posX, posY , NULL, &scaleRect );
}

bool Bar::has_collided(SDL_Rect ball)
{
	if (posY + BAR_HEIGHT <= ball.y)
	{
		return false;
	}

	if (posY >= ball.y + ball.h)
	{
		return false;
	}

	if (posX + BAR_WIDTH <= ball.x)
	{
		return false;
	}

	if (posX >= ball.x + ball.w)
	{
		return false;
	}

	return true;
}

Bar::~Bar()
{
	texture.free();
}