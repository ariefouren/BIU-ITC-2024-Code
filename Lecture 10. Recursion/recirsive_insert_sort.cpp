// File: recursive_insert_sort.cpp
// This program demonstrates recursive insertion sort of an array

#include <iostream>
#include <iomanip>      // setw()
#include <stdlib.h>     // for srand(), rand(), RAND_MAX
#include <time.h>       // for time()

#define WIDTH 10
using namespace std; 

// recursive insertion sort
// sort an array using insertion sort
// parameters: array - the array to sort
//             lastIndex - the last index of the array
// returns: none
void insertionSort(int array[], int lastIndex)
{
    if(lastIndex <= 0) return; // base case
    insertionSort(array, lastIndex-1); // sort the array[0...lastIndex-1]
    int lastElement = array[lastIndex]; // the value to insert
    int i = lastIndex-1; // the index to start comparing
    while(i >= 0 && array[i] > lastElement) // shift the elements up
    {
        array[i+1] = array[i];
        i--;
    }
    array[i+1] = lastElement; // insert the lastElement to the correct position
}

// print the array
void printArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << setw(WIDTH)  << array[i];
    }
    cout << endl;
}

int main()
{
    int numValues;
    cout << "Enter the number of values in the array : ";
    cin >> numValues;

    // create dynamic array and fill it with random values
    int* array = new int[numValues];

    srand (time(NULL));
    for(int i = 0; i<numValues; i++)
    {
        array[i] = rand();
    }
    cout << "Original array :" << endl;
    printArray(array, numValues);

    // sort the array using insertion sort
    insertionSort(array, numValues-1);

    // print sorted array
    cout << "Sorted array :" << endl;
    printArray(array, numValues);
        
    system("pause");
    return 0;
}  
