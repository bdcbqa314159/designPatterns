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

struct RelationshipBrowser
{

    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

struct RelationShips : RelationshipBrowser
{

    vector<tuple<Person, RelationShip, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, RelationShip::parent, child});
        relations.push_back({child, RelationShip::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) override
    {
        vector<Person> result;
        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == name && rel == RelationShip::parent)
            {
                result.push_back(second);
            }
        }

        return result;
    }
};

struct Research
{

    // Research(const RelationShips &relationships)
    // {

    //     auto &relations = relationships.relations;

    //     for (auto &&[first, rel, second] : relations)
    //     {

    //         if (first.name == "John" && rel == RelationShip::parent)
    //         {
    //             cout << "John has a child called " << second.name << endl;
    //         }
    //     }
    // }

    Research(RelationshipBrowser &browser)
    {
        for (auto &child : browser.find_all_children_of("John"))
        {
            cout << "John has a child called " << child.name << endl;
        }
    }
};

#endif