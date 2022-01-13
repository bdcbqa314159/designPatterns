#ifndef DRINKFACTORY_H
#define DRINKFACTORY_H

#include <functional>
#include "hotDrink.hpp"
#include "hotDrinkFactory.hpp"


struct HotDrinkFactory;

class DrinkFactory
{

    map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory()
    {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string &name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);

        return drink;
    }
};

class DrinkWithVolumeFactory
{

    map<string, function<unique_ptr<HotDrink>()>> factories;

public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = []
        {
            auto drink = make_unique<Tea>();
            drink->prepare(200);
            return drink;
        };

        factories["coffee"] = []
        {
            auto drink = make_unique<Coffee>();
            drink->prepare(200);
            return drink;
        };
    }

    unique_ptr<HotDrink> make_drink(const string &name)
    {
        return factories[name]();
    }
};

#endif