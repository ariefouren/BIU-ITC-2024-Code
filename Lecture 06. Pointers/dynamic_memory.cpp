#include <iostream>
#include <iomanip>      // for setw()
#include <stdlib.h>     // for srand(), rand()
#include <time.h>       // for time()

#define WIDTH 4
using namespace std; 

void randomPermutation(int arr[], int n);
void printArray(int arr[], int n);
void swap(int& x, int& y);

int main()
{
    int size;
    cout << "Enter the number of elements :";
    cin >> size;

    // allocate a dynamic array of integers
    int* arrayPtr = new int[size]; 
    
    // generate random permutation
    randomPermutation(arrayPtr, size);
    cout << "Random permutation :" << endl;
    printArray(arrayPtr, size);
    cout << endl;

    delete [] arrayPtr;     // destroy the dynamic array 
                            // and return the memory to free-store

    system("pause");
    return 0;
}

void randomPermutation(int arr[], int n)
{
    // initialize the array by 0,1,...n-1
    for(int i = 0; i< n; i++)
    {
        arr[i] = i;
    }

    // initialize the random generator by a random seed
    srand(time(NULL));

    // generate random permutation
    for(int nextPos = n-1; 1 <= nextPos; nextPos--)
    {
        // choose random index from 0 ... nextPos
        int randPos = rand() % (nextPos + 1); 
        swap(arr[randPos], arr[nextPos]); 
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i< n; i++)
    {
        cout << setw(WIDTH) << arr[i];
    }
}

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
} 
