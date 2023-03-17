#ifndef POINT_H
#define POINT_H

struct Point {
    long x,y;
};

// return the square of the distance between points a and b
long long distSquared(const Point& a, const Point& b);

// compare by x as primary key (using y as secondary key)
bool compareByX(const Point& a, const Point& b);

// compare by y as primary key (using x as secondary key)
bool compareByY(const Point& a, const Point& b);

#endif
