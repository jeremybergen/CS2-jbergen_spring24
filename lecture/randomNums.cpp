#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
    char someCh;
    int someInt;

    someCh = 'J';
    someInt = 'J' - 'K';

    cout << "someCh: " << someCh << endl;
    cout << "someInt: " << someInt << endl;
    // srand(42);
    // for(int i = 0; i < 10; i++)
    // {
    //     cout << rand()%10 << endl;
    // }
    return 0;
}