#pragma once
#include "aclass.h"
#include <iostream>

namespace bclass {
    class Bclass {
        private:
        int someNumber;
        aclass::Aclass* things[10];

        public:
        Bclass();
        ~Bclass();
        void setThings(aclass::Aclass*, int);
    };
}