#include <iostream>

using namespace std;

class SomeClass {
    private:
    static int id;
    // static int num1;
    // static int num2;
    // static int num3;

    public:
    SomeClass();
    static int getId();
    // static void displayInfo();
};

int SomeClass::id = 0;
// int SomeClass::num1 = 10;
// int SomeClass::num2 = 20;
// int SomeClass::num3 = 30;

int main(int argc, char* argv[])
{
    // SomeClass sc1;
    // SomeClass sc2;
    // SomeClass sc3;
    // SomeClass sc4;
    // SomeClass sc5;
    for(int i = 0; i < 10; i++) {
        SomeClass* sc = new SomeClass();
        delete sc;
    }
    cout << SomeClass::getId() << endl;
    // SomeClass sc1;

    // sc1.displayInfo();

    // SomeClass::displayInfo();
    return 0;
}

int SomeClass::getId()
{
    return id;
}

SomeClass::SomeClass()
{
    id++;
}

// void SomeClass::displayInfo()
// {
//     cout << "num1: " << num1 << endl;
//     cout << "num1: " << num2 << endl;
//     cout << "num1: " << num3 << endl;
// }