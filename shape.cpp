#include "shape.h"

Shape::Shape(int x1, int y1) : x(x1), y(y1), orientation(0) {
    for(int i = 0; i < 4; i++)
        squares[i].setPoint(x1,y1);
}

Shape::~Shape() {}

void Shape::down() {
    for(int i = 0; i < 4; i++)
        squares[i].down();
    y -= SQUARE_WIDTH;
}

void Shape::right() {
    for(int i = 0; i < 4; i++)
        squares[i].right();
    x += SQUARE_WIDTH;
}

void Shape::left() {
    for(int i = 0; i < 4; i++)
        squares[i].left();
    x -= SQUARE_WIDTH;
}

void Shape::draw() {
    for(int i = 0; i < 4; i++)
        squares[i].draw();
}

void Shape::hitBottom(Square* pile[48][14]) {
    for(int i = 0; i < 4; i++)
        pile[squares[i].Y()/SQUARE_WIDTH][(squares[i].X()-LEFT_WALL)/SQUARE_WIDTH] = new Square(squares[i]);
}

void Shape::setColor(int color) {
    for(int i = 0; i < 4; i++)
        squares[i].COLOR_ARRAY_INDEX = color;
}

void Shape::updateXY() {
    x = 640, y = 800;
    for(int i = 0; i < 4; i++) {
        if(squares[i].X() < x)
            x = squares[i].X();
        if(squares[i].Y() < y)
            y = squares[i].Y();
    }
}


