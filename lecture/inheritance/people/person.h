#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace person {
    class Person {
        private:
        string _name;
        int _age;
        int _height;

        protected:
        string getName();
        string getHeight();

        public:
        Person(string = "", int = 0, int = 0);
    };
}