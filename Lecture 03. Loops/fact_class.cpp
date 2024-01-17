#include <iostream>
using namespace std; 

int fact(int n);

int main()
{
    int n;
    // get user's input
    cout << "Enter a positive integer: ";
    cin >> n;

    // call the function fact
    cout << "Factorial of " << n << " is " << fact(n);

    return 0;
}

int fact(int n)
{
    int result = 1;
    for(int i = 1; i<=n; i++)
    {
        result = result * i;
    }
    return result;
}