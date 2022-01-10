#include "../include/designPatterns_bits/personBuilder.hpp"

// namespace builder
// {
//     PersonAddressBuilder PersonBuilderBase::lives() const
//     {
//         return PersonAddressBuilder{person};
//     }

//     PersonJobBuilder PersonBuilderBase::works() const
//     {
//         return PersonJobBuilder{person};
//     }
// }

namespace builder
{

    PersonAddressBuilder PersonBuilderBase::lives() const
    {
        return PersonAddressBuilder{person};
    }

    PersonJobBuilder PersonBuilderBase::works() const
    {
        return PersonJobBuilder{person};
    }
}