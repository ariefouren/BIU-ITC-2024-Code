#include <iostream>
#include <cmath>                   // for pow(), sqrt()
using namespace std; 

#define MAX_NUM_GRADES  100        // max number of grades

double sum(double values[], int size);
double average(double values[], int size);
double stdDev(double values[], int size);

int main()
{
    double grades[MAX_NUM_GRADES];
    int numGrades = 0;          // actual number of grades

    // get the list of grades and store them in the array
    double nextGrade;
    cout << "Enter the list of grades ( -1 to finish) :" << endl;
    do
    {
        cin >> nextGrade;
        if(nextGrade >= 0) // a valid grade
        {
            grades[numGrades] = nextGrade;  // store the valid grade in the array
            numGrades ++;                   // update the number of grades stored
        }
    } while ((nextGrade >=0) && (numGrades < MAX_NUM_GRADES));

    // print statistics
    cout << "Average            : " << average(grades, numGrades) << endl;
    cout << "Standard deviation : " << stdDev(grades, numGrades) << endl;

    system("pause");
    return 0;
}

// This function computes the sum of the values in the array.
double sum(double values[], int size)
{
    double sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += values[i];
    }
    return sum;
}

// This function computes the average of the values in the array.
double average(double values[], int size)
{
    double avg = sum(values, size)/size;
    return avg;
}

// This function computes the standard deviation of the values in the array.
double stdDev(double values[], int size)
{
    double avg = average(values, size);
    double sumSquares = 0;   

    for(int i = 0; i < size; i++)
    {
        sumSquares += pow((values[i] - avg), 2);
    }
    double stdDev = sqrt(sumSquares / size);
    return stdDev;
}

