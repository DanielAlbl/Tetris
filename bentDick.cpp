#include "bentDick.h"

BentDick::BentDick(int x1, int y1) : Shape(x1, y1) { init(); }

void BentDick::init() {
	squares[1].up();
    squares[2].up();
    squares[2].right();
    squares[3].up();
    squares[3].up();
    squares[3].right();
}

void BentDick::rotateClock() {
	if(orientation)
		rotate1();
	else
		rotate0();
	
    orientation = (orientation + 1) % 2;
}

void BentDick::rotateCounter() { rotateClock(); }

void BentDick::rotate0() {
    squares[0].right();
    squares[0].right();
    squares[3].down();
    squares[3].down();
}

void BentDick::rotate1() {
    squares[0].left();
    squares[0].left();
    squares[3].up();
    squares[3].up();
}

