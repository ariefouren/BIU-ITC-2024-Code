#include <iostream>
#include <iomanip>      // for setw(), setpricision()
#include <stdlib.h>     // for srand(), rand(), RAND_MAX
#include <time.h>       // for time()


#define WIDTH 10
using namespace std; 

// define a node of the list
struct Node
{
    char value;   
    Node* next;
};

// creates a new node with the given value using dynamic memory allocation
// returns a pointer to the new node
Node* createNewNode(char ch)
{
    Node* newNode = new Node;
    newNode->value = ch;
    newNode->next = NULL;
    return newNode;
};

struct LinkedList
{
    Node* head;
    Node* tail;
};

// creates a new empty list using dynamic memory allocation
// returns a pointer to the new list
LinkedList* createNewList()
{
    LinkedList* list = new LinkedList;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// returns true if the list is empty, false otherwise
bool isEmpty(LinkedList* list)
{
    return list->head == NULL;
}

// prints the values of the list
void printList(LinkedList* list)
{
    Node* currentNode = list->head;     // start from the head of the list
    while(currentNode != NULL)    // while the current node is not NULL
    {
        cout << currentNode->value;
        currentNode = currentNode->next;
    }
    cout << endl;
}

// inserts a new node with the given value at the tail of the list
void insertAtTail(LinkedList* list, char value)
{
    // create a new node with the given value
    Node* newNode = createNewNode(value);
    if(isEmpty(list))  // the list is empty
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else    // the list is not empty
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// removes the node from the head of the list   
// returns the value of the removed node
char removeFromHead(LinkedList* list)
{
    if(isEmpty(list))  // the list is empty
    {
        cout << "The list is empty." << endl;
        return '\0';
    }
    else    // the list is not empty
    {
        Node* removedNode = list->head;
        char removedValue = removedNode->value;
        list->head = list->head->next;
        delete removedNode;
        return removedValue;
    }
}

// deletes the list and frees the dynamically allocated memory
void deleteList(LinkedList* list)
{
    while(!isEmpty(list)) // the list is not empty
    {
        removeFromHead(list);
    }
    delete list;
}

// returns true if the given character is a correct nucleotide (A, C, G, or T)
// and false otherwise
bool isCorrectNucleotide(char ch)
{
    return ch == 'A' || ch == 'C' || ch == 'G' || ch == 'T';
}

// gets the DNA sequence from the user and stores it in the list DNAsequence
void getDNAsequence(LinkedList* DNAsequence)
{
    char ch;
    do{
        cin >> noskipws >> ch; // noskipws: do not skip white spaces
        if(isCorrectNucleotide(ch))
        {
            insertAtTail(DNAsequence, ch);
        }
    }while(isCorrectNucleotide(ch)); // get the DNA sequence
}

// find and print all occurrences of the subsequence in the DNA sequence
void findSubsequence(LinkedList* DNAsequence, LinkedList* subsequence)
{
    int occurrenceCount = 0;
    int currDNAposition = 0;
    Node* currentDNA = DNAsequence->head;
    while(currentDNA != NULL)
    {
        Node* currentSub = subsequence->head;
        Node* currentDNA2 = currentDNA;
        while(currentSub != NULL && 
            currentDNA2 != NULL && 
            currentSub->value == currentDNA2->value)
        {
            currentSub = currentSub->next;
            currentDNA2 = currentDNA2->next;
        }
        if(currentSub == NULL) // subsequence found
        {
            occurrenceCount++;
            cout << "Subsequence found at position " << currDNAposition << endl;
        }
        currentDNA = currentDNA->next;
        currDNAposition++;
    }
    cout << "Total occurrences: " << occurrenceCount << endl;
}

// main function
// get the DNA sequence and the subsequence from the user
// and find all occurrences of the subsequence in the DNA sequence
int main()
{
    // create a new empty list to store the DNA sequence
    LinkedList* DNAsequence = createNewList();
    // create a new empty list to store the subsequence
    LinkedList* subsequence = createNewList();

    // print the user instructions
    cout << "Enter the DNA sequence (ENTER to finish)" << endl;  
    getDNAsequence(DNAsequence);

    cout << "Enter the subsequence of nucleotides (ENTER to finish)" << endl;
    getDNAsequence(subsequence);
    
    // print the DNA sequence and the subsequence
    cout << "DNA sequence: ";
    printList(DNAsequence);
    cout << "Subsequence: ";
    printList(subsequence);

    // find all occurrences of the subsequence in the DNA sequence
    findSubsequence(DNAsequence, subsequence);

    // delete the lists
    deleteList(DNAsequence);
    deleteList(subsequence);

    system("pause");
    return 0;
}    