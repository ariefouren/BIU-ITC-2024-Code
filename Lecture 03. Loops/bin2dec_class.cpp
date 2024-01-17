#include <iostream>
#include <cmath>        // for pow() 
using namespace std; 

int main()
{
    const int NUM_BITS = 8;
    // define array of bits
    int bits[NUM_BITS];
    
    // get user's input
    cout << "Enter " << NUM_BITS << " bits (the most significant bit first) : "; 
    // the most significant digit is stored 
    // at the the last index of the array, (NUM_BITS - 1)
    // the weight of i-th digit is 2^i
    for(int i = NUM_BITS - 1; i>=0; i--)    
    {
        cin >> bits[i];
    }

    // compute the value of the binary number
    int n = 0;
    for(int i = 0; i < NUM_BITS; i++)
    {
        n += bits[i] * pow(2, i);
    }

    cout << "Integer value : " << n << endl;
    system("pause");
    return 0;


}    
