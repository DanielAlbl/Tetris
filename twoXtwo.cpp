#include "twoXtwo.h"

TwoXtwo::TwoXtwo(int x1, int y1) : Shape(x1,y1) {
    squares[1].up();
    squares[2].right();
    squares[3].right();
    squares[3].up();
}


