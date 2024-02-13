#include <iostream>
#include <iomanip>      // std::setw()

using namespace std; 

void swap(int* xPtr, int* yPtr);

int main()
{
    int x = 0;            
    int y = 1024;

    cout << "Initial values : " << endl;
    cout << "x = " << x << "\t" << "y = " << y << endl << endl;

    swap(&x, &y);
    cout << "After swap(&x, &y)  : " << endl;
    cout << "x = " << x << "\t" << "y = " << y << endl;

    system("pause");
    return 0;
}

void swap(int* xPtr, int* yPtr)
{
    int tmp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = tmp;
}
