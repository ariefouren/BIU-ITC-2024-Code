// File: binary_search.cpp
// This program demonstrates recursive binary search on a sorted array


#include <iostream>
#include <iomanip>      // setw()
#include <stdlib.h>     // for srand(), rand(), RAND_MAX
#include <time.h>       // for time()

#define WIDTH 10
using namespace std; 

// recursive binary search
// in a sorted array, search for a value
// return the index of the value if found, -1 otherwise
// parameters: array - the array to search
//             lowIndex - the lower index of the array
//             hiIndex - the higher index of the array
//             value - the value to search for
// returns: the index of the value if found, -1 otherwise
// preconditions: array is sorted in ascending order
int binarySearch(int array[], int lowIndex, int hiIndex, int value)
{
    if(lowIndex > hiIndex) return -1; // value not found
    int midIndex = (lowIndex + hiIndex)/2; // find the middle index
    if(array[midIndex] == value) return midIndex; // value found
    if(array[midIndex] > value) // search in the lower half of the array
    {
        return binarySearch(array, lowIndex, midIndex-1, value);
    }  
    else // search in the upper half of the array
    {
        return binarySearch(array, midIndex+1, hiIndex, value); 
    } 
}

// merge two sorted arrays into one sorted array
// parameters: array - the array to merge
//             aux - the auxillary array used for merging
//             lowIndex - the lower index of the array
//             midIndex - the middle index of the array
//             hiIndex - the higher index of the array
// returns: none
void merge(int array[], int aux[], int lowIndex, int midIndex, int hiIndex)
{
    // copy array[loIndex ... hiIndex] to aux[lowIndex,..., hiIndex]
    for(int i = lowIndex; i<=hiIndex; i++) 
    {
        aux[i] = array[i];
    } 

    // merge back to array[loIndex ... hiIndex]
    int i = lowIndex;
    int j = midIndex+1;
    for(int k = lowIndex; k<=hiIndex; k++)
    {
        if(i > midIndex)            array[k] = aux[j++];
        else if(j > hiIndex)        array[k] = aux[i++];
        else if(aux[i] < aux[j])    array[k] = aux[i++];
        else                        array[k] = aux[j++];
    }
}

// merge sort
// sort the array using the merge sort algorithm
// parameters: array - the array to sort
//             aux - the auxillary array used for merging
//             lowIndex - the lower index of the array
//             hiIndex - the higher index of the array
// returns: none
void mergeSort(int array[], int aux[], int lowIndex, int hiIndex)
{
    if(lowIndex >= hiIndex) return;             // nothing to sort
    int midIndex = (lowIndex + hiIndex)/2;
    mergeSort(array, aux, lowIndex, midIndex);  // sort left half
    mergeSort(array, aux, midIndex+1, hiIndex); // sort right half
    merge(array, aux, lowIndex, midIndex, hiIndex);
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
    // auxillary array used by merge sort
    int* aux = new int[numValues];

    srand (time(NULL));
    for(int i = 0; i<numValues; i++)
    {
        array[i] = rand();
    }
    // sort the array using merge sort
    mergeSort(array, aux, 0, numValues-1);

    // print sorted array
    cout << "Sorted array :" << endl;
    printArray(array, numValues);

    // search for a value in the array
    int value;
    do
    {
        cout << "Enter the value to search for : ";
        cin >> value;
        if(value >= 0)
        {
            int index = binarySearch(array, 0, numValues-1, value);
            if(index != -1)
            {
                cout << "Value " << value << " found at index " << index << endl;
            }
            else
            {
                cout << "Value " << value << " not found" << endl;
            }
        }
        else
        {
            cout << "Exiting..." << endl;
        }
    } while (value >= 0);
    
    system("pause");
    return 0;
}  
