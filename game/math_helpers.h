#ifndef MATH_HELPER_H
#define MATH_HELPER_H
#include <cmath>
#include <algorithm>
using namespace std;
inline double mapd(double v, double a, double b, double na, double nb) {
    return (v - a) / (b - a) * (nb - na) + na;
}

inline double clampd(double v, double a, double b) {
    return min(b, max(v, a));
}
#endif
