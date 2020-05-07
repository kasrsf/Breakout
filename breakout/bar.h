#ifndef BAR_H
#define BAR_H

#include <SDL2/SDL.h>
#include "constants.h"
#include "texture.h"

class Bar
{
public:
	static const int BAR_WIDTH = 80;
	static const int BAR_HEIGHT = 15;

	static const int BAR_VEL = 10;

	static const int BOUNDS_OFFSET = 10;

	static const int BAR_STARTX = ( SCREEN_WIDTH - BAR_WIDTH ) / 2;
	static const int BAR_STARTY = SCREEN_HEIGHT - BOUNDS_OFFSET - BAR_HEIGHT;

	Bar();
	~Bar();
	
	bool load();

	void handle_event( SDL_Event &e );
	void move();
	void render();

	bool has_collided(SDL_Rect);
private:
	int posX ,posY;
	int velX;

	Texture texture;
};

#endif