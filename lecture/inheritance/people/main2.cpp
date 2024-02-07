#include <iostream>
#include "students.h"

using namespace std;

int main(int argc, char* argv[])
{
    person::Student s1(42, "CSCI112", "Jeremy", 21, 74);

    s1.printStudent();

    return 0;
}