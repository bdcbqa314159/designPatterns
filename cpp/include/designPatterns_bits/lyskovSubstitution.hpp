#ifndef LP_H
#define LP_H

#include <iostream>

class Rectangle
{
protected:
    int width, height;

public:
    Rectangle(int width, int height) : width(width), height(height)
    {
    }

    int get_width() const
    {
        return width;
    }

    int get_height() const
    {
        return height;
    }

    virtual void set_width(const int width)
    {
        this->width = width;
    }

    virtual void set_height(const int height)
    {
        this->height = height;
    }

    int area() const
    {
        return width * height;
    }
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size, size)
    {
    }

    void set_width(const int width) override
    {
        this->width = width;
        this->height = width;
    }

    void set_height(const int height) override
    {
        this->height = height;
        this->width = height;
    }
};

void process(Rectangle &r)
{
    int w = r.get_width();
    r.set_height(10);

    std::cout << "expected area = " << w * 10 << std::endl;

    std::cout << " actual area = " << r.area() << std::endl;
}

// Objects in a program should be replaceable with instances of their subtypes without altering the correctness of the program.
// The design above does not take care if Rectangle has subclasses like Square, the design is broken and Lyskov principle is violated.
// If we want this process API keep going we need to set Square out of inheritance because process is not suitable for square anyway.

#endif