#ifndef FM_H
#define FM_H

#include <cmath>
#include <iostream>

using namespace std;

class Printable
{
protected:
    float x, y;
    Printable(float x, float y) : x(x), y(y) {}

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
    Point1(float x, float y, PointType type = PointType::cartesian) : Printable(x, y)
    {
        if (type == PointType::cartesian)
        {
            this->x = x;
            this->y = y;
        }
        else
        {
            this->x = x * cos(y);
            this->y = x * sin(y);
        }
    }
};

class Point2 : public Printable
{
    Point2(float x, float y) : Printable(x, y)
    {
    }

public:
    static Point2 newCatesian(float x, float y)
    {
        return Point2{x, y};
    }

    static Point2 newPolar(float x, float y)
    {
        return Point2{x * cos(y), x * sin(y)};
    }
};

#endif
