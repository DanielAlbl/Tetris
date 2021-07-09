#ifndef SQUARE
#define SQUARE

#include "globalShit.h"

class Square {
    int x, y;

  public:
    Square(): x(320), y(800-SQUARE_WIDTH) {}
    Square(int x1, int y1): x(x1), y(y1) {}
    Square(Square & s);

    void setPoint(int x1, int y1) { x = x1, y = y1; }

    int X() { return x; }
    int Y() { return y; }

    void up();
    void down();
    void right();
    void left();

    void draw();
    int COLOR_ARRAY_INDEX;
};

#endif
