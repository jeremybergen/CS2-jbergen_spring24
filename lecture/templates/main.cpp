#include <iostream>

using namespace std;

template < typename T1, int arrSize = 10, typename T2 = char >
class MyClass {
    private:
    T1 _id;
    T1 myArray[arrSize];
    T2 someData;

    public:
    void setId(T1);
    T1 getId();
    void getArrSize();
};

class TmpClass {
    private:
    int _id;
    int _gpa;
    string myStrings[100];
    // string _something;

    public:
    int getId()
    {
        return _id;
    }
};

template <class T1, class T2>
T1 addNums(T1, T2);

int main(int argc, char* argv[])
{
    // float num1;
    // int num2;
    // float result;

    // num1 = 42.15;
    // num2 = 15;
    // result = addNums<float, float>(num1, num2);

    // cout << num1 << " + " << num2 << " = " << result << endl;

    // cout << 3000 << " + " << 68.3 << " = " << addNums<int, int>(3000, 68.3) << endl;

    MyClass<TmpClass, 10000, string> *c1 = new MyClass<TmpClass, 10000, string>();
    MyClass<string, 10000> c2;
    MyClass<int, 10000> c3;
    // c1.setId("42.15");
    // cout << c1.getId() << endl;
    c1->getArrSize();
    c2.getArrSize();
    c3.getArrSize();

    delete c1;
    return 0;
}



template <typename T1, int arrSize, typename T2>
void MyClass<T1, arrSize, T2>::getArrSize()
{
    cout << "sizeof myArray: " << sizeof(myArray) << endl;
}

template <typename T1, int arrSize, typename T2>
void MyClass<T1, arrSize, T2>::setId(T1 id)
{
    _id = id;
}

template <typename T1, int arrSize, typename T2>
T1 MyClass<T1, arrSize, T2>::getId()
{
    return _id;
}

// int addNums(int n1, int n2)
template <class T1, class T2>
T1 addNums(T1 n1, T2 n2)
{
    T1 sum;
    sum = n1 + n2;
    return sum;
}