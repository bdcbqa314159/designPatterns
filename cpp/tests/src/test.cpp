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

void openCloseTester()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};
    Product sky{"Sky", Color::blue, Size::large};

    const vector<Product *> all{&apple, &tree, &house, &sky};

    // This is a bad practice:
    ProductFilter filter;
    auto answer1 = filter.by_color(all, Color::green);

    for (auto &i : answer1)
    {
        std::cout << i->name << " is green." << std::endl;
    }

    auto answer2 = filter.by_size_and_color(all, Color::green, Size::large);

    for (auto &i : answer2)
    {
        std::cout << i->name << " is green & large." << std::endl;
    }
    // End of bad practice.

    // This respects the open-close principle:
    BetterFilter bf;
    ColorSpecification green(Color::green);

    auto green_objects = bf.filter(all, green);
    std::cout << "### With better filter. ###" << std::endl;

    for (auto &i : green_objects)
    {
        std::cout << i->name << " is green." << std::endl;
    }

    SizeSpecification large(Size::large);
    // We will use operator && for this.
    AndSpecification green_large(green, large);

    auto green_big_objects = bf.filter(all, green_large);

    for (auto &i : green_big_objects)
    {
        std::cout << i->name << " is green & large." << std::endl;
    }

    auto spec = green && large;

    auto green_big_objects1 = bf.filter(all, spec);

    for (auto &i : green_big_objects1)
    {
        std::cout << i->name << " is green & large." << std::endl;
    }
    auto spec1 = ColorSpecification{Color::blue} && SizeSpecification{Size::large};

    auto blue_big_objects = bf.filter(all, spec1);

    for (auto &i : blue_big_objects)
    {
        std::cout << i->name << " is blue & large." << std::endl;
    }
}

void lyskovTester()
{

    Rectangle r(5, 5);
    process(r);

    Square sq(5);
    process(sq);
}

void interfaceAggregationTester()
{

    Document doc;

    SingleScanner scan;
    scan.scan(doc);
    scan.print(doc);

    Printer p;
    Scanner sc;

    Machine machine(p, sc);

    machine.print(doc);
    machine.scan(doc);
}

void dependencyInversionTester()
{
    Person parent("John");
    Person child1("Chris");
    Person child2("Matt");

    Relationships relationships;

    relationships.add_parent_and_child(parent, child1);

    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);
}

void builderPatternTester()
{
    std::cout << "Bad way to build a complex object such as formatted text:" << std::endl;
    badBuilder();
    std::cout << std::endl;
    std::cout << "Easier way to build a complex object" << std::endl;

    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello").add_child("li", "world");
    std::cout << builder.str() << std::endl;
}

void groovyStyleTester()
{

    std::cout << "Builiding a HTML like doc..." << std::endl;

    std::cout << html::P{
                     html::IMG{"https::pokemon.com/pikachu.png"}}
              << std::endl;
}

void facetsTester()
{
    builder::Person p = builder::Person::create()
                            .lives()
                            .at("123 London Road")
                            .with_postcode("SW1 1GB")
                            .in("London")
                            .works()
                            .at("PragmaSoft")
                            .as_a("Consultant")
                            .earning(10e6);

    cout << p << endl;
}

int main()
{

    // messageCool();
    // singleResponsabilityTester();
    // openCloseTester();
    // lyskovTester();
    // interfaceAggregationTester();
    // dependencyInversionTester();
    builderPatternTester();
    groovyStyleTester();
    facetsTester();

    return 0;
}