#ifndef BP_H
#define BP_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

// void badBuilder()
// {
//     string text = "hello";
//     string out = "<p>" + text + "</p>";

//     cout << out << endl;

//     string words[] = {"hello", "world"};

//     ostringstream oss;
//     oss << "<ul>";

//     for (auto &w : words)
//     {
//         oss << "<li>" << w << "</li>";
//     }

//     oss << "</ul>";

//     cout << oss.str() << endl;
// }

// struct HtmlBuilder;

// struct HtmlElement
// {
//     string name;
//     string text;
//     vector<HtmlElement> elements;

//     const size_t indent_size = 2;

//     HtmlElement() {}

//     HtmlElement(const string &name, const string &text) : name(name), text(text) {}

//     string str(int indent = 0) const
//     {

//         ostringstream oss;
//         string i(indent_size * indent, ' ');
//         oss << i << "<" << name << ">" << endl;

//         if (text.size() > 0)
//         {
//             oss << string(indent_size * (indent + 1), ' ') << text << endl;
//         }

//         for (auto &element : elements)
//         {
//             oss << element.str(indent + 1) << endl;
//         }

//         oss << i << "</" << name << ">" << endl;
//         return oss.str();
//     }

//     static unique_ptr<HtmlBuilder> build(string root_name)
//     {
//         return make_unique<HtmlBuilder>(root_name);
//     }
// };

// struct HtmlBuilder
// {
//     HtmlElement root;

//     HtmlBuilder(string root_name)
//     {
//         root.name = root_name;
//     }

//     HtmlBuilder &add_child(string name, string text)
//     {

//         HtmlElement element{name, text};
//         root.elements.emplace_back(element);
//         return *this;
//     }

//     HtmlBuilder *add_child2(string name, string text)
//     {

//         HtmlElement element{name, text};
//         root.elements.emplace_back(element);
//         return this;
//     }

//     string str()
//     {
//         return root.str();
//     }

//     operator HtmlElement() const
//     {
//         return root;
//     }
// };

void badBuilder()
{

    string text = "hello";
    string out = "<p>" + text + "</p>";

    cout << out << endl;

    string words[] = {"hello", "world"};
    ostringstream oss;

    oss << "<ul>";

    for (auto &w : words)
    {
        oss << "<li>" << w << "</li>";
    }

    oss << "</ul>";

    cout << oss.str() << endl;
}

struct HtmlBuilder;

struct HtmlElement
{

    string name, text;
    vector<HtmlElement> elements;

    const size_t indent_size = 2;

    HtmlElement()
    {
    }

    HtmlElement(const string &name, const string &text) : name(name), text(text)
    {
    }

    string str(int indent = 0) const
    {

        ostringstream oss;
        string i(indent * indent_size, ' ');
        oss << i << "<" << name << ">" << endl;

        if (text.size())
        {
            oss << string(indent_size * (indent + 1), ' ') << text << endl;
        }

        for (auto &e : elements)
        {
            oss << e.str(indent + 1) << endl;
        }

        oss << "</" << name << ">" << endl;
        return oss.str();
    }

    static unique_ptr<HtmlBuilder> build(string root_name)
    {
        return make_unique<HtmlBuilder>(root_name);
    }
};

struct HtmlBuilder
{

    HtmlElement root;

    HtmlBuilder(string root_name)
    {
        root.name = root_name;
    }

    HtmlBuilder &add_child(string name, string text)
    {
        HtmlElement e{name, text};
        root.elements.emplace_back(e);
        return *this;
    }

    HtmlBuilder *add_child2(string name, string text)
    {
        HtmlElement e{name, text};
        root.elements.emplace_back(e);
        return this;
    }

    string str() const
    {
        return root.str();
    }

    operator HtmlElement() const
    {
        return root;
    }
};

#endif

// We use the builder pattern in order to create an object oriented structure before trying to create the object we intend to.
// So in principle we use an object oriented structure & an object oriented builder which takes care of the initialisation.
/* rather than use this
class A{
    A(){

    }
};

int main(){
    A a; //->this in the builder.
}
*/