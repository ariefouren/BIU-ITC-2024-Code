#include <iostream>
using namespace std;

int main()
{
    // variables declarations
    double width, height, perimeter, area;

    // user's input
    cout << "Enter the rectangle width  : ";
    cin >> width;

    cout << "Enter the rectangle height :";
    cin >> height;

    // calculations
    perimeter = 2 * (width + height);
    area = width * height;

    // output
    cout << "Perimeter : " << perimeter << endl;
    cout << "Area      : " << area << endl;

    // wait for the user to press any key to finish the program
    system("pause");

    // report to the operating system that the program terminated correctly
    return 0;
}
