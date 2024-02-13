#include <iostream>
#include <iomanip>      // for setw()
#include <stdlib.h>     // for srand(), rand()
#include <time.h>       // for time()
#include <string.h>     // for len()

#define KEY_LENGTH 26
#define MAX_TEXT_LEN 500
#define WIDTH 5
using namespace std; 

void randomPermutation(int arr[], int n);

void generateKeys(int encryptionKey[], int decryptionKey[], int keyLength);
void encrypt(char plaintext[], char ciphertext[], int key[], int keyLength);
void swap(int& x, int& y);
void printArray(int arr[], int n);

int main()
{
    int* encryptionKey = new int[KEY_LENGTH];
    int* decryptionKey = new int [KEY_LENGTH];

    char* plainText = new char[MAX_TEXT_LEN];
    char* encryptedText = new char[MAX_TEXT_LEN];
    char* decryptedText = new char[MAX_TEXT_LEN];

    cout << "Enter text:     ";
    cin >> plainText; 
    
    generateKeys(encryptionKey, decryptionKey, KEY_LENGTH);

    encrypt(plainText, encryptedText, encryptionKey, KEY_LENGTH);
    cout << "Encrypted text:   " << encryptedText << endl;
    
    // note that the decryption is an encryption of the ciphertext with the decryption key
    encrypt(encryptedText, decryptedText, decryptionKey, KEY_LENGTH);
    cout << "Decrypted text:  " << decryptedText << endl;

    
    delete[]  encryptionKey;
    delete[]  decryptionKey;
    delete[]  plainText;
    delete[]  encryptedText;
    delete[]  decryptedText;  
    
    system("pause");
    return 0;
}

void generateKeys(int encryptionKey[], int decryptionKey[], int keyLength)
{
    // generate encryption key
    randomPermutation(encryptionKey, keyLength);
    // generate decryption key
    for(int i=0; i< keyLength; i++)
    {
        decryptionKey[encryptionKey[i]] = i; 
    }

}

void encrypt(char plaintext[], char ciphertext[], int key[], int keyLength)
{
    int textLen = strlen(plaintext);
    for(int i = 0; i<= textLen; i++)
    {
        char plainChar = plaintext[i]; 
        int plainCharIndex = plainChar - 'a';
        char encryptedCharIndex = key[plainCharIndex]; 
        ciphertext[i] = encryptedCharIndex + 'a';
    }
    ciphertext[textLen] = 0;
}

void randomPermutation(int arr[], int n)
{
    // initialize the array by 0,1,...n-1
    for(int i = 0; i< n; i++)
    {
        arr[i] = i;
    }

    // initialize random seed
    srand (time(NULL));

    // generate random permutation
    for(int nextPos = n-1; 1 <= nextPos; nextPos--)
    {
        int randPos = rand() % nextPos; // choose random index from 0 ... nextPos-1
        swap(arr[randPos], arr[nextPos]); 
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i< n; i++)
    {
        cout << setw(WIDTH) << arr[i];
    }
}

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
