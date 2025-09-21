#include <iostream>
#include <cmath>

#include "structs.h"

const double EPS = 1e-5;
const double PI = 3.141592653589793;

static bool isEqual(const double a, const double b) {
    return fabs(a - b) < EPS;
}

static double getSquaredDistance(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

static double getDistance(const Point &a, const Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

Point readPoint() {
    Point point;
    std::cin >> point.x >> point.y;
    return point;
}

void printPoint(const Point &point) {
    std::cout << "Point: (" << point.x << ", " << point.y << ")" << std::endl;
}

Circle readCircle() {
    Circle circle;
    circle.center = readPoint();
    std::cin >> circle.radius;
    return circle;
}

void printCircle(const Circle &circle) {
    std::cout << "Circle: center=(" << circle.center.x << ", " << circle.center.y << "), radius=" << circle.radius <<
            std::endl;
}

double circleLength(const Circle &circle) {
    return 2 * PI * circle.radius;
}

double circleArea(const Circle &circle) {
    return PI * circle.radius * circle.radius;
}

bool isPointInCircle(const Point &point, const Circle &circle) {
    return getSquaredDistance(point, circle.center) + EPS < circle.radius * circle.radius;
}

bool isPointOnCircle(const Point &point, const Circle &circle) {
    return isEqual(getSquaredDistance(point, circle.center), circle.radius * circle.radius);
}

Square readSquare() {
    Square square;
    square.topLeft = readPoint();
    std::cin >> square.side;
    return square;
}

void printSquare(const Square &square) {
    std::cout << "Square: top-left point=(" << square.topLeft.x << ", " << square.topLeft.y
            << "), side=" << square.side << std::endl;
}

double squarePerimeter(const Square &square) {
    return 4 * square.side;
}

double squareArea(const Square &square) {
    return square.side * square.side;
}

bool isPointInSquare(const Point &point, const Square &square) {
    Point topLeft = square.topLeft;
    Point bottomRight = {square.topLeft.x + square.side, square.topLeft.y - square.side};

    return (point.x > topLeft.x + EPS && point.x < bottomRight.x - EPS &&
            point.y < topLeft.y - EPS && point.y > bottomRight.y + EPS);
}

bool isPointOnSquare(const Point &point, const Square &square) {
    Point topLeft = square.topLeft;
    Point bottomRight = {square.topLeft.x + square.side, square.topLeft.y - square.side};

    const bool onLeftEdge = isEqual(point.x, topLeft.x) && (
                                point.y <= topLeft.y + EPS && point.y >= bottomRight.y - EPS);
    const bool onRightEdge = isEqual(point.x, bottomRight.x) && (
                                 point.y <= topLeft.y + EPS && point.y >= bottomRight.y - EPS);
    const bool onTopEdge = isEqual(point.y, topLeft.y) && (
                               point.x >= topLeft.x - EPS && point.x <= bottomRight.x + EPS);
    const bool onBottomEdge = isEqual(point.y, bottomRight.y) && (
                                  point.x >= topLeft.x - EPS && point.x <= bottomRight.x + EPS);

    return onLeftEdge || onRightEdge || onTopEdge || onBottomEdge;
}

bool areCirclesIntersecting(const Circle &circle1, const Circle &circle2) {
    const double distance = getDistance(circle1.center, circle2.center);
    return distance <= circle1.radius + circle2.radius + EPS;
}

bool areSquaresIntersecting(const Square &square1, const Square &square2) {
    Point topLeft1 = square1.topLeft;
    Point bottomRight1 = {square1.topLeft.x + square1.side, square1.topLeft.y - square1.side};

    Point topLeft2 = square2.topLeft;
    Point bottomRight2 = {square2.topLeft.x + square2.side, square2.topLeft.y - square2.side};

    return !(bottomRight1.x < topLeft2.x ||
             topLeft1.x > bottomRight2.x ||
             bottomRight1.y > topLeft2.y ||
             topLeft1.y < bottomRight2.y);
}

bool areCircleSquareIntersecting(const Circle &circle, const Square &square) {
    Point topLeft = square.topLeft;
    Point bottomRight = {square.topLeft.x + square.side, square.topLeft.y - square.side};

    Point closestSquarePoint = {
        std::max(topLeft.x, std::min(circle.center.x, bottomRight.x)),
        std::max(bottomRight.y, std::min(circle.center.y, topLeft.y))
    };

    const double squaredDistance = getSquaredDistance(circle.center, closestSquarePoint);
    return squaredDistance <= circle.radius * circle.radius + EPS;
}

bool isCircleInCircle(const Circle &inner, const Circle &outer) {
    const double distance = getDistance(inner.center, outer.center);
    return distance + inner.radius <= outer.radius + EPS;
}

bool isSquareInSquare(const Square &inner, const Square &outer) {
    Point topLeft1 = inner.topLeft;
    Point bottomRight1 = {inner.topLeft.x + inner.side, inner.topLeft.y - inner.side};

    Point topLeft2 = outer.topLeft;
    Point bottomRight2 = {outer.topLeft.x + outer.side, outer.topLeft.y - outer.side};

    return (topLeft1.x >= topLeft2.x - EPS &&
            bottomRight1.x <= bottomRight2.x + EPS &&
            topLeft1.y <= topLeft2.y + EPS &&
            bottomRight1.y >= bottomRight2.y - EPS);
}

bool isSquareInCircle(const Square &square, const Circle &circle) {
    Point topLeft = square.topLeft;
    Point topRight{square.topLeft.x + square.side, square.topLeft.y};
    Point bottomLeft{square.topLeft.x, square.topLeft.y - square.side};
    Point bottomRight{square.topLeft.x + square.side, square.topLeft.y - square.side};
    return isPointInCircle(topLeft, circle) && isPointInCircle(topRight, circle) && isPointInCircle(bottomLeft, circle)
           && isPointInCircle(bottomRight, circle);
}

bool isCircleInSquare(const Circle &circle, const Square &square) {
    Point topLeft = square.topLeft;
    Point bottomRight = {square.topLeft.x + square.side, square.topLeft.y - square.side};

    return (circle.center.x - circle.radius >= topLeft.x - EPS &&
            circle.center.x + circle.radius <= bottomRight.x + EPS &&
            circle.center.y + circle.radius <= topLeft.y + EPS &&
            circle.center.y - circle.radius >= bottomRight.y - EPS);
}
