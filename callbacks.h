/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <iostream>
#include "event.h"
#include "util.h"

using namespace std;

/// Callback for the display event
void display();
/// Callback for the keyboard event
void keyboard(unsigned char, int, int);
/// Callback for the keyboard up event
void keyboardUp(unsigned char, int, int);
/// Callback for special keys
void special(int, int, int);
/// Callback for special up keys
void specialUp(int, int, int);
/// Callback for the mouseClick event
void mouseClick(int, int, int, int);
/// Callback for the mouseDrag event
void mouseDrag(int, int);
/// Callback for the mouseMove event
void mouseMove(int, int);
/// Callback for the reshape event
void reshape(const int, const int);
/// Common function for collecting event information
void utilityCentral(Event *);
/// Function that's called on a timer
void ticktock(int);
/// Called when openGL is closing
void onClose();

#endif
