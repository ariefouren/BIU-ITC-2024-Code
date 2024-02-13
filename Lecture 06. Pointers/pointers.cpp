#include <iostream>
#include <iomanip>      // for setw()

using namespace std; 

int main()
{
    int num = 1025;         // declare and initialize variable num
    int* numPtr = &num;     // initialize numPtr with the address of int variable num

    cout << "The address of num  (&num)   : " << &num << endl;
    cout << "The value of numPtr          : " << numPtr << endl << endl;

    cout << "The value of num             : " << num << endl;
    cout << "The value of *numPtr         : " << *numPtr << endl;

    system("pause");
    return 0;
}
