#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <GL/freeglut.h>
#define SQUARE_WIDTH 15
#define START_X 305
#define START_Y 800
#define NEXT_X 500
#define NEXT_Y 500
#define RIGHT_WALL 400
#define LEFT_WALL 200
static const float COLOR_ARRAY[7][3] = { {1,0,0},
    {0,1,0},
    {0,0,1},
    {1,0,1},
    {1,1,0},
    {0,1,1},
    {1,.5,0}
};

