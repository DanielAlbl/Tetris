#include "bentDick.h"

BentDick::BentDick(int x1, int y1) : Shape(x1,y1)
{
    squares[1].up();
    squares[2].up();
    squares[2].right();
    squares[3].up();
    squares[3].up();    
    squares[3].right();   
}

void BentDick::rotateClock()
{
    switch(orientation % 2)
    {
        case 0: rotate0();
            break;
        case 1: rotate1();
            break;
    }       
    orientation++;
}

void BentDick::rotateCounter()
{
    switch(orientation % 2)
    {
        case 0:  rotate0();
            break;
        case 1:  rotate1();
            break;
    }    
    orientation--;
}

void BentDick::rotate0()
{
    squares[0].right();
    squares[0].right();
    squares[3].down();
    squares[3].down();
}

void BentDick::rotate1()
{
   squares[0].left();
   squares[0].left();
   squares[3].up();
   squares[3].up();
}

