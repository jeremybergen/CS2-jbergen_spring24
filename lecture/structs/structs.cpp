#include <iomanip>
#include "structs.h"


void getName()
{
    string name;
    cout << "What is your name? ";
    cin >> name;

    greetPerson(name);
}

void greetPerson(string name)
{
    cout << "Welcome " << name << " to our people/restaurant list" << endl;
}

void getRest(Person* people[], int arrSize)
{
    cout << "List of Restaurants: " << endl;
    for(int i = 0; i < arrSize; i++) {
        cout << people[i]->restaurant << endl;
    }
}

void getRating(Person* people[], int arrSize)
{
    cout << "Ratings for Restaurants:" << endl;
    cout << left << setw(10) << "Name" << setw(3) << "Rating" << endl;
    cout << setfill('-');
    cout << setw(16) << "" << endl;
    cout << setfill(' ');
    for(int i = 0; i < arrSize; i++) {
        // Person
        // Person.restaurant
        cout << setw(10) << people[i]->restaurant 
             << " " << setw(3) << people[i]->rating << endl;
    }
}

void printVals()
{

}