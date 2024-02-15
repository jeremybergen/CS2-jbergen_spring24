#include <iostream>

using namespace std;

// int addNums(int, int);
// float addNums(float, float);

// class Base {
//     public:
//     virtual void print() = 0;
//     virtual void show() = 0;
// };

// class Derived : public Base {
//     public:
//     void print();
//     void show();
// };
class Animal {
    protected:
    Animal();
    public:
    
    virtual ~Animal();
    virtual char eat(int, int) = 0;
};

class Mammal : public Animal {
    public:
    Mammal();
    ~Mammal();
    char eat(int, int);
};

int main(int argc, char* argv[])
{
    // Animal a1;
    Mammal d1;
    // Animal* a1;
    // Mammal d1;
    // a1 = &d1;
    // Mammal *d1 = new Mammal();
    // Animal *a1 = d1;

    // cout << a1->eat(1, 2) << endl;

    // delete a1;
    // Derived d1;
    // Base *b1;
    // Derived d1;
    // b1 = &d1;

    // b1->print();
    // b1->show();
    // float num1, num2;
    // num1 = 42;
    // num2 = 15;

    // cout << addNums(num1, num2) << endl;

    // int num3, num4;
    // num3 = 42;
    // num4 = 15;

    // cout << addNums(num3, num4) << endl;
    return 0;
}

Animal::Animal()
{
    cout << "Animal Constructor" << endl;
}
Animal::~Animal()
{
    cout << "Animal Destructor" << endl;
}

Mammal::Mammal()
{
    cout << "Mammal Constructor" << endl;
}
Mammal::~Mammal()
{
    cout << "Mammal Destructor" << endl;
}

char Mammal::eat(int n1, int n2)
{
    return 'J';
}

// void Base::print()
// {
//     cout << "Inside Base print" << endl;
// }
// void Base::show()
// {
//     cout << "Inside Base show" << endl;
// }

// void Derived::print()
// {
//     cout << "Inside Derived print" << endl;
// }
// void Derived::show()
// {
//     cout << "Inside Derived show" << endl;
// }

// float addNums(float n1, float n2)
// {
//     return n1 + n2;
// }

// int addNums(int n1, int n2)
// {
//     return n1 + n2;
// }