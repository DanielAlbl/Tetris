#include "game.h"

Game::Game() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++)
            pile[i][j] = nullptr;
        fullLine[i] = false;
    }
    srand(time(NULL));
}

Game::~Game() {
	for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++) 
			delete pile[i][j];

    delete currentShape;
    delete nextShape;
}

void Game::changeNextShape() {
    int randNum = rand() % 7;
    delete nextShape;
    switch(randNum) {
		case 0: nextShape = new TwoXtwo(NEXT_X,NEXT_Y);    break;
		case 1: nextShape = new OhhJesus(NEXT_X,NEXT_Y);   break;
		case 2: nextShape = new Chode(NEXT_X,NEXT_Y);      break;
		case 3: nextShape = new Dick(NEXT_X,NEXT_Y);       break;
		case 4: nextShape = new LhDick(NEXT_X,NEXT_Y);     break;
		case 5: nextShape = new BentDick(NEXT_X,NEXT_Y);   break;
		case 6: nextShape = new LhBentDick(NEXT_X,NEXT_Y); break;
    }
    nextShape->setColor(randNum);
    nextShapeType = randNum;
}

void Game::changeShape() {
    int randNum;
    if(turn == 0) 
        randNum = rand() % 7;
    else {
        randNum = nextShapeType;
        delete currentShape;
    }

    switch(randNum) {
		case 0: currentShape = new TwoXtwo(START_X,START_Y);    break;
		case 1: currentShape = new OhhJesus(START_X,START_Y);   break;
		case 2: currentShape = new Chode(START_X,START_Y);      break;
		case 3: currentShape = new Dick(START_X,START_Y);       break;
		case 4: currentShape = new LhDick(START_X,START_Y);     break;
		case 5: currentShape = new BentDick(START_X,START_Y);   break;
		case 6: currentShape = new LhBentDick(START_X,START_Y); break;
    }
    currentShape->setColor(randNum);
}

void Game::executeTurn() {
    if(!paused) {
		// speed up over time
        if(turn % 10000 == 0)
            dropDelay--;
        if(((turn == keyHitTime or turn > keyHitTime + 100) and turn % 50 == keyHitTime % 50) or tuckableRight())
            if(right and inBoundsRight())
                currentShape->right();
        if(((turn == keyHitTime or turn > keyHitTime + 100) and turn % 50 == keyHitTime % 50) or tuckableLeft())
            if(left and inBoundsLeft())
                currentShape->left();

        if(turn % dropDelay == 0) {
            glClear(GL_COLOR_BUFFER_BIT);
            if(hitPile()) {
                updatePile();
                if(hitTop()) {
                    std::cout << "Final Score: " << score << '\n';
                    glutLeaveMainLoop();
                }
                changeShape();
                changeNextShape();
            }

            drawBorder();
            printPile();
            currentShape->draw();
			nextShape->draw();

            glutSwapBuffers();

            currentShape->down();
        }
        turn++;
    }
}

void Game::initGameState() {
    changeShape();
    changeNextShape();
    drawBorder();
}

void Game::drawBorder() {
    float white[3] = {1,1,1};
    glLineWidth(2);
    glColor3fv(white);
    glBegin(GL_LINE_LOOP);
    glVertex2f(LEFT_WALL-5, 0);
    glVertex2f(LEFT_WALL-5, START_Y);
    glVertex2f(RIGHT_WALL+SQUARE_WIDTH, START_Y);
    glVertex2f(RIGHT_WALL+SQUARE_WIDTH, 0);
    glEnd();
}

void Game::updatePile() {
    currentShape->hitBottom(pile);
    findFullLines();
    deleteLines();
}

void Game::printPile() {
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            if(pile[i][j] != nullptr)
                pile[i][j]->draw();
}

bool Game::hitPile() {
    if(currentShape->Y() <= SQUARE_WIDTH)
        return true;
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            for(int k = 0; k < 4; k++)
                if(pile[i][j] and pile[i][j]->X() == currentShape->squares[k].X() and pile[i][j]->Y()+SQUARE_WIDTH == currentShape->squares[k].Y())
                    return true;
    return false;
}

bool Game::hitTop() {
    for(int i = 0; i < WIDTH; i++)
        if(pile[HEIGHT-1][i])
            return true;
    return false;
}

