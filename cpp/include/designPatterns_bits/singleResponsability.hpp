#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;

struct Journal
{
    string title;
    vector<string> entries;

    explicit Journal(const string &title) : title{title}
    {
    }

    void add(const string &entry);

    void save(const string &filename);
};

void Journal::add(const string &entry)
{
    static int count = 1;
    entries.push_back(boost::lexical_cast<string>(count++) + " : " + entry);
}

void Journal::save(const string &filename)
{

    ofstream ofs(filename);
    for (auto &s : entries)
    {
        ofs << s << endl;
    }
}

struct PersistenceManager
{

    void save(const Journal &j, const string &filename)
    {
        ofstream ofs(filename);
        for (auto &s : j.entries)
        {
            ofs << s << endl;
        }
    }
};

/*
The methode is the "work" of the class.
The save is too much in violates the single responsability concept.

Too many persistences -> we create a Manager for saving for journals and open for others classes
*/
