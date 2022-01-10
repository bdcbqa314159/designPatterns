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

        Person(Person &&other) : street_address(move(other.street_address)), post_code(move(other.post_code)), city(move(other.city)), position(move(other.position)), annual_income(move(other.annual_income))
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
            position = move(other.position);
            annual_income = move(other.annual_income);

            return *this;
        }

        friend ostream &operator<<(ostream &os, const Person &person)
        {

            os << "street address :" << person.street_address << " postcode: " << person.post_code << " city: " << person.city << " position: " << person.position << " annual income: " << person.annual_income << endl;

            return os;
        }
        friend class PersonBuilder;
        friend class PersonAddressBuilder;
        friend class PersonJobBuilder;
    };

}

// namespace builder1
// {
//     class PersonBuilder;

//     class Person
//     {

//         string street_address, post_code, city;

//         string company_name, position;

//         int annual_income{0};

//         Person()
//         {
//             cout << "Person created" << endl;
//         }

//     public:
//         ~Person()
//         {
//             cout << "Person destroyed" << endl;
//         }

//         static PersonBuilder create();

//         Person(Person &&other) : street_address(move(other.street_address)), post_code(move(other.post_code)), city(move(other.city)), company_name(move(other.company_name)), position(move(other.position)), annual_income(move(other.annual_income))
//         {
//         }

//         Person &operator=(Person &&other)
//         {
//             if (this == &other)
//             {
//                 return *this;
//             }

//             street_address = move(other.street_address);
//             post_code = move(other.post_code);
//             city = move(other.city);
//             company_name = move(other.company_name);
//             position = move(other.position);
//             annual_income = move(other.annual_income);

//             return *this;
//         }

//         friend ostream &operator<<(ostream &os, const Person &obj)
//         {
//             return os << "street_address: " << obj.street_address << " post_code: " << obj.post_code << " city: " << obj.city << " company_name: " << obj.company_name << " positon: " << obj.position << " annual_income: " << obj.annual_income;
//         }

//         friend class PersonBuilder;
//         friend class PersonAddressBuilder;
//         friend class PersonJobBuilder;
//     };
// }
#endif