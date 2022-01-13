#ifndef HOTDRINK_H
#define HOTDRINK_H

#include <iostream>
#include <memory>
#include <map>
#include <string>

using namespace std;

// struct HotDrink
// {

//     virtual ~HotDrink() = default;
//     virtual void prepare(int volume) const = 0;
// };

// struct Tea : HotDrink
// {

//     void prepare(int volume) const override
//     {
//         cout << "Here you have " << volume << "ml of tea." << endl;
//     }
// };

// struct Coffee : HotDrink
// {

//     void prepare(int volume) const override
//     {
//         cout << "Here you have " << volume << "ml if coffee" << endl;
//     }
// };

// unique_ptr<HotDrink> make_drink(const string &name)
// {

//     unique_ptr<HotDrink> drink;

//     if (name == "tea")
//     {
//         auto drink = make_unique<Tea>();
//         drink->prepare(200);
//     }

//     else if (name == "coffee")
//     {
//         auto drink = make_unique<Coffee>();
//         drink->prepare(200);
//     }

//     return drink;
// }

struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) const = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) const override
    {
        cout << "Here: " << volume << "ml  of tea." << endl;
    }
};

struct Coffee : HotDrink
{

    void prepare(int volume) const override
    {
        cout << "Here: " << volume << "ml of coffee." << endl;
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