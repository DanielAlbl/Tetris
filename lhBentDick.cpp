#include "lhBentDick.h"

LhBentDick::LhBentDick(int x1, int y1) : BentDick(x1, y1) {}

void LhBentDick::init() {
	squares[1].up();
    squares[2].up();
    squares[2].left();
    squares[3].up();
    squares[3].up();
    squares[3].left();
}


