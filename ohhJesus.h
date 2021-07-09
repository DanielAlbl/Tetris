#ifndef OHHJESUS
#define OHHJESUS

#include "shape.h"

class OhhJesus : public Shape {
  public:
    OhhJesus(int, int);
	void init();
    void rotateClock();
    void rotateCounter();
};

#endif
