#include "callbacks.h"

/***************************************************************************//**
 * Initialize glut callback functions, set the display mode, create a window
 ******************************************************************************/
void initOpenGL(int argc, char** argv, int wCols, int wRows) {
    char title[7] = "Tetris";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
    glutInitWindowSize(wCols, wRows);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialUp);
    glutReshapeFunc(reshape);
    glutTimerFunc(1, ticktock, 1);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

int main(int argc, char** argv) {
    initOpenGL(argc, argv, RIGHT_WALL+LEFT_WALL+4, START_Y);

    glutMainLoop();

    return 0;
}
