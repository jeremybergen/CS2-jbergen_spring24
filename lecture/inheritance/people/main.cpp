#include <iostream>
#include <string>

using namespace std;

class Base {
    private:
    int _n1;
    string _name;

    protected:
    int getN1();

    public:
    Base();
    
};

class Derived : Base {
    private:
    string _something;

    public:
    Derived();
    int derivedGetN1();
};

int main(int argc, char* argv[])
{
    Derived d1;

    cout << "d1.getN1(): " << d1.derivedGetN1() << endl;

    return 0;
}

int Derived::derivedGetN1()
{
    return this->getN1();
    // return (*this).getN1();
}

int Base::getN1()
{
    return this->_n1;
}

Derived::Derived()
{
    cout << "Derived constructor" << endl;
    _something = "";
}

Base::Base()
{
    cout << "Base constructor" << endl;
    this->_n1 = 42;
    this->_name = "";
}