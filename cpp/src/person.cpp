#include "../include/designPatterns_bits/person.hpp"
#include "../include/designPatterns_bits/personBuilder.hpp"

namespace builder
{

    PersonBuilder Person::create()
    {
        return PersonBuilder{};
    }
}

// namespace builder1
// {
//     PersonBuilder Person::create()
//     {
//         return PersonBuilder{};
//     }
// }