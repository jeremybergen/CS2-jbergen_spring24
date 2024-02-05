#include "bclass.h"


int main(int argc, char* argv[])
{
    Bclass bClassInstance;

    for(int i = 0; i < 10; i++)
    {
        Aclass* newAclass = new Aclass();
        bClassInstance.setThings(newAclass, i);
    }
    // bClassInstance.~Bclass();
    return 0;
}

