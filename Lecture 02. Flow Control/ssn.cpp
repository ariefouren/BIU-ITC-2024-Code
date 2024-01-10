#include <iostream>
using namespace std;

int main(){
    int ssn;

    cout << "Enter your social security number (9 digits): ";
    cin >> ssn;

    cout << "SSN (without check digit) :" << ssn/10 << endl;
    cout << "Check digit: " << ssn%10 << endl;
}