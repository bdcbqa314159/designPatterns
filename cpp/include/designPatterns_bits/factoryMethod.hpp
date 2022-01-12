#ifndef FM_H
#define FM_H

#include <cmath>
#include <iostream>

using namespace std;

class Printable
{

protected:
    float x, y;

    Printable(float x, float y) : x(x), y(y)
    {
    }

    friend ostream &operator<<(ostream &os, const Printable &p)
    {
        os << "x: " << p.x << endl;
        os << "y: " << p.y << endl;

        return os;
    }
};

enum class PrintType
{
    cartesian,
    polar
};

class Point1 : public Printable
{
public:
    Point1(float x, float y, PrintType type = PrintType::cartesian) : Printable(x, y)
    {

        if (type == PrintType::cartesian)
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
    static Point2 newCartesian(float x, float y)
    {
        return Point2(x, y);
    }
    static Point2 newPolar(float x, float y)
    {
        return Point2(x * cos(y), x * sin(y));
    }
};

class Point3 : public Printable
{

    Point3(float x, float y) : Printable(x, y)
    {
    }

public:
    friend class PointFactory;
};

class PointFactory
{

public:
    PointFactory() {}

    static Point3 newCartesian(float x, float y)
    {
        return Point3(x, y);
    }
    static Point3 newPolar(float x, float y)
    {
        return Point3(x * cos(y), x * sin(y));
    }
};

class Point4 : public Printable
{

    Point4(float x, float y) : Printable(x, y)
    {
    }

    class PointFactory
    {

    public:
        PointFactory() {}

        static Point4 newCartesian(float x, float y)
        {
            return Point4(x, y);
        }

        static Point4 newPolar(float x, float y)
        {
            return Point4(x * cos(y), x * sin(y));
        }
    };

public:
    static PointFactory Factory;
};

#endif
