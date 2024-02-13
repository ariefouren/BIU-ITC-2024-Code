#include <iostream>
#include <iomanip>      // for setw()
#include <stdlib.h>     // for srand(), rand()
#include <time.h>       // for time()

#define ARR_LENGTH 26
#define WIDTH 5
using namespace std; 

void randomPermutation(int arr[], int n);
void printArray(int arr[], int n);
void swap(int& x, int& y);

int main()
{
    int array[ARR_LENGTH];
    randomPermutation(array, ARR_LENGTH);
    printArray(array, ARR_LENGTH);
    cout << endl;

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

    // initialize random seed
    srand(time(NULL));

    // generate random permutation
    for(int nextPos = n-1; 1 <= nextPos; nextPos--)
    {   // choose random index from 0 ... nextPos-1
        // rand() returns a random number between 0 and RAND_MAX
        // rand() % nextPos returns a random number between 0 and nextPos-1
        int randPos = rand() % nextPos; 
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
