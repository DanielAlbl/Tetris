#ifndef DICK
#define DICK

#include "shape.h"

class Dick : public Shape
{
public:
    Dick(int, int);
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
