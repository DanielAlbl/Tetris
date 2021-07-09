#include "callbacks.h"

// OpenGL thinks the y = 0 coordinate is at the top of the screen.  Flip it over
int actualY(int y) {
    return glutGet(GLUT_WINDOW_HEIGHT) - y;
}

void display() {
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	if(key == ESCAPE_KEY) 
        glutLeaveMainLoop();
	else if(key == 'd')
        game.rotateShapeClock();
	else if(key == 'a')
        game.rotateShapeCounter();
	else if(key == 'p')
        game.paused ^= 1;
}

void special(int key, int x, int y) {
	if(key == GLUT_KEY_LEFT) {
        game.setKeyHitTime();
        game.left = true;
    }
	else if(key == GLUT_KEY_RIGHT) {
        game.setKeyHitTime();
        game.right = true;
    }
    else if(key == GLUT_KEY_DOWN)
        game.speedUp();
}

void specialUp(int key, int x, int y) {
	if(key == GLUT_KEY_LEFT)
        game.left = false;
	else if(key == GLUT_KEY_RIGHT)
        game.right = false;
	else if(key == GLUT_KEY_DOWN)
        game.slowDown();
}

void reshape(const int w, const int h) {
    glLoadIdentity();
    // project 3d world space into 2d
    gluOrtho2D(0.0, w, 0.0, h);
    // point the camera at the 2d projection
    glViewport(0,0,w,h);
}

void ticktock(int value) {
    game.executeTurn();
    // Set the next timer event elapsed time and function to call
    glutTimerFunc(value, ticktock, value);
}

