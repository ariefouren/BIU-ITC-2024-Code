#include <iostream>
#include <iomanip>      // for setw()

#define WIDTH 16

using namespace std; 

int main()
{
    int x = 0;            
    int y = 1024;
    int* ptr1 = &x;
    int* ptr2 = &y;
    
    cout << "Initial values : " << endl;
    cout << " ptr1 : " << ptr1 << "\t"; // "\t" is a tab character for better formatting
    cout << "*ptr1 : " << *ptr1 << endl;
    cout << " ptr2 : " <<  ptr2 << "\t";
    cout << "*ptr2 : " << *ptr2 << endl << endl;

    ptr2 = ptr1;
    cout << "After ptr2 = ptr1 : " << endl;
    cout << " ptr1 : " <<  ptr1 << "\t";
    cout << "*ptr1 : " << *ptr1 << endl;
    cout << " ptr2 : " <<  ptr2 << "\t";
    cout << "*ptr2 : " << *ptr2 << endl << endl;

    *ptr2 = 2048;
    cout << "After *ptr1 = 2048 : " << endl;
    cout << " ptr1 : " <<  ptr1 << "\t";
    cout << "*ptr1 : " << *ptr1 << endl;
    cout << " ptr2 : " <<  ptr2 << "\t";
    cout << "*ptr2 : " << *ptr2 << endl<< endl;
  
    system("pause");
    return 0;
}
