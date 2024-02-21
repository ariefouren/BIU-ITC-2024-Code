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
    int seqLen;
    cin >> seqLen;
    char* DNAseq = new char[seqLen+1];
    cin >> DNAseq;

    int subSeqLen;
    cin >> subSeqLen;
    char* subSeq = new char[subSeqLen+1];
    cin >> subSeq;

    int count = 0;
    for(int seqPos = 0; seqPos <= seqLen - subSeqLen; seqPos++)
    {
        bool fail = false;
        for(int subSeqPos = 0; subSeqPos < subSeqLen; subSeqPos ++)
        {
            if(DNAseq[seqPos + subSeqPos]!= subSeq[subSeqPos]) 
            {
                fail = true;
                break;
            }
        }
        if(!fail)
        {
            cout << "Subsequence is found at position " << seqPos<< endl;
            count++;
        }
    }
    cout << "Subsequence is found " << count << " times";
    
}