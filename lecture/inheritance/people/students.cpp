#include "students.h"

person::Student::Student(int id, string course, string name, int age, int height) : Person(name, age, height)
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
    cout << this->getName() << " is " << this->getHeight() << endl;
}