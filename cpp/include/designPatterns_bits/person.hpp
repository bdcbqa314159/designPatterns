#ifndef FPERSON_H
#define FPERSON_H

#include <string>
#include <iostream>

using namespace std;

// namespace builder1
// {

//     class PersonBuilder;

//     class Person
//     {

//         string street_address, postcode, city;
//         string position, company_name;
//         int annual_income{0};

//         Person()
//         {
//             cout << "Person created" << endl;
//         }

//     public:
//         ~Person()
//         {
//             cout << "Person destroyed." << endl;
//         }

//         static PersonBuilder create();

//         Person(Person &&other) : street_address(move(other.street_address)), postcode(move(other.postcode)), city(move(other.city)), company_name(move(other.company_name)), position(move(other.position)), annual_income(move(other.annual_income))
//         {
//         }

//         static PersonBuilder create();

//         Person &operator=(Person &&other)
//         {
//             if (this == &other)
//             {
//                 return *this;
//             }

//             street_address = move(other.street_address);
//             postcode = move(other.postcode);
//             city = move(other.city);
//             company_name = move(other.company_name);
//             position = move(other.position);
//             annual_income = move(other.annual_income);

//             return *this;
//         }

//         friend ostream &operator<<(ostream &os, const Person &p)
//         {
//             os << " street address: " << p.street_address << " postcode: " << p.postcode << " city: " << p.city << " position: " << p.position << " company: " << p.company_name << " annual income: " << p.annual_income;

//             return os;
//         }

//         friend class PersonBuilder;
//         friend class PersonAddressBuilder;
//         friend class PersonJobBuilder;
//     };
// }

namespace builder
{

    class PersonBuilder;

    class Person
    {

        string street_name, postcode, city;
        string company_name, position;
        int annual_income;

        Person()
        {
            cout << "Person created" << endl;
        }

    public:
        ~Person()
        {
            cout << "Person destroyed" << endl;
        }

        Person(Person &&other) : street_name(move(other.street_name)), postcode(move(other.postcode)), city(move(other.city)), company_name(move(other.company_name)), position(move(other.position)), annual_income(move(other.annual_income))
        {
        }

        static PersonBuilder create();

        Person &operator=(Person &&p)
        {

            if (this == &p)
            {
                return *this;
            }

            street_name = move(p.street_name);
            postcode = move(p.postcode);
            city = move(p.city);
            company_name = move(p.company_name);
            position = move(p.position);
            annual_income = move(p.annual_income);

            return *this;
        }

        friend ostream &operator<<(ostream &os, const Person &p)
        {
            os << " street address: " << p.street_name << " with postcode: " << p.postcode << " in: " << p.city << " working as: " << p.position << " at: " << p.company_name << " earning: " << p.annual_income;

            return os;
        }

        friend class PersonBuilder;
        friend class PersonAddressBuilder;
        friend class PersonJobBuilder;
    };

}

#endif