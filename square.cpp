#include "square.h"

Square::Square(Square& s) {
    x = s.X(), y = s.Y();
    COLOR_ARRAY_INDEX = s.COLOR_ARRAY_INDEX;
}

void Square::up()    { y += SQUARE_WIDTH; }

void Square::down()  { y -= SQUARE_WIDTH; }

void Square::right() { x += SQUARE_WIDTH; }

void Square::left()  { x -= SQUARE_WIDTH; }

void Square::setVertices() {
	glVertex2f(x, y);
    glVertex2f(x+SQUARE_WIDTH, y);
    glVertex2f(x+SQUARE_WIDTH, y+SQUARE_WIDTH);
    glVertex2f(x, y+SQUARE_WIDTH);
}

void Square::draw() {
    float white[3] = {1,1,1};
    glColor3fv(COLOR_ARRAY[COLOR_ARRAY_INDEX]);
    glBegin(GL_POLYGON);
	setVertices();
	glEnd();

    glLineWidth(2);
    glColor3fv(white);
    glBegin(GL_LINE_LOOP);
	setVertices();
    glEnd();
}
