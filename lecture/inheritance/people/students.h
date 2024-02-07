#pragma once
#include "person.h"

namespace person {
    class Student : public Person {
        private:
        int _id;
        string _course;

        protected:

        public:
        /*
        Student constructor

        Student(id, course, name, age, height);
        */
        Student(int = 0, string = "", string = "NULL", int = 0, int = 0);
        void setCourse(string);
        void printStudent();
    };
}