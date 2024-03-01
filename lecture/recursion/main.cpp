#include <iostream>

using namespace std;

// int sum(int);
// int fib(int);
void stars(int);

int main(int argc, char* argv[])
{
    // cout << fib(50) << endl;
    // cout << sum(100) << endl;
    stars(5);
    return 0;
}

// stars(5)
// *****
// ****
// ***
// **
// *
void stars(int n)
{
    if(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "*";
        }
        cout << endl;
        stars(n-1);
    }
}

// int fib(int n)
// {
//     // if(n == 0)
//     // {
//     //     return 0;
//     // }
//     // if(n == 1)
//     // {
//     //     return 1;
//     // }
//     if (n <= 1) return n;
//     return fib(n-2) + fib(n-1);
// }

// int sum(int n1)
// {
//     if(n1 <= 0)
//     {
//         return 0;
//     }
//     return sum(n1 - 1) + n1;
//     //    sum(2-1) + 2
//     // sum(1-1) + 1
//     //    0
// }