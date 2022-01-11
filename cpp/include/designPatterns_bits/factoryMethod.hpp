#ifndef FM_H
#define FM_H

#include <cmath>
#include <iostream>

using namespace std;

enum class PointType
{
    cartesian,
    polar
};

class Point1
{

public:
    float x, y;
    Point1(float a, float b, PointType type = PointType::cartesian)
    {

        if (type == PointType::cartesian)
        {
            x = a;
            y = b;
        }
        else
        {
            x = a * cos(b);
            y = a * sin(b);
        }
    }

    friend ostream &operator<<(ostream &os, const Point1 &obj)
    {

        os << "x: " << obj.x << endl;
        os << "y: " << obj.y << endl;

        return os;
    }
};

class Point2
{

    float x, y;

    Point2(const float x, const float y) : x(x), y(y)
    {
    }

public:
    friend ostream &operator<<(ostream &os, const Point2 &obj)
    {

        os << "x: " << obj.x << endl;
        os << "y: " << obj.y << endl;

        return os;
    }

    static Point2 newCartesian(float x, float y)
    {
        return Point2{x, y};
    }

    static Point2 newPolar(float r, float theta)
    {
        return Point2{r * cos(theta), r * sin(theta)};
    }
};

#endif
