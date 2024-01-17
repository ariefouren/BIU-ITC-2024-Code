#include <iostream>
using namespace std; 

int main()
{
    // get users' input
    cout << "Enter the grades, -1 to finish"; 
    double grade;
    double sum = 0;
    int count = 0;

    do{
        cin >> grade;
        if(grade >=0)
        {
            sum += grade;
            count++;
        }
    }
    while(grade >= 0);

    // print the average
    cout << "The average is " << sum/count << endl;
    cout << "The average rounded down is " << (int) (sum/count) << endl;

}