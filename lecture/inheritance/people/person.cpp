#include "person.h"

person::Person::Person(string name, int age, int height)
{
    _name = name;
    _age = age;
    _height = height;
    cout << "Creating a new person." << endl;
}

string person::Person::getName()
{
    return _name;
}

string person::Person::getHeight()
{
    int feet, inches;
    string returnStr = "";
    feet = _height/12;
    inches = _height%12;

    if(feet == 0) {
        returnStr = to_string(inches) + " in tall.";
        return returnStr;
    } else {
        returnStr = to_string(feet) + " ft " + to_string(inches) + " in tall.";
        return returnStr;
    }
}