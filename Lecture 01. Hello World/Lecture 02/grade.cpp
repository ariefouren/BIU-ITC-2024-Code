#include <iostream>

using namespace std;

int main()
{
    const int GRADE_TO_PASS = 60;
    int grade;
    cout << "Please enter the grade : ";
    cin >> grade;

    if(grade >= GRADE_TO_PASS)
    {
        cout << "Passed :)" << endl;
    }
    else
    {
        cout << "Failed :(" << endl;
    }
    system("pause");
    return 0;
}