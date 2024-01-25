#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Person {
    string fName;
    string lName;
    string restaurant;
    int rating;
};

void getName();
void greetPerson(string);
void getRest(Person*[], int);
void getRating(Person*[], int);

void printVals();