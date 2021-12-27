#include <designPatterns>

void singleResponsabilityTester()
{
    Journal journal("My diary");
    journal.add("I ate a bug");
    journal.add("I cried today");

    // journal.save("journal1");
    PersistenceManager pm;
    pm.save(journal, "journal2");
}

int main()
{

    messageCool();
    singleResponsabilityTester();

    return 0;
}