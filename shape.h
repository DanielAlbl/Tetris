#ifndef SHAPES
#define SHAPES

#include "square.h"

class Shape {
  protected:
    int x;
    int y;
    unsigned int orientation;

  public:
    Shape(int,int);
    virtual ~Shape() = 0;

    Square squares[4];

    void down();
    void right();
    void left();
    void draw();
    int X() {
        return x;
    }
    int Y() {
        return y;
    }
    void setColor(int);
    void hitBottom(Square* pile[48][14]);
    virtual void rotateClock() = 0;
    virtual void rotateCounter() = 0;
    void updateXY();
};

#endif
