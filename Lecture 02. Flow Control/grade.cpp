#include <iostream>
using namespace std;
const int GRADE_TO_PASS = 60;

int main()
{
    int grade;
    cout << "Enter your grade: ";
    cin >> grade;

    if(grade >= GRADE_TO_PASS)
    {
        cout << "You passed!  :)" << endl;
    }
    else
    {
        cout << "You failed!  " << endl;
    }
    return 0;
}