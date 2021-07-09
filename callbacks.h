/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef CALLBACKS_H
#define CALLBACKS_H

#define ESCAPE_KEY 27

#include "game.h"

static Game game;

void display();
void keyboard(unsigned char, int, int);
void special(int, int, int);
void specialUp(int, int, int);
void reshape(const int, const int);
void ticktock(int);

#endif
