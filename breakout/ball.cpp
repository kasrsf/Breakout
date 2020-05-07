#include <SDL2/SDL.h>
#include "ball.h"
#include "constants.h"
#include "bar.h"
#include "brickList.h"

Ball::Ball(Bar* p, BrickList* bl)
{
	if ( !load() )
	{
		printf( "Unable to Load Ball Texture!\n");
		return;
	}

	ballAtts.x = BALL_STARTX;
	ballAtts.y = 400;

	ballAtts.w = BALL_WIDTH;
	ballAtts.h = BALL_HEIGHT;

	velX = BALL_START_VEL;
	velY = BALL_START_VEL;

	player = p;
	brickSet = bl;
}

bool Ball::load()
{
	return texture.load_from_file("./Textures/ball.bmp");
}

void Ball::move()
{
	ballAtts.x += velX;

	if ( ( ballAtts.x < 0 ) || ( ballAtts.x > SCREEN_WIDTH ) || check_collision())
	{
		ballAtts.x -= velX;

		//change velo
		velX *= -1;
	}

	ballAtts.y += velY;

	if ( ( ballAtts.y < 0 ) || check_collision())
	{
		ballAtts.y -= velY;

		velY *= -1;
	}

	if ( ballAtts.y > SCREEN_HEIGHT ) 
	{
		ballAtts.x = BALL_STARTX;
		ballAtts.y = 400;
	}
}

void Ball::render()
{
	texture.render( ballAtts.x, ballAtts.y);
}

bool Ball::check_collision()
{
	return (player->has_collided(ballAtts) || brickSet->has_collided(ballAtts));
}

Ball::~Ball()
{
	texture.free();
}