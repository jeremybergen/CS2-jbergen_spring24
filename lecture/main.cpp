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
    Dog(string, string = "Jerk", float = 50, int = 4, char = 'U');
    // Dog(string, string);
    ~Dog();
    void setName(string);
    string getName();
    void setNumLegs(int);
    void getNumLegs();

    void speak();

};

int main(int argc, char* argv[])
{
    Dog* dogs[5];

    for(int i = 0; i < 5; i++)
    {
        Dog* dog1 = new Dog("Novo");
        if(i == 2)
        {
            dog1->setName("Novo");
            dog1->setNumLegs(4);
        }
        dogs[i] = dog1;
    }
    

    for(int i = 0; i < 5; i++)
    {
        if(dogs[i]->getName() != "NULL")
        {
            cout << "Index of dogs which has a name set is: " 
                 << i << endl;
        }
        dogs[i]->getNumLegs();
    }
    // dog1->setName("Novoabcdefhijklmnop");
    // dog1->setNumLegs(0);
    // dog1.name = "Novo";
    // dog1.breed = "Husky";
    // dog1.weight = 50;
    // dog1.numLegs = 4;
    // dog1.gender = 'M';

    // dog1->speak();
    // cout << "The name of dog1 is: " << dog1->getName() << endl;

    // delete dog1;
    // for(int i = 0; i < 5; i++)
    // {
    //     // delete dogs[i];
    //     dogs[i]->~Dog();
    // }
    return 0;
}

void Dog::getNumLegs()
{
    cout << "Number of Legs is: " << _numLegs << endl;
}

Dog::Dog(string name, string breed, float weight, int numLegs, char gender)
{
    _numLegs = numLegs;
    _name = name;
    _weight = weight;
    _breed = breed;
    _gender = gender; 
}

// Dog::Dog(string name, string breed)
// {
//     _numLegs = 4;
//     _name = name;
//     _weight = 50;
//     _breed = breed;
//     _gender = 'U';
//     // cout << "Dog constructor" << endl;
// }

Dog::~Dog()
{
    cout << "Dog destructor" << endl;
    delete this;
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