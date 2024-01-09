#include <iostream>

using namespace std;

int main()
{
    int numPupils, busCapacity;
    cout << "Please enter the number of pupils: ";
    cin >> numPupils;

    cout << "Please enter the bus capacity: ";
    cin >> busCapacity;

    cout << "Number of full buses: " << numPupils / busCapacity << endl;
    cout << "Number of pupils in the last bus: " << numPupils % busCapacity << endl;
    system("pause");
    return 0;
}
