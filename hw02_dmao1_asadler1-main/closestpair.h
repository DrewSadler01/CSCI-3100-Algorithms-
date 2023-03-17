#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "point.h"
#include <vector>

// used as a return value
struct Outcome {
    Point p,q;
    long long dsq;   // distance squared
    Outcome() : p(), q(), dsq(-1) {}
    Outcome(const Point& p, const Point& q, long long dsq) : p(p), q(q), dsq(dsq) {}
    Outcome(const Point& p, const Point& q) : p(p), q(q), dsq(distSquared(p,q)) {}
};


Outcome brute(const std::vector<Point>& data);
Outcome efficient(const std::vector<Point>& data);
Outcome extra(const std::vector<Point>& data);

#endif
