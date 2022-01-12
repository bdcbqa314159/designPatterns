#ifndef HOTDRINK_H
#define HOTDRINK_H

#include <iostream>
#include <memory>
#include <map>
#include <string>

using namespace std;

struct HotDrink
{

    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{

    void prepare(int volume) override
    {
        cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon & enjoy!" << endl;
    }
};

struct Coffee : HotDrink
{

    void prepare(int volume) override
    {
        cout << "Grind some beans, boil water, pour " << volume << "ml, add cream & enjoy!" << endl;
    }
};

unique_ptr<HotDrink> make_drink(const string &name)
{
    unique_ptr<HotDrink> drink;

    if (name == "tea")
    {
        auto drink = make_unique<Tea>();
        drink->prepare(200);
    }

    else if (name == "coffee")
    {
        auto drink = make_unique<Coffee>();
        drink->prepare(200);
    }

    return drink;
}

#endif