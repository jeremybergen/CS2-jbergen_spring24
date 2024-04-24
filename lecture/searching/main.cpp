#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

void buildArray(vector<long>&, int);
bool linearSearch(vector<long>&, long);
bool binarySearch(vector<long>&, long, int, int);

int main(int argc, char* argv[])
{
    vector<long> array;
    int arrSize = 1000000;
    bool dataFound = false;

    cout << "Building array..." << endl;
    buildArray(array, arrSize);

    auto start = chrono::system_clock::now();
    cout << "Searching array..." << endl;
    // bubbleSort(bubbleArray, arrSize);
    if (linearSearch(array, 31415926535))
    {
        cout << "Element found" << endl;
    }
    auto end = chrono::system_clock::now();
    auto elapsed = end - start;
    cout << "Linear Search: " << elapsed.count() << '\n';

    start = chrono::system_clock::now();
    cout << "Searching array..." << endl;
    // bubbleSort(bubbleArray, arrSize);
    if (binarySearch(array, 31415926535, 0, array.size()-1))
    {
        cout << "Element found" << endl;
    }
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "binary Search: " << elapsed.count() << '\n';


    return 0;
}

bool binarySearch(vector<long>& array, long data, int start, int end)
{
    int mid = start + (end - start) / 2;
    if(start >= end && array.at(mid) != data) return false;
    if(array.at(mid) == data) {cout << array.at(mid) << endl; return true;}
    if(array.at(mid) < data) return binarySearch(array, data, mid+1, end);
    if(array.at(mid) > data) return binarySearch(array, data, start, mid - 1);
    return false;
}

bool linearSearch(vector<long>& array, long data)
{
    for(auto it = array.begin(); it != array.end(); it++)
    {
        if(*it == data)
        {
            return true;
        }
        if(*it > data)
        {
            return false;
        }
    }
    return false;
}

void buildArray(vector<long> &array, int arrSize)
{
    srand(time(0));
    for (int i = 0; i < arrSize; i++)
    {
        array.push_back(rand());
    }
    array.push_back(31415926535);
    sort(array.begin(), array.end());
}

