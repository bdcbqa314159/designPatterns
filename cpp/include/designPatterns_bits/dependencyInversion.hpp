#ifndef DIP
#define DIP

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

enum class RelationShip
{

    parent,
    child,
    sibling
};

struct Person
{
    string name;
    Person(string name) : name(name)
    {
    }
};

struct RelationShips
{

    vector<tuple<Person, RelationShip, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, RelationShip::parent, child});
        relations.push_back({child, RelationShip::child, parent});
    }
};

struct Research
{

    Research(const RelationShips &relationships)
    {

        auto &relations = relationships.relations;

        for (auto &&[first, rel, second] : relations)
        {

            if (first.name == "John" && rel == RelationShip::parent)
            {
                cout << "John has a child called " << second.name << endl;
            }
        }
    }
};

#endif