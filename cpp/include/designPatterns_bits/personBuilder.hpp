#ifndef FPERSONBUILDER_H
#define FPERSONBUILDER_H

#include "person.hpp"

// namespace builder
// {

//     class PersonAddressBuilder;
//     class PersonJobBuilder;

//     class PersonBuilderBase
//     {

//     protected:
//         Person &person;

//         explicit PersonBuilderBase(Person &person) : person(person)
//         {
//         }

//     public:
//         operator Person() const
//         {
//             return move(person);
//         }

//         PersonAddressBuilder lives() const;
//         PersonJobBuilder works() const;
//     };

//     class PersonBuilder : public PersonBuilderBase
//     {

//         Person p;

//     public:
//         explicit PersonBuilder() : PersonBuilderBase(p)
//         {
//         }
//     };

//     class PersonAddressBuilder : public PersonBuilderBase
//     {
//         typedef PersonAddressBuilder self;

//     public:
//         explicit PersonAddressBuilder(Person &p) : PersonBuilderBase(p)
//         {
//         }

//         self &at(const string &street_address)
//         {
//             person.street_name = street_address;
//             return *this;
//         }

//         self &with_postcode(const string &postcode)
//         {
//             person.postcode = postcode;
//             return *this;
//         }

//         self &in(const string &city)
//         {
//             person.city = city;
//             return *this;
//         }
//     };

//     class PersonJobBuilder : public PersonBuilderBase
//     {
//         typedef PersonJobBuilder self;

//     public:
//         explicit PersonJobBuilder(Person &p) : PersonBuilderBase(p)
//         {
//         }

//         self &at(const string &company_name)
//         {
//             person.company_name = company_name;
//             return *this;
//         }

//         self &as_a(const string &position)
//         {
//             person.position = position;
//             return *this;
//         }

//         self &earning(const int &annual_income)
//         {
//             person.annual_income = annual_income;
//             return *this;
//         }
//     };
// }

namespace builder
{

    class PersonAddressBuilder;
    class PersonJobBuilder;

    class PersonBuilderBase
    {
    protected:
        Person &person;

        explicit PersonBuilderBase(Person &person) : person(person)
        {
        }

    public:
        operator Person() const
        {
            return move(person);
        }

        PersonAddressBuilder lives() const;
        PersonJobBuilder works() const;
    };

    class PersonBuilder : public PersonBuilderBase
    {
        Person p;

    public:
        PersonBuilder() : PersonBuilderBase(p)
        {
        }
    };

    class PersonAddressBuilder : public PersonBuilderBase
    {
        typedef PersonAddressBuilder self;

    public:
        explicit PersonAddressBuilder(Person &p) : PersonBuilderBase(p)
        {
        }

        self &at(const string &street_address)
        {
            person.street_name = street_address;
            return *this;
        }

        self &with_postcode(const string &postcode)
        {
            person.postcode = postcode;
            return *this;
        }

        self &in(const string &city)
        {
            person.city = city;
            return *this;
        }
    };

    class PersonJobBuilder : public PersonBuilderBase
    {
        typedef PersonJobBuilder self;

    public:
        explicit PersonJobBuilder(Person &p) : PersonBuilderBase(p)
        {
        }

        self &at(const string &company)
        {
            person.company_name = company;
            return *this;
        }

        self &as_a(const string &position)
        {
            person.position = position;
            return *this;
        }

        self &earning(const int &annual_income)
        {
            person.annual_income = annual_income;
            return *this;
        }
    };
}

#endif