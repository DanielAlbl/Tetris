#ifndef LHDICK
#define LHDICK

#include "shape.h"

class J : public Shape {
  public:
    J(int, int);
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
