#include "point.h"

// return the square of the distance between points a and b
long long distSquared(const Point& a, const Point& b) {
    long long dx = (a.x-b.x);
    long long dy = (a.y-b.y);
    return dx*dx + dy*dy;
}

// compare by x as primary key (using y as secondary key)
bool compareByX(const Point& a, const Point& b) {
    if (a.x == b.x)
        return (a.y < b.y);
    else
        return (a.x < b.x);
}

// compare by y as primary key (using x as secondary key)
bool compareByY(const Point& a, const Point& b) {
    if (a.y == b.y)
        return (a.x < b.x);
    else
        return (a.y < b.y);
}
