OBJS = main.o bar.o ball.o brick.o funcs.o globals.o texture.o brickList.o
CC = g++
COMPILER_FLAGS = -w -c -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

OBJ_NAME = breakout

Breakout : $(OBJS)
	$(CC) $(OBJS) $(LINKER_FLAGS) -o Breakout

main.o : main.cpp funcs.h bar.h globals.h constants.h ball.h brick.h brickList.h
	$(CC) $(COMPILER_FLAGS) main.cpp

bar.o : bar.cpp bar.h texture.h constants.h
	$(CC) $(COMPILER_FLAGS) bar.cpp

ball.o : ball.cpp ball.h constants.h texture.h bar.h brickList.h
	$(CC) $(COMPILER_FLAGS) ball.cpp

brick.o : brick.h brick.cpp constants.h globals.h texture.h
	$(CC) $(COMPILER_FLAGS) brick.cpp

brickList.o : brickList.h brickList.cpp brick.h constants.h texture.h
	$(CC) $(COMPILER_FLAGS) brickList.cpp

funcs.o : funcs.h funcs.cpp globals.h constants.h brick.h
	$(CC) $(COMPILER_FLAGS) funcs.cpp

globals.o : globals.h globals.cpp texture.h constants.h
	$(CC) $(COMPILER_FLAGS) globals.cpp

texture.o : texture.h texture.cpp globals.h
	$(CC) $(COMPILER_FLAGS) texture.cpp

clean:
	rm *.o Breakout