void Game::findFullLines() {
    bool full;
    int count = 0;
    for(int i = 0; i < HEIGHT; i++) {
        full = true;
        for(int j = 0; j < WIDTH; j++)
            if(!pile[i][j])
                full = false;
        if(full) {
            fullLine[i] = true;
            count++;
        }
    }
    score += count * count;
    printScore();
}

void Game::printScore() {
    std::stringstream ss;
    ss << "Score: " << score;
    glutSetWindowTitle(ss.str().c_str());
}

void Game::findFullSingleLine(int i) {
    bool full = true;
    for(int j = 0; j < WIDTH; j++)
        if(!pile[i][j])
            full = false;
    if(full)
        fullLine[i] = true;
}

void Game::deleteLines() {
    int count = 0;
    for(int i = 0; i+count < HEIGHT; i++)
        if(fullLine[i+count]) {
            fullLine[i+count] = false;
            for(int j = 0; j < WIDTH; j++) {
                delete pile[i][j];
                pile[i][j] = nullptr;
            }

            for(int k = i; k < HEIGHT-1; k++)
                for(int j = 0; j < WIDTH; j++) {
                    pile[k][j] = pile[k+1][j];
                    if(pile[k][j])
                        pile[k][j]->down();
                }
            for(int j = 0; j < WIDTH; j++)
                pile[HEIGHT-1][j] = nullptr;
            i--, count++;
        }
}

void Game::rotateShapeClock() {
    currentShape->rotateClock();
    currentShape->updateXY();
    bool loopedOnce = false;
    while(!inBoundsLeft()) {
        currentShape->right();
        loopedOnce = true;
    }
    if(loopedOnce) {
        currentShape->left();
        loopedOnce = false;
    }
    while(!inBoundsRight()) {
        currentShape->left();
        loopedOnce = true;
    }
    if(loopedOnce)
        currentShape->right();
}

void Game::rotateShapeCounter() {
    currentShape->rotateCounter();
    currentShape->updateXY();
    bool loopedOnce = false;
    while(!inBoundsLeft()) {
        currentShape->right();
        loopedOnce = true;
    }
    if(loopedOnce) {
        currentShape->left();
        loopedOnce = false;
    }
    while(!inBoundsRight()) {
        currentShape->left();
        loopedOnce = true;
    }
    if(loopedOnce)
        currentShape->right();
}

bool Game::inBoundsRight() {
    for(int i = 0; i < 4; i++) {
        if(currentShape->squares[i].X()+SQUARE_WIDTH > RIGHT_WALL)
            return false;
        for(int j = 0; j < HEIGHT; j++)
            for(int k = 0; k < WIDTH; k++)
                if(pile[j][k] and currentShape->squares[i].Y() == pile[j][k]->Y() and currentShape->squares[i].X()+SQUARE_WIDTH == pile[j][k]->X())
                    return false;
    }
    return true;
}

bool Game::inBoundsLeft() {
    for(int i = 0; i < 4; i++) {
        if(currentShape->squares[i].X()-SQUARE_WIDTH < LEFT_WALL)
            return false;
        for(int j = 0; j < HEIGHT; j++)
            for(int k = 0; k < WIDTH; k++)
                if(pile[j][k] and currentShape->squares[i].Y() == pile[j][k]->Y() and currentShape->squares[i].X()-SQUARE_WIDTH == pile[j][k]->X())
                    return false;
    }
    return true;
}

void Game::setKeyHitTime() {
    keyHitTime = turn;
}

bool Game::tuckableRight() {
    /*
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < HEIGHT; j++)
            for(int k = 0; k < WIDTH; k++)
                if(pile[j][k] and pile[j][k]->X() == (currentShape->squares[i].X()+SQUARE_WIDTH) and pile[j][k]->Y()+SQUARE_WIDTH > currentShape->squares[i].X())
                    return true;
                    */
    return false;
}

bool Game::tuckableLeft() {
    /*
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < HEIGHT; j++)
            for(int k = 0; k < WIDTH; k++)
                if(pile[j][k] and pile[j][k]->X() == (currentShape->squares[i].X()-SQUARE_WIDTH) and pile[j][k]->Y()+SQUARE_WIDTH > currentShape->squares[i].X())
                    return true;
    */
    return false;
}


