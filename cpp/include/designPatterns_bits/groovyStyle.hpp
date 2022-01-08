#ifndef GS_H
#define GS_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace html
{

    struct Tag
    {
        string text, name;
        vector<Tag> children;
        vector<pair<string, string>> attributes;

        friend ostream &operator<<(ostream &os, const Tag &tag)
        {

            os << "<" << tag.name;

            for (const auto &att : tag.attributes)
            {
                os << " " << att.first << "=\"" << att.second << "\"";
            }

            if (tag.children.size() == 0 && tag.attributes.size() == 0)
            {
                os << "/>";
            }

            else
            {

                os << ">" << endl;

                if (tag.text.length())
                {
                    os << tag.text << endl;
                }

                for (const auto &child : tag.children)
                {
                    os << child << endl;
                }

                os << "</" << tag.name << ">" << endl;
            }

            return os;
        }

        Tag(const string &name, const string &text) : name(name), text(text)
        {
        }

        Tag(const string &name, const vector<Tag> children) : name(name), children(children)
        {
        }
    };

    struct P : Tag
    {
        P(const string &text) : Tag("p", text)
        {
        }

        explicit P(initializer_list<Tag> children) : Tag("p", children)
        {
        }
    };

    struct IMG : Tag
    {

        explicit IMG(const string &url) : Tag("src", "")
        {
            attributes.emplace_back(make_pair("img", url));
        }
    };
}

#endif