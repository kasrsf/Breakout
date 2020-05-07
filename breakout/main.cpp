#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "funcs.h"
#include "bar.h"
#include "globals.h"
#include "constants.h"
#include "brick.h"
#include "ball.h"
#include "brickList.h"

int main( int argc, char* args[] )
{
	if (init() == false)
	{
		printf( "Could not initialize SDL!\n" );
	}
	else
	{
	//	Brick* brickSet[ NUM_OF_BRICKS ];

/*		if (load_files() == false)
		{
			printf( "Could not load files!\n" );
		}
		else
		{
*/			bool quit = false;

			Bar player;

			BrickList bl;

			Ball ball(&player, &bl);


			SDL_Event e;

			
			while (!quit)
			{
				while ( SDL_PollEvent( &e ) != 0 )
				{
					if ( e.type == SDL_QUIT )
					{
						quit = true;
					}

					player.handle_event( e );
				}

				player.move();
				ball.move();

				//clear screan
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( renderer );

				player.render();
				ball.render();

				bl.render();
				//update screen
				SDL_RenderPresent( renderer );
			}
	//	}
	}

	return 0;
}