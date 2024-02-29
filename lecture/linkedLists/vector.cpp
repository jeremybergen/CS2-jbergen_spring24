#include <iostream>
#include <vector>

using namespace std;

template <class T1>
struct Node {
    T1 data;
    Node<T1>* next;
};

int main(int argc, char* argv[])
{
    vector<int> myVector;
    int numbers[5];
    Node<int> head;

    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(42);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(15);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    myVector.push_back(9000);
    cout << "myVector.capacity(): " << myVector.capacity() << endl;
    cout << "&myVector: " << &myVector[0] << endl;
    numbers[0] = 42;

    cout << myVector.size() << endl;


    return 0;
}