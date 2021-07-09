#include "util.h"

int main(int argc, char** argv) {
    initOpenGL(argc, argv, RIGHT_WALL+LEFT_WALL+4, START_Y);

    glutMainLoop();

    return 0;
}
