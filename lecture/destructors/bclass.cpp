#include "bclass.h"

void bclass::Bclass::setThings(aclass::Aclass* newAclass, int arrIdx)
{
    things[arrIdx] = newAclass;
}

bclass::Bclass::Bclass()
{
    someNumber = 42;
}
bclass::Bclass::~Bclass()
{
    std::cout << "Freeing up Aclass memory" << std::endl;
    for(int i = 0; i < 10; i++)
    {
        delete things[i];
    }
}