#ifndef OHHJESUS
#define OHHJESUS

#include "shape.h"

class I : public Shape {
  public:
    I(int, int);
    void rotateClock();
    void rotateCounter();
};

#endif
