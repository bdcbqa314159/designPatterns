#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>
#include <iostream>
#include <sstream>
#include <memory>

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;
using namespace boost;

struct Address
{

    string street;
    string city;
    int suite;

    Address()
    {
    }

    Address(const string &street, const string &city, const int suite) : street{street}, city{city}, suite{suite}
    {
    }

    Address(const Address &address) : street{address.street}, city{address.city}, suite{address.suite}
    {
    }

    friend ostream &operator<<(ostream &os, const Address &obj)
    {
        return os << "street : " << obj.street << " city : " << obj.city << " suite : " << obj.suite;
    }

private:
    friend class serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned version)
    {
        ar &street;
        ar &city;
        ar &suite;
    }
};

struct Contact
{
    string name;
    Address *address;

    Contact &operator=(const Contact &other)
    {
        if (this == &other)
        {
            return *this;
        }

        name = other.name;
        address = other.address;
        return *this;
    }

    Contact()
    {
    }

    Contact(string name, Address *address) : name{name}, address{address}
    {
        this->address = new Address{*address};
    }

    Contact(const Contact &other) : name{other.name}, address{new Address{*other.address}}
    {
    }

    ~Contact()
    {
        delete address;
    }

    friend ostream &operator<<(ostream &os, const Contact &obj)
    {
        os << "name: " << obj.name << " works at : " << *obj.address;

        return os;
    }

private:
    friend class serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned version)
    {
        ar &name;
        ar &address;
    }
};

struct EmployeeFactory
{

    static unique_ptr<Contact> newMainOfficeEmployee(string name, int suite)
    {
        static Contact main{"", new Address{"123 East Dr", "London", 0}};

        return NewEmployee(name, suite, main);
    }

private:
    static unique_ptr<Contact> NewEmployee(string name, int suite, Contact &prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

Contact inOutSerialize(const Contact &c)
{
    ostringstream oss;
    archive::text_oarchive oa(oss);
    oa << c;
    string s = oss.str();
    cout << s << endl;

    istringstream iss(s);
    archive::text_iarchive ia(iss);
    Contact result;
    ia >> result;
    return result;
};

#endif

// Several steps
/*
1) Doing copy constructor & copy assignement.
2) Create a factory with a private constructor and make unique framework from a static prototype.
3) Boost serialization.
*/