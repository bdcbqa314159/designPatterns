#ifndef FPERSON_H
#define FPERSON_H

#include <string>
#include <iostream>

using namespace std;

namespace builder
{

    class PersonBuilder;

    class Person
    {
        string street_address, post_code, city;
        string company_name, position;
        int annual_income{0};

        Person()
        {
            cout << "Person created" << endl;
        }

    public:
        ~Person()
        {
            cout << "Person destroyed" << endl;
        }

        static PersonBuilder create();

        Person(Person &&other) : street_address(move(other.street_address)), post_code(move(other.post_code)), city(move(other.city)), position(move(other.position)), company_name(move(other.company_name)), annual_income(move(other.annual_income))
        {
        }

        Person &operator=(Person &&other)
        {
            if (this == &other)
            {
                return *this;
            }

            street_address = move(other.street_address);
            post_code = move(other.post_code);
            city = move(other.city);
            company_name = move(other.company_name);
            position = move(other.position);
            annual_income = move(other.annual_income);

            return *this;
        }

        friend ostream &operator<<(ostream &os, const Person &person)
        {

            os << " street address: " << person.street_address << " post code: " << person.post_code << " city: " << person.city << " position: " << person.position << " company: " << person.company_name << " annual income: " << person.annual_income << endl;

            return os;
        }

        friend class PersonBuilder;
        friend class PersonAddressBuilder;
        friend class PersonJobBuilder;
    };
}

#endif