#include <iostream>

using namespace std;

int main()
{
    int ssn;
    cout << "Please enter the social security number (9 digits) : ";
    cin >> ssn;

    cout << "Social security number (without check digit) : " << ssn/10 << endl;
    cout << "Check digit : " <<ssn % 10 << endl;
    system("pause");
    return 0;
}
