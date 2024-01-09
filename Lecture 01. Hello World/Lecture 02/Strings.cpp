#include <iostream>
#include <string>       // using the string class
using namespace std; 

int main()
{
    string firstName, lastName, fullName;
    
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name : ";
    cin >> lastName;

    //  note: here "+" means string concatenation
    fullName = firstName + " " + lastName;
    cout << "Hello, " << fullName << " !" <<endl;
    
    system("pause");
    return 0;
}
