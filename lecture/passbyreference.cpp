#include <iostream>
#include <cstdio>

using namespace std;

void getNums(int&, int&);
void addNums(int, int, int&);

int main(int argc, char* argv[])
{
    int someCh;

    someCh = 'J';

    cout << (someCh - 'J') << endl;
    // int number1, number2, result;
    // int* ptr1, *ptr2, *ptr3;

    // ptr1 = &number1;
    // ptr2 = &number2;
    // ptr3 = &result;

    // getNums(*ptr1, *ptr2);
    // addNums(*ptr1, *ptr2, *ptr3);

    // printf("%d + %d = %d\n", number1, number2, result);

    return 0;
}

void getNums(int& n1, int& n2)
{
    cout << "Enter two numbers separated by a space: ";
    cin >> n1 >> n2;
}

void addNums(int num1, int num2, int& sum)
{
    sum = num1 + num2;
}