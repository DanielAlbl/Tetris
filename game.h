#ifndef __GAME_H
#define __GAME_H

#include <sstream>
#include "o.h"
#include "i.h"
#include "t.h"
#include "l.h"
#include "j.h"
#include "s.h"
#include "z.h"

class Game {
    int turn = 0;
    int keyHitTime;
    int dropDelay = 100;
    bool fullLine[HEIGHT];
    int score = 0;
    int nextShapeType = 0;
    int changeShapeTime;

  public:
    Shape * currentShape;
    Shape * nextShape;

    Game();
	~Game();

    Square* pile[HEIGHT][WIDTH];
    bool left = false;
    bool right = false;
    bool paused = false;

    void updatePile();
    void printPile();
    bool hitPile();
    bool hitTop();

    void drawBorder();
	void draw();

    void speedUp()  { dropDelay /= 4; }
    void slowDown() { dropDelay *= 4; }

    void changeShape();
    void changeNextShape();
    void executeTurn();

    void printScore();
    void findFullLines();
    void findFullSingleLine(int);
    void deleteLines();

    void rotateShapeClock();
    void rotateShapeCounter();
    bool inBoundsRight();
    bool inBoundsLeft();

    void setKeyHitTime();
};

#endif
