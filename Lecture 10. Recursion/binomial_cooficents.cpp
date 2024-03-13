// This program demonstrates recursive computation of binomial coefficients

#include <iostream>
#include <iomanip>      // setw()
using namespace std;

// recursive computation of binomial coefficients
// parameters: n - the number of items
//             k - the number of items to choose
// returns: the binomial coefficient of n and k
int binomial(int n, int k)
{
    if(k == 0 || k == n) return 1;
    return binomial(n-1, k-1) + binomial(n-1, k);
}

// main function
// parameters: none
int main()
{
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "The binomial coefficient of " << n << " and " << k << " is " << binomial(n, k) << endl;
    return 0;
}
