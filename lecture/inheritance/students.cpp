#include "students.h"

person::Student::Student(int id, string course)
{
    _id = id;
    _course = course;
    cout << "Creating student." << endl;
}

void person::Student::setCourse(string course)
{
    _course = course;
}

void person::Student::printStudent()
{
    cout << this->getName() << " is taking course: "
         << _course << endl;
}