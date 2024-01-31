#include <iostream>
#include <cmath>                   // for pow(), sqrt()
using namespace std; 

#define MAX_NUM_GRADES  1000        // max number of grades

double sum(double grades[], int size);
double average(double grades[], int size);
double standard_deviation(double grades[], int size);

int main()
{
    double grades[MAX_NUM_GRADES];
    int size = 0; // the actual number of grades;

    // get user's input and store in the array grades
    cout << "Enter the grades (-1 to finish) :" << endl;
    double grade;
    do
    {
        cin >> grade;
        if(0<=grade && grade <=100 )
        {
            grades[size] = grade;
            size++;
        }

    } while(0<=grade && grade <=100 && size < MAX_NUM_GRADES);
    
    // calculate statistics
    double avrg = average(grades, size);
    double std_dev = standard_deviation(grades, size);

    // print the results
    cout << "Average grade: " << avrg << endl;
    cout << "Standard deviation : " << std_dev << endl;
    return 0;
}

// implementation of function sum()
double sum(double grades[], int size)
{
    double sum_grades = 0;
    for(int i = 0; i < size; i++)
    {
        sum_grades += grades[i];
    }
    return sum_grades;
}


// implementation of function average()
double average(double grades[], int size)
{
    double avg;
    if(size == 0) return 0;
    avg = sum(grades, size) / size;
    return avg;
}

// implementation of function standard_deviation()
double standard_deviation(double grades[], int size)
{
    if(size == 0) return 0;
    double avg = average(grades, size);
    double sum_sqrs = 0;
    for(int i = 0; i < size; i++)
    {
        sum_sqrs += pow((grades[i] - avg), 2);
    }
    double std_dev = sqrt(sum_sqrs/size);
    return std_dev;

}


