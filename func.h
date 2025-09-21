#ifndef FUNC_H
#define FUNC_H

#include "structs.h"

// Точка
Point readPoint();

void printPoint(const Point &point);

// Круг
Circle readCircle();

void printCircle(const Circle &circle);

double circleLength(const Circle &circle);

double circleArea(const Circle &circle);

// Квадрат
Square readSquare();

void printSquare(const Square &square);

double squarePerimeter(const Square &square);

double squareArea(const Square &square);

// Принадлежность круга фигуре
bool isPointInCircle(const Point &point, const Circle &circle);

bool isPointInSquare(const Point &point, const Square &square);

// Нахождение точки на контуре
bool isPointOnCircle(const Point &point, const Circle &circle);

bool isPointOnSquare(const Point &point, const Square &square);

// Пересечение фигур
bool areCirclesIntersecting(const Circle &circle1, const Circle &circle2);

bool areSquaresIntersecting(const Square &square1, const Square &square2);

bool areCircleSquareIntersecting(const Circle &circle, const Square &square);

// Принадлежность фигуры
bool isCircleInCircle(const Circle &inner, const Circle &outer);

bool isSquareInSquare(const Square &inner, const Square &outer);

bool isSquareInCircle(const Square &inner, const Circle &outer);

bool isCircleInSquare(const Circle &inner, const Square &outer);

#endif
