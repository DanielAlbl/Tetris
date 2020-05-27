#include "util.h"

void utilityCentral(Event *event)
{
   static Game game;
   event->doAction(game);
   delete event;
}



/***************************************************************************//**
 * Initialize glut callback functions, set the display mode, create a window
 ******************************************************************************/
void initOpenGL(int argc, char** argv, int wCols, int wRows)
{
   char title[9] = "Score: 0";

   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

   glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);

   glutInitWindowSize(wCols, wRows);

   glutInitWindowPosition(100, 100);

   glutCreateWindow(title);

   glutDisplayFunc(display);

   glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

   glutKeyboardFunc(keyboard);

   glutKeyboardUpFunc(keyboardUp);

   glutMouseFunc(mouseClick);

   glutReshapeFunc(reshape);

   glutTimerFunc(1, ticktock, 1);

   glutCloseFunc(onClose);

   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

   utilityCentral(new InitEvent(wCols, wRows));
}
