#ifndef __UTIL_H
#define __UTIL_H

#include <GL/freeglut.h>
#include <sstream>
#include <string>
#include "event.h"
#include "callbacks.h"

void initOpenGL(int, char**, int, int);
void utilityCentral(Event *);
string printScore(int);
#endif
