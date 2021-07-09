#ifndef LHDICK
#define LHDICK

#include "dick.h"

class LhDick : public Dick {
  public:
    LhDick(int, int);
	void init();

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
