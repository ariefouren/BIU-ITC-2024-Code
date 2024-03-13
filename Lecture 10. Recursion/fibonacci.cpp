// File:    fibonacci.cpp
// This program demonstrates recursive fibonacci sequence
//
#include <iostream>
using namespace std;

// recursive fibonacci sequence
// parameters: n - the number of items
// returns: the nth fibonacci number
int fibonacci(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

// main function
// parameters: none
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The " << n << "th fibonacci number is " << fibonacci(n) << endl;
    return 0;
}
