#include <iostream>
#include <string>

using namespace std;

// int sum(int);
// int fib(int);
// void stars(int);
// void tower(int, char, char, char);
// bool isPalin(string, int, int);
bool isPalin(string);

int main(int argc, char* argv[])
{
    // cout << fib(50) << endl;
    // cout << sum(100) << endl;
    // stars(10);
    // tower(7, 'A', 'B', 'C');
    // cout << boolalpha << 

    // bool answer = isPalin("racecar");
    // if(answer == true)
    // {
    //     cout << "true" << endl;
    // }
    cout << boolalpha << isPalin("amanaplanacanalpanama") << endl;
    // cout << noboolalpha;
    return 0;
}

bool isPalin(string inputStr)
{
    if(inputStr.length() <= 1)
    {
        return true;
    }
    // if(inputStr[0] != inputStr[inputStr.length()-1])
    if(inputStr.at(0) != inputStr.at(inputStr.length()-1))
    {
        return false;
    }
    return isPalin(inputStr.substr(1, inputStr.length()-2));
}

// void tower(int numDisk, char start, char mid, char end)
// {
//     if(numDisk == 1)
//     {
//         cout << "Move disk 1 from: " << start << " to " << end << endl;
//         return;
//     }
//     tower(numDisk - 1, start, end, mid);
//     cout << "Move disk " << numDisk << " from " << start << " to " << end << endl;
//     tower(numDisk - 1, mid, start, end);
// }

// stars(5)
// *****
// ****
// ***
// **
// *
// void stars(int n)
// {
    
//     if(n > 0)
//     {
//         // stars(n-1);
//         for(int i = 0; i < n; i++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//         stars(n-1);
//     }
// }

// int gcd(int a, int b)
// {
//     if(b == 0)
//         return a;
//     gcd(b, a%b);
// }

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