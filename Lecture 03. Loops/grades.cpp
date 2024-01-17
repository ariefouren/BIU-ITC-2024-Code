#include <iostream>
using namespace std; 

int main()
{
    double grade;
    int numGrades = 0;        
    double sum = 0;
    double average;

    // get user's input
    cout << "Enter the list of grades ( -1 to finish) :" << endl;
    do
    {
        cin >> grade;
        if(grade >= 0) // the grade is correct
        {
            numGrades ++;
            sum += grade;
        }
    } while (grade >=0);
    
    // compute the average
    average = sum / numGrades;

    // output
    cout << "Average grade:               " << average << endl;
    cout << "Average grade rounded down:  " << (int) average << endl;

    system("pause");
    return 0;
}

