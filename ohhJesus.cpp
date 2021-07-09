#include "ohhJesus.h"

OhhJesus::OhhJesus(int x1, int y1) : Shape(x1, y1) { init(); }

void OhhJesus::init() {
	squares[1].up();
    squares[2].up();
    squares[2].up();
    squares[3].up();
    squares[3].up();
    squares[3].up();
}

void OhhJesus::rotateClock() {
    if(orientation % 2 == 1) {
        rotateCounter();
        return;
    }

    squares[0].up();
    squares[0].up();
    squares[0].left();
    squares[0].left();
    squares[1].up();
    squares[1].left();
    squares[3].down();
    squares[3].right();

    orientation++;
}

void OhhJesus::rotateCounter() {
    if(orientation % 2 == 0) {
        rotateClock();
        return;
    }

    squares[0].down();
    squares[0].down();
    squares[0].right();
    squares[0].right();
    squares[1].down();
    squares[1].right();
    squares[3].up();
    squares[3].left();

    orientation--;
}
