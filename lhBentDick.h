#ifndef LH_BENT_DICK
#define LH_BENT_DICK

#include "shape.h"

class LhBentDick : public Shape {
  public:
    LhBentDick(int, int);
    void rotateClock();
    void rotateCounter();

    void rotate0();
    void rotate1();
};

#endif
