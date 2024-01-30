/*
Name: Jeremy Bergen

Fraction Calculator
*/
#include <iostream>

using namespace std;

class Fraction {
    private:
    int _numerator;
    int _denom;
    public:
    Fraction();
    ~Fraction();

    //setters
    void setNumerator(int);
    void setDenom(int);
    //getters
};

int main(int argc, char* argv[])
{
    Fraction frac1;
    Fraction frac2;


    return 0;
}

Fraction::Fraction()
{
    _numerator = 0;
    _denom = 1;
}

Fraction::~Fraction()
{

}

void Fraction::setNumerator(int numerator)
{
    _numerator = numerator;
}
void Fraction::setDenom(int denom)
{
    while(denom == 0)
    {
        cout << "The denominator must not be zero. ";
        cin >> denom;
    }
    _denom = denom;
}