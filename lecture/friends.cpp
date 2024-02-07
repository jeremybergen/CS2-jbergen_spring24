#include <iostream>

using namespace std;

// class Rectangle {
//     private:
//     int _side1, _side2;

//     public:
//     // Rectangle(int, int);
//     friend int calcArea(Rectangle&);
//     friend void setVals(Rectangle&);
// };

// int calcArea(Rectangle&);
// void setVals(Rectangle&);
class Aclass;
class Bclass;

class Aclass {
    private:
    int _number1;
    
    public:
    void setNumber1(int);
    friend void max(Aclass&, Bclass&);
};

class Bclass {
    private:
    int _number1;
    
    public:
    void setNumber1(int);
    friend void max(Aclass&, Bclass&);
};

void max(Aclass&, Bclass&);

int main(int argc, char* argv[])
{
    Aclass a1;
    Bclass b1;

    a1.setNumber1(15);
    b1.setNumber1(42);

    max(a1, b1);
    // Rectangle rect1(10, 2);
    // Rectangle rect1;

    // setVals(rect1);

    // cout << "The area of our rectangle is: " << calcArea(rect1) << endl;
    return 0;
}

void max(Aclass& a1, Bclass& b1)
{
    if(a1._number1 > b1._number1)
    {
        cout << "Aclass is greater than Bclass" << endl;
    } else
    {
        cout << "Bclass is greater than Aclass" << endl;
    }
}

void Aclass::setNumber1(int n1)
{
    _number1 = n1;
}

void Bclass::setNumber1(int n1)
{
    _number1 = n1;
}

// void setVals(Rectangle& r1)
// {
//     cout << "Enter side 1: ";
//     cin >> r1._side1;

//     cout << "Enter side 2: ";
//     cin >> r1._side2;
// }

// int calcArea(Rectangle& r1)
// {
//     int area;
//     area = r1._side1 * r1._side2;
//     return area;
// }

// Rectangle::Rectangle(int side1, int side2)
// {
//     _side1 = side1;
//     _side2 = side2;
// }