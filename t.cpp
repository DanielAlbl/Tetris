#include "t.h"

T::T(int x1, int y1) : Shape(x1,y1) {
    squares[1].right();
    squares[2].right();
    squares[2].up();
    squares[3].right();
    squares[3].right();
}

void T::rotateClock() {
    switch(orientation % 4) {
		case 0: clock0(); break;
		case 1: clock1(); break;
		case 2: clock2(); break;
		case 3: clock3(); break;
    }
    orientation++;
}

void T::rotateCounter() {
    switch(orientation % 4) {
		case 0: counter0(); break;
		case 1: counter1(); break;
		case 2: counter2(); break;
		case 3: counter3(); break;
    }
    orientation--;
}

void T::clock0() {
    squares[0].down();
    squares[0].right();
}

void T::clock1() {
    squares[0].up();
    squares[0].left();
    squares[2].down();
    squares[2].down();
}

void T::clock2() {
    squares[3].left();
    squares[3].up();
}

void T::clock3() {
    squares[3].right();
    squares[3].down();
    squares[2].up();
    squares[2].up();
}

void T::counter0() {
    squares[3].left();
    squares[3].up();
    squares[2].down();
    squares[2].down();
}

void T::counter1() {
    squares[0].up();
    squares[0].left();
}

void T::counter2() {
    squares[0].down();
    squares[0].right();
    squares[2].up();
    squares[2].up();
}

void T::counter3() {
    squares[3].right();
    squares[3].down();
}

