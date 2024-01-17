#include <iostream>
using namespace std; 

int main()
{
    int max; 
    int fib1 = 1;
    int fib2 = 1;
    int next = fib1 + fib2;

    // get user's input
    do{
        cout << "Enter a positive integer: ";
        cin >> max;
    }
    while(max <= 0);

    cout << "Fibonacci series: " << endl;
    cout << fib1 << " " << fib2 << " ";

    while(next <= max)
    {
        cout << next << " ";
        fib1 = fib2;
        fib2 = next;
        next = fib1 + fib2;
    }

}
