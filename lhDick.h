#ifndef LHDICK
#define LHDICK

#include "shape.h"

class LhDick : public Shape {
  public:
    LhDick(int, int);
    void rotateClock();
    void rotateCounter();

    void clock0();
    void clock1();
    void clock2();
    void clock3();

    void counter0();
    void counter1();
    void counter2();
    void counter3();
};

#endif
