#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int>* myVector = new vector<int>();

    cout << myVector->capacity() << endl;
    // cout << &myVector->at(0) << endl;
    myVector->push_back(42);
    cout << myVector->capacity() << endl;
    cout << &myVector->at(0) << endl;

    myVector->push_back(42);
    cout << myVector->capacity() << endl;
    cout << &myVector->at(0) << endl;

    myVector->push_back(42);
    cout << myVector->capacity() << endl;
    cout << &myVector->at(0) << endl;

    myVector->push_back(42);
    cout << myVector->capacity() << endl;
    cout << &myVector->at(0) << endl;

    myVector->push_back(42);
    cout << myVector->capacity() << endl;
    cout << &myVector->at(0) << endl;

    delete myVector;
    return 0;
}