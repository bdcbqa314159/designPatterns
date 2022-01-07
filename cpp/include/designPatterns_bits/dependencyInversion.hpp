#ifndef DIP
#define DIP

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

enum class Relationship
{

    parent,
    child,
    sibling
};

struct Person
{

    string name;

    Person(string name) : name(name){};
};

struct RelationshipBrowser
{

    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

struct Relationships : RelationshipBrowser
{

    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child)
    {

        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) override
    {

        vector<Person> result;

        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }

        return result;
    }
};

struct Research
{

    // Research(const Relationships &relationships)
    // {

    //     auto &relations = relationships.relations;

    //     for (auto &&[first, rel, second] : relations)
    //     {
    //         if (first.name == "John" && rel == Relationship::parent)
    //         {
    //             cout << "John has a child called " << first.name << endl;
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

/*Principle:
1) High-level modules should not depend on low-level modules.
Both should depend on abstractions/ virtual or base classes.
2) Abstractions should not depend on details.
Details should depend on abstractions.*/

#endif