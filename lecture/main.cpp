/*
Name: Jeremy Bergen

Classes!!!
*/
#include <iostream>
#include <string>

using namespace std;

class Dog {
    private:
    string _name;
    string _breed;
    float _weight;
    int _numLegs;
    char _gender;

    public:
    void setName(string);
    string getName();
    void setNumLegs(int);

    void speak();

};

int main(int argc, char* argv[])
{
    Dog dog1;

    dog1.setName("Novoabcdefhijklmnop");
    dog1.setNumLegs(0);
    // dog1.name = "Novo";
    // dog1.breed = "Husky";
    // dog1.weight = 50;
    // dog1.numLegs = 4;
    // dog1.gender = 'M';

    dog1.speak();
    cout << "The name of dog1 is: " << dog1.getName() << endl;
    return 0;
}

void Dog::setNumLegs(int numLegs)
{
    while(!(numLegs < 5 && numLegs > 0))
    {
        cout << "Number of legs must be between 1 and 4" << endl;
        cin >> numLegs;
    }
    _numLegs = numLegs;
}

void Dog::setName(string newName)
{
    while(!(newName.length() < 10))
    {
        // if(newName.length() > 10) {
        cout << "The name is longer than 10 characters, try again" << endl;

        // }
        getline(cin, newName);
    }
    _name = newName;
}

string Dog::getName()
{
    return _name;
}

void Dog::speak()
{
    cout << _name << " barks." << endl;
}