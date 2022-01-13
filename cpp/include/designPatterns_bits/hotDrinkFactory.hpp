#ifndef HOTDRINKFACTORY_H
#define HOTDRINKFACTORY_H

#include "hotDrink.hpp"

struct HotDrinkFactory
{

    virtual ~HotDrinkFactory() = default;

    virtual unique_ptr<HotDrink> make() const = 0;
};

#endif