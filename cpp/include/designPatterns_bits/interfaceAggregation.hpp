#ifndef IAP
#define IAP

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Document
{

    string title;
    vector<string> lines;
};

struct IMachineBad
{

    virtual void print(Document &doc) = 0;
    virtual void scan(Document &doc) = 0;
    virtual void fax(Document &doc) = 0;
};

struct MFP : IMachineBad
{

    void print(Document &doc) override
    {
        std::cout << "printing with a bad interface :(" << std::endl;
    }

    void scan(Document &doc) override
    {
        std::cout << "scanning with a bad interface :(" << std::endl;
    }

    void fax(Document &doc) override
    {
        std::cout << "faxing with a bad interface :(" << std::endl;
    }
};

struct SingleScanner : IMachineBad
{

    void print(Document &doc) override
    {
        std::cout << "nothing here coz only scanner :(" << std::endl;
    }

    void scan(Document &doc) override
    {
        std::cout << "scanning with a bad interface :(" << std::endl;
    }

    void fax(Document &doc) override
    {
        std::cout << "nothing here coz only scanner :(" << std::endl;
    }
};

struct IPrinter
{
    virtual void print(Document &doc) = 0;
};

struct IFaxer
{
    virtual void fax(Document &doc) = 0;
};

struct IScanner
{

    virtual void scan(Document &doc) = 0;
};

struct Printer : IPrinter
{

    void print(Document &doc)
    {
        std::cout << "printing with a better interface :)" << std::endl;
    }
};

struct Scanner : IScanner
{

    void scan(Document &doc)
    {
        std::cout << "scanning with a better interface :)" << std::endl;
    }
};

struct IMachine : IPrinter, IScanner
{
};

struct Machine : IMachine
{
    IPrinter &printer;
    IScanner &scanner;

    Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner)
    {
    }

    void print(Document &doc)
    {
        printer.print(doc);
    }

    void scan(Document &doc)
    {
        scanner.scan(doc);
    }
};

#endif

/*Interface Aggregation Principle is to avoid too big interfaces, mix the single responsability and then aggregate them according with the need we have.*/

// First IMachine struct is too big and forces to implement something with holes & send a bad message to the user.
// See SingleScanner implementation.
// Better implemention: using one single virtual interface gives a more flexible code and at the end a better fashioned interface.