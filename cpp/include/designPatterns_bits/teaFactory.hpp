#ifndef TEAFACTORY_H
#define TEAFACTORY_H

#include "hotDrinkFactory.hpp"

// struct TeaFactory : HotDrinkFactory
// {

//     unique_ptr<HotDrink> make() const override
//     {
//         return make_unique<Tea>();
//     }
// };

struct TeaFactory : HotDrinkFactory
{

    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Tea>();
    }
};

#endif