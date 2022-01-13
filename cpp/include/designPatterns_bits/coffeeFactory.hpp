#ifndef COFFEEFACTORY_H
#define COFFEEFACTORY_H

#include "hotDrinkFactory.hpp"

struct CoffeeFactory : HotDrinkFactory
{

    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Coffee>();
    }
};

#endif