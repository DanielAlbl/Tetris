#ifndef BENT_DICK
#define BENT_DICK

#include "shape.h"

class S : public Shape {
  public:
    S(int, int);
    void rotateClock();
    void rotateCounter();

    void rotate0();
    void rotate1();
};

#endif
