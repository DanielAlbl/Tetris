#include <iostream>
#include <ctime>
#include <GL/freeglut.h>

using namespace std;

const int SQUARE_WIDTH =  15;
const int HEIGHT       =  48;
const int WIDTH        =  14;
const int START_X      = 305;
const int START_Y      = 800;
const int NEXT_X       = 500;
const int NEXT_Y       = 500;
const int RIGHT_WALL   = 400;
const int LEFT_WALL    = 200;

const float COLOR_ARRAY[7][3] = { 
	{1,0,0},
    {0,1,0},
    {0,0,1},
    {1,0,1},
    {1,1,0},
    {0,1,1},
    {1,.5,0}
};

