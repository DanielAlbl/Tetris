#ifndef TWOxTWO
#define TWOxTWO

#include "shape.h"

class TwoXtwo : public Shape {
  public:
    TwoXtwo(int, int);
	void init();
    void rotateClock() {}
    void rotateCounter() {}
};

#endif
