#include <iostream>
#include <iomanip>      // std::setw()

using namespace std; 

void swapByValue(double x, double y);
void swapByReference(double &x, double &y);

int main()
{
    double x, y;

    cout << "Enter x = ";
    cin >> x;
    cout << "Enter y = ";
    cin >> y;
   
    swapByValue(x, y);
    cout << "After swap by value :" <<endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << endl;

    swapByReference(x, y);
    cout << "After swap by reference :" <<endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << endl;
     
    system("pause");
    return 0;
}

void swapByValue(double x, double y)
{
    double tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void swapByReference(double &x, double &y)
{
    double tmp;
    tmp = x;
    x = y;
    y = tmp;
}