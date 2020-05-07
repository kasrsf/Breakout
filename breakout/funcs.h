#ifndef FUNCS_H_
#define FUNCS_H_

#include "brick.h"

//Initialization
bool init();

//File Loading
bool load_files();

bool close( Brick* bricks[] );

bool set_bricks( Brick* bricks[] );

#endif