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

        Student(id, course);
        */
        Student(int = 0, string = "");
        void setCourse(string);
        void printStudent();
    };
}