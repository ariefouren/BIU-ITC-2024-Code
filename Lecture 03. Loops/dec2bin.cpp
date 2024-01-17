#include <iostream>
#include <cmath>        // for pow() 
using namespace std; 

int main()
{
    const int NUM_BITS = 8;
    int bits[NUM_BITS];         // array declaration
    
    int n;

    // user's input
    do{
        cout << "Enter integer in the range 0 ... 255 : " ; 
        cin >> n;
    } while ((n < 0) ||  (255 < n) ); 
    
    // compute the binary representation of n
    // starting from the least significant bit
    for(int i = 0; i < NUM_BITS; i++) 
    {
        bits[i] = n % 2;    // extract the last bit of n
        n = n/2;            // discard the last bit
    }

    // print the binary representation of n 
    // starting from the most significant bit
    cout << "Binary representation : "; 
    for(int i = NUM_BITS - 1; i >= 0; i--)
    {
        cout << bits[i];
    }
    cout << endl;
    
    system("pause");
    return 0;
}
