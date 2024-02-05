/*
Name: Jeremy Bergen

Fraction Calculator
*/
#include <iostream>
#include <string>

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
    int getNumerator();
    int getDenom();

    //operator overloading

    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);
    friend ostream& operator<<(ostream&, const Fraction&);
};

Fraction addFractions(Fraction, Fraction);

int main(int argc, char* argv[])
{
    char ch;
    int num, den;
    Fraction frac1;
    Fraction frac2;
    Fraction frac3;

    Fraction addedFrac;
    Fraction subFrac;

    cout << "Enter the numerator and denominator for fraction 1: ";
    cin >> num >> ch >> den;
    frac1.setNumerator(num);
    frac1.setDenom(den);

    cout << "Enter the numerator and denominator for fraction 2: ";
    cin >> num >> ch >> den;
    frac2.setNumerator(num);
    frac2.setDenom(den);

    cout << "Enter the numerator and denominator for fraction 3: ";
    cin >> num >> ch >> den;
    frac3.setNumerator(num);
    frac3.setDenom(den);

    // addedFrac = addFractions(frac1, addFractions(frac2, frac3));
    addedFrac = frac1 + (frac2 + frac3);

    subFrac = frac1 - frac2;

    cout << frac1 << " + " 
         << frac2 << " + "
         << frac3 << " = "
         << addedFrac.getNumerator() << "/" << addedFrac.getDenom() << endl;

    cout << frac1 << " - " 
         << frac2 << " = "
         << subFrac.getNumerator() << "/" << subFrac.getDenom() << endl;

    return 0;
}

ostream& operator<<(ostream& os, const Fraction& f1)
{
    os << f1._numerator << '/' << f1._denom;
    return os;
}

Fraction Fraction::operator-(const Fraction& f1)
{
    Fraction subFrac;
    int commonDenom;
    int n1, n2;
    commonDenom = _denom * f1._denom;
    n1 = _numerator * f1._denom;
    n2 = f1._numerator * _denom;

    subFrac.setNumerator(n1 - n2);
    subFrac.setDenom(commonDenom);

    //a return
    return subFrac;
}

Fraction Fraction::operator+(const Fraction& f1)
{
    Fraction addedFrac;
    int commonDenom;
    int n1, n2;
    commonDenom = _denom * f1._denom;
    n1 = _numerator * f1._denom;
    n2 = f1._numerator * _denom;

    addedFrac.setNumerator(n1 + n2);
    addedFrac.setDenom(commonDenom);

    return addedFrac;
}

Fraction addFractions(Fraction f1, Fraction f2)
{
    Fraction addedFrac;
    int commonDenom = 0;
    int num1, num2;
    commonDenom = f1.getDenom() * f2.getDenom();
    num1 = f1.getNumerator() * f2.getDenom();
    num2 = f2.getNumerator() * f1.getDenom();

    addedFrac.setNumerator(num1 + num2);
    addedFrac.setDenom(commonDenom);

    return addedFrac;
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
        cout << "The denominator must not be zero: ";
        cin >> denom;
    }
    _denom = denom;
}

int Fraction::getNumerator()
{
    return _numerator;
}

int Fraction::getDenom()
{
    return _denom;
}