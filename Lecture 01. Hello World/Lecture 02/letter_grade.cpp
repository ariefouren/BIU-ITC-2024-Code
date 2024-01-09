#include <iostream>

using namespace std;

int main()
{
    const int A_PLUS =97;
    const int A = 93;
    const int A_MINUS = 90;
    const int B_PLUS = 87;
    const int B = 83;
    const int B_MINUS = 80; 
    const int C_PLUS = 77;
    const int C = 73;
    const int C_MINUS = 70; 
    const int D_PLUS = 67;
    const int D = 63;
    const int D_MINUS = 60;
    const int F = 0;

    int grade;
    string letter_grade; 

    cout << "Please enter the grade : ";
    cin >> grade;

    if(grade >= A_PLUS)
    {
        letter_grade = "A+";
    }
    else if(grade >= A)
    {
        letter_grade = "A";
    } 
    else if(grade >= A_MINUS)
    {
        letter_grade = "A-";
    }
    else if(grade >= B_PLUS)
    {
        letter_grade = "B+";
    }
    else if(grade >= B)
    {
        letter_grade = "B";
    }
    else if(grade >= B_MINUS)
    {
        letter_grade = "B-";
    }
    else if(grade >= D_PLUS)
    {
        letter_grade = "D+";
    }
    else if(grade >= D)
    {
        letter_grade = "D";
    }
    else if(grade >= D_MINUS)
    {
        letter_grade = "D_MINUS";
    }
    else 
    {
        letter_grade = "F";
    }

    cout << "Letter grade: " << letter_grade << endl;
    system("pause");
    return 0;
}
