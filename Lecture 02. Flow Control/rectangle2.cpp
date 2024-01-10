#include <iostream>
using namespace std;

int main() {
    double height, width;
    double area, perimeter;

    // get user's input
    cout << "Enter the rectangle height : ";
    cin >> height;
    cout << "Enter the rectangle width : ";
    cin >> width;

    // calculate area and perimeter
    area = height * width;
    perimeter = 2 * (height + width);

    // display the result
    cout << "The rectangle area is " << area << endl;
    cout << "The rectangle perimeter is " << perimeter << endl;

    return 0;
}