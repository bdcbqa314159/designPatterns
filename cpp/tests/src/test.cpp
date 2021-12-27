#include <designPatterns>
#include <iostream>

void singleResponsabilityTester()
{
    std::cout << "Working with the single responsability principle." << std::endl;

    Journal journal("My diary");
    journal.add("I ate a bug");
    journal.add("I cried today");

    // journal.save("journal1");
    PersistenceManager pm;
    pm.save(journal, "journal2");
    std::cout << "type cat #filename# and check the content of the docs" << std::endl;
}

int main()
{

    messageCool();
    singleResponsabilityTester();

    return 0;
}