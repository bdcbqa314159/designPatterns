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
    virtual void fax(Document &doc) = 0;
    virtual void scan(Document &doc) = 0;
};

struct MFP : IMachineBad
{

    void print(Document &doc) override
    {
        cout << "printing doc" << endl;
    };

    void fax(Document &doc) override
    {
        cout << "faxing doc" << endl;
    };
    void scan(Document &doc) override
    {
        cout << "faxing doc" << endl;
    };
};

struct SingleScanner : IMachineBad
{

    void print(Document &doc) override
    {
        cout << "nothing" << endl;
    };

    void fax(Document &doc) override
    {
        cout << "nothing" << endl;
    };
    void scan(Document &doc) override
    {
        cout << "faxing doc" << endl;
    };
};

struct IPrinter
{

    virtual void print(Document &doc) = 0;
};

struct IScanner
{

    virtual void scan(Document &doc) = 0;
};

struct IFaxer
{

    virtual void fax(Document &doc) = 0;
};

struct Printer : IPrinter
{

    void print(Document &doc) override
    {
        cout << "printing" << endl;
    }
};

struct Scanner : IScanner
{

    void scan(Document &doc) override
    {
        cout << "scanning" << endl;
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

    void print(Document &doc) override
    {
        printer.print(doc);
    }

    void scan(Document &doc) override
    {
        scanner.scan(doc);
    }
};

#endif

/*Interface Aggregation Principle is to avoid too big interfaces, mix the single responsability and then aggregate them according with the need we have.*/

// First IMachine struct is too big and forces to implement something with holes & send a bad message to the user.
// See SingleScanner implementation.
// Better implemention: using one single virtual interface gives a more flexible code and at the end a better fashioned interface.