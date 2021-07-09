#ifndef TWOxTWO
#define TWOxTWO

#include "shape.h"

class O : public Shape {
  public:
    O(int, int);
    void rotateClock() {}
    void rotateCounter() {}
};

#endif
