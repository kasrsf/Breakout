#include <fstream>
#include <stdio.h>
#include "brickList.h"
#include "texture.h"
#include "brick.h"
#include "constants.h"

BrickList::BrickList()
{
	first = NULL;
	last = NULL;

	if (!load())
	{
		printf("Failed To Load Bricks Texture!\n");
		return;
	}	
	if (!set_bricks())
	{
		printf("Failed To Set Bricks!\n");
		return;
	}
}

bool BrickList::load()
{
	if (!texture.load_from_file("./Textures/brick.bmp"))
	{
		return false;
	}

	brickClips[ BRICK_RED ].x = 0;
	brickClips[ BRICK_RED ].y = 0;
	brickClips[ BRICK_RED ].w = BRICK_WIDTH;
	brickClips[ BRICK_RED ].h = BRICK_HEIGHT;

	brickClips[ BRICK_GREEN ].x = 0;
	brickClips[ BRICK_GREEN ].y = 20;
	brickClips[ BRICK_GREEN ].w = BRICK_WIDTH;
	brickClips[ BRICK_GREEN ].h = BRICK_HEIGHT;

	brickClips[ BRICK_YELLOW ].x = 0;
	brickClips[ BRICK_YELLOW ].y = 40;
	brickClips[ BRICK_YELLOW ].w = BRICK_WIDTH;
	brickClips[ BRICK_YELLOW ].h = BRICK_HEIGHT;

	brickClips[ BRICK_ORANGE ].x = 0;
	brickClips[ BRICK_ORANGE ].y = 60;
	brickClips[ BRICK_ORANGE ].w = BRICK_WIDTH;
	brickClips[ BRICK_ORANGE ].h = BRICK_HEIGHT;

	return true;
}

bool BrickList::set_bricks()
{
	int x = BRICKS_STARTX;
	int y = BRICKS_STARTY;

	std::fstream map("./map");

	if ( map == NULL )
	{
		printf("Unable to Load Map File!\n");
		return false;
	}

	for ( int i = 0; i < NUM_OF_BRICKS; i++ )
	{
		int brickType = 0;

		map >> brickType;

		if( map.fail() )
		{
			//Stop loading map
			printf( "Error loading map: Unexpected end of file!\n" );
			return false;
		}
		if ( ( brickType >= 0) && ( brickType < BRICK_COLORS ) )
		{
			add_brick(x, y, brickType);
		}
		else
		{
			printf("Error loading map: Invalid Brick Type!\n");
			return false;
		}

		x += BRICK_WIDTH + DIST_BET_BRICKS;

		if ( x >= BRICKS_ENDX )
		{
			x = BRICKS_STARTX;
			y += BRICK_HEIGHT + DIST_BET_BRICKS;
		}
	}

	map.close();

	return true;
}

void BrickList::add_brick(int x, int y, int type)
{
	Brick* newBrick = new Brick(x, y, type);
	if (last != NULL)
	{
		last->set_next(newBrick);
		newBrick->set_prev(last);
		last = newBrick;
	}
	else
	{
		last = newBrick;
		first = newBrick;
	}
}	

void BrickList::render()
{
	Brick* tmp = first;

	while (tmp != NULL)
	{
		tmp->render(&texture, brickClips[tmp->get_type()]);
		tmp = tmp->get_next();
	}
}

bool BrickList::has_collided(SDL_Rect ball)
{
	Brick *tmp = first;

	while (tmp != NULL)
	{
		if (tmp->has_collided(ball))
		{
			if (tmp == first)
			{
				if (tmp->get_next() != NULL)
				{
					first = tmp->get_next();
					tmp->get_next()->set_prev(NULL);
				}
				else
				{
					first = NULL;
					//NO MORE BRICKS. GAME OVer
				}
				tmp->set_next(NULL);
			}

			if (tmp == last)
			{
				if (tmp->get_prev() != NULL)
				{
					last = tmp->get_prev();
					tmp->get_prev()->set_next(NULL);
				}
				else
				{
					last = NULL;
					// NO MORE BRICKS.
				}
				tmp->set_prev(NULL);
			}

			if ((tmp->get_next() != NULL) && (tmp->get_prev() != NULL))
			{
				tmp->get_prev()->set_next(tmp->get_next());
				tmp->get_next()->set_prev(tmp->get_prev());
	
				tmp->set_prev(NULL);
				tmp->set_next(NULL);
			}
		

			return true;
		}

		tmp = tmp->get_next();
	}

	return false;
}

BrickList::~BrickList()
{
	texture.free();
}