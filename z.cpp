#include "z.h"

Z::Z(int x1, int y1) : Shape(x1,y1) {
    squares[1].up();
    squares[2].up();
    squares[2].left();
    squares[3].up();
    squares[3].up();
    squares[3].left();
}

void Z::rotateClock() {
	if(orientation)
		rotate1();
	else
		rotate0();
	
    orientation = (orientation + 1) % 2;
}

void Z::rotateCounter() { rotateClock(); }

void Z::rotate0() {
    squares[0].left();
    squares[0].left();
    squares[3].down();
    squares[3].down();
}

void Z::rotate1() {
    squares[0].right();
    squares[0].right();
    squares[3].up();
    squares[3].up();
}

