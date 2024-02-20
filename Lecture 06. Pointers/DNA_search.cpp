#include <iostream>
#include <iomanip>      // for setw()

#define WIDTH 16

using namespace std; 

int main()
{
    // print the user instructions
    cout << "Enter: "<< endl;
    cout<< "the length of the DNA sequence" << endl;
    cout<< "the DNA sequence" << endl;
    cout<< "the length of the subsequence" << endl;
    cout<< "the subsequence" << endl;
    // get the input
    int sequenceLength;
    cin >> sequenceLength;

    // dynamically allocate memory for the DNA sequence
    char* DNAsequence = new char[sequenceLength];
    // get the DNA sequence
    cin >> DNAsequence;

    int subsequenceLength;
    // get the length of the subsequence
    cin >> subsequenceLength;   
    // dynamically allocate memory for the subsequence
    char* subsequence = new char[subsequenceLength];
    cin >> subsequence;

    // search for the subsequence in the DNA sequence
    // and print the position of each occurrence
    int occurrenceCount = 0;
    for (int startPos = 0; startPos < sequenceLength - subsequenceLength + 1; startPos++)
    {
        int subsequencePos = 0;
        while(subsequencePos < subsequenceLength && 
            DNAsequence[startPos+subsequencePos] == subsequence[subsequencePos])
        {
            subsequencePos++;
        }
        if (subsequencePos == subsequenceLength) // subsequence found
        {
            occurrenceCount++;
            cout << "Subsequence " << subsequence <<" found at position " << startPos << endl;
        }
    }
    cout << "Total occurrences: " << occurrenceCount << endl;

}
