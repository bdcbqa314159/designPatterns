#ifndef FM_H
#define FM_H

#include <cmath>
#include <iostream>

using namespace std;

class Printable
{
protected:
    float x, y;

    friend ostream &operator<<(ostream &os, const Printable &p)
    {
        os << "x : " << p.x << endl;
        os << "y : " << p.y << endl;

        return os;
    }
};

enum class PointType
{
    cartesian,
    polar
};

class Point1 : public Printable
{

public:
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
            y = a * cos(b);
        }
    }
};

class Point2 : public Printable
{
    float x, y;

    Point2(float x, float y) : x(x), y(y)
    {
    }

public:
    static Point2 newCartesian(float x, float y)
    {
        return Point2{x, y};
    }

    static Point2 newPolar(float x, float y)
    {
        return Point2{x * cos(y), x * sin(y)};
    }
};

#endif
