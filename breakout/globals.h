#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL2/SDL.h>
#include "texture.h"
#include "constants.h"

// the window we render to
extern SDL_Window *window;

// the window renderer
extern SDL_Renderer *renderer;

extern Texture brickTexture;
#endif