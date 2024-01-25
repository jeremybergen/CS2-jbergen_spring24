#include <iostream>
#include <sstream>
#include <fstream>

#include "structs.h"

using namespace std;

int main(int argc, char* argv[]) {
    int counter = 0;
    Person* people[10];
    ifstream fin;
    string tmpLine;

    fin.open("data/input.csv");
    
    while(getline(fin, tmpLine))
    {
        string token;
        int tokCounter = 0;
        stringstream iss;

        iss.str(tmpLine);

        Person* newPerson = new Person();
        while(getline(iss, token, ','))
        {
            if(tokCounter == 0)
            {
                newPerson->fName = token;
            }
            else if(tokCounter == 1)
            {
                newPerson->lName = token;
            }
            else if(tokCounter == 2)
            {
                newPerson->restaurant = token;
            }
            else
            {
                newPerson->rating = stoi(token);
            }

            tokCounter++;
        }

        people[counter] = newPerson;
        counter++;
    }

    getName();
    getRest(people, counter);
    getRating(people, counter);

    // for(int i = 0; i < counter; i++) {
    //     cout << "people[" << i << "]->fName: "
    //          << people[i]->fName << endl;
    // }

    fin.close();
    // delete[] people;
    
    for(int i = 0; i < counter; i++) 
    {
        delete people[i];
    }
    
    return 0;
}