#include <iostream>

using namespace std;

class Base1
{
    protected:
    int _base1;

    public:
    void setBase1(int);
};

class Base2
{
    protected:
    int _base1;

    public:
    void setBase1(int);
};

class Derived : public Base1, public Base2
{
    public:
    void showInfo();
};


int main(int argc, char* argv[])
{
    Derived d1;

    d1.Base1::setBase1(42);
    d1.Base2::setBase1(15);
    d1.showInfo();
    return 0;
}

void Derived::showInfo()
{
    cout << "Base1: " << Base1::_base1 << ", Base2: " << Base2::_base1 << endl;
}

void Base1::setBase1(int base)
{
    _base1 = base;
}

void Base2::setBase1(int base)
{
    _base1 = base;
}