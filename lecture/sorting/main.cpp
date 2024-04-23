#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

void buildArray(int[], int);
void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

void quickSort(int[], int, int);
int partition(int[], int, int);

void printArray(int[], int);
void copyArray(int[], int[], int);

int main(int argc, char *argv[])
{
    // int arrSize = 3584;
    int arrSize = 3584;
    int array[arrSize];
    int bubbleArray[arrSize];
    int selectionArray[arrSize];
    int insertionArray[arrSize];
    int mergeArray[arrSize];
    int quickArray[arrSize];
    vector<int> stlArray;
    stlArray.resize(arrSize);

    cout << "Building array..." << endl;
    buildArray(array, arrSize);
    copyArray(array, bubbleArray, arrSize);

    auto start = chrono::system_clock::now();
    cout << "Bubble Sorting array..." << endl;
    bubbleSort(bubbleArray, arrSize);
    auto end = chrono::system_clock::now();
    auto elapsed = end - start;
    cout << "Bubble Sort: " << elapsed.count() << '\n';

    start = chrono::system_clock::now();
    cout << "Selection Sorting array..." << endl;
    copyArray(array, selectionArray, arrSize);
    selectionSort(selectionArray, arrSize);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Selection Sort: " << elapsed.count() << '\n';

    start = chrono::system_clock::now();
    cout << "Insertion Sorting array..." << endl;
    copyArray(array, insertionArray, arrSize);
    insertionSort(insertionArray, arrSize);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Insertion Sort: " << elapsed.count() << '\n';

    int l, r;
    l = 0;
    r = arrSize - 1;

    start = chrono::system_clock::now();
    cout << "Merge Sorting array..." << endl;
    copyArray(array, mergeArray, arrSize);
    mergeSort(mergeArray, l, r);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Merge Sort: " << elapsed.count() << '\n';

    start = chrono::system_clock::now();
    cout << "Quick Sorting array..." << endl;
    copyArray(array, quickArray, arrSize);
    quickSort(array, 0, arrSize - 1);
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "Quick Sort: " << elapsed.count() << '\n';

    start = chrono::system_clock::now();
    cout << "STL Sorting array..." << endl;
    // copyArray(array, stlArray, arrSize);
    for(int num: array)
    {
        stlArray.push_back(num);
    }
    sort(stlArray.begin(), stlArray.end());
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << "STL Sort: " << elapsed.count() << '\n';
    // printArray(bubbleArray, arrSize);
    // printArray(mergeArray, arrSize);
    // printArray(selectionArray, arrSize);
    // printArray(insertionArray, arrSize);
    for(int i = 0; i < arrSize; i++)
    {
        if(bubbleArray[i] != mergeArray[i] && bubbleArray[i] != selectionArray[i] && bubbleArray[i] != insertionArray[i] && bubbleArray[i] != quickArray[i])
        {
            cout << "Arrays differ at index: " << i << endl;
            break;
        }
    }
    // cout << "DEBUG: bubbleArray[0]: " << bubbleArray[0] << endl;
    // cout << "DEBUG: bubbleArray[1]: " << bubbleArray[1] << endl;
    // cout << "DEBUG: mergeArray[0]: " << mergeArray[0] << endl;
    // cout << "DEBUG: mergeArray[1]: " << mergeArray[1] << endl;

    // int counter = 0;
    // for(int num: bubbleArray)
    // {
    //     if(num == 100669) counter++;
    // }
    // cout << "counter: " << counter << endl;

    return 0;
}

void copyArray(int origArray[], int newArray[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        newArray[i] = origArray[i];
    }
}

void printArray(int array[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void buildArray(int array[], int arrSize)
{
    srand(time(0));
    for (int i = 0; i < arrSize; i++)
    {
        array[i] = rand();
    }
}

void merge(int array[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = array[p + i];
    }
    for (int j = 0; j < n1; j++)
    {
        M[j] = array[q + 1 + j];
    }

    // for (int i = 0; i < n1; i++)
    // {
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n2; i++)
    // {
    //     cout << M[i] << " ";
    // }
    // cout << endl;
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = M[j];
        j++;
        k++;
    }
    // cout << "Merged array: " << endl;
    // for (int arrIdx = 0; arrIdx < k; arrIdx++)
    // {
    //     cout << array[arrIdx] << " ";
    // }
    // cout << endl;
}

void mergeSort(int array[], int l, int r)
{

    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        // cout << "Calling merge: " << endl;
        merge(array, l, m, r);
        // cout << "After merge: " << endl;
        // cout << "DEBUG: l: " << l << endl;
        // for (int arrIdx = 0; arrIdx < r; arrIdx++)
        // {
        //     cout << array[arrIdx] << " ";
        // }
        // cout << endl;
    }
}

void insertionSort(int array[], int arrSize)
{
    for (int i = 1; i < arrSize; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void selectionSort(int array[], int arrSize)
{
    // bool swapped = false;
    int minimum;
    for (int i = 0; i < arrSize - 1; i++)
    {
        minimum = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (array[j] < array[minimum])
            {
                minimum = j;
            }
        }
        if (minimum != i)
        {
            swap(array[minimum], array[i]);
        }
    }
}

void bubbleSort(int array[], int arrSize)
{
    bool swapped = false;
    for (int i = 0; i < arrSize; i++)
    {
        swapped = false;
        for (int j = 0; j < arrSize - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void quickSort(int array[], int start, int end)
{
    if(start < end)
    {
        int partitionIndex = partition(array, start, end);

        quickSort(array, start, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, end);
    }
}

int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if(array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[end]);
    return i + 1;
}