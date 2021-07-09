#include "dick.h"

Dick::Dick(int x1, int y1) : Shape(x1, y1) { init(); }

void Dick::init() {
	squares[1].up();
    squares[2].up();
    squares[2].up();
    squares[3].up();
    squares[3].up();
    squares[3].left();
}

void Dick::rotateClock() {
    switch(orientation % 4) {
		case 0: clock0(); break;
		case 1: clock1(); break;
		case 2: clock2(); break;
		case 3: clock3(); break;
    }
    orientation++;
}

void Dick::rotateCounter() {
    switch(orientation % 4) {
		case 0: counter0(); break;
		case 1: counter1(); break;
		case 2: counter2(); break;
		case 3: counter3(); break;
    }
    orientation--;
}

void Dick::clock0() {
    squares[0].up();
    squares[0].left();
    squares[2].right();
    squares[2].down();
    squares[3].right();
    squares[3].right();
}

void Dick::clock1() {
    squares[0].up();
    squares[0].right();
    squares[2].left();
    squares[2].down();
    squares[3].down();
    squares[3].down();
}

void Dick::clock2() {
    squares[0].down();
    squares[0].right();
    squares[2].left();
    squares[2].up();
    squares[3].left();
    squares[3].left();
}

void Dick::clock3() {
    squares[0].down();
    squares[0].left();
    squares[2].right();
    squares[2].up();
    squares[3].up();
    squares[3].up();
}

void Dick::counter0() {
    squares[0].up();
    squares[0].right();
    squares[2].left();
    squares[2].down();
    squares[3].down();
    squares[3].down();

}

void Dick::counter1() {
    squares[0].down();
    squares[0].right();
    squares[2].left();
    squares[2].up();
    squares[3].left();
    squares[3].left();
}

void Dick::counter2() {
    squares[0].down();
    squares[0].left();
    squares[2].right();
    squares[2].up();
    squares[3].up();
    squares[3].up();
}

void Dick::counter3() {
    squares[0].up();
    squares[0].left();
    squares[2].right();
    squares[2].down();
    squares[3].right();
    squares[3].right();
}

