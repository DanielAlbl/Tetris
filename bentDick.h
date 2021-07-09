#ifndef BENT_DICK
#define BENT_DICK

#include "shape.h"

class BentDick : public Shape {
  public:
    BentDick(int, int);
    void rotateClock();
    void rotateCounter();

    void rotate0();
    void rotate1();
};

#endif
