// File: DNAsubseq.cpp
// C++ program to find all occurrences of a subsequence
// in a DNA sequence using a linked list
// Lecture 08: Linked list 29-Mar-2024
//
#include <iostream>

using namespace std;

struct Node
{
    char value;
    Node* next;
};

struct LinkedList
{
    Node* head;
    Node* tail;
};

// creates a new node with the given value using dynamic memory allocation
// returns a pointer to the new node
Node* createNewNode(char ch)
{
    Node* newNode = new Node;
    newNode->value = ch;
    newNode->next = NULL;
    return newNode;
}

// creates a new empty list using dynamic memory allocation
// returns a pointer to the new list
LinkedList* createNewList()
{
    LinkedList* newList = new LinkedList;
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

// returns true if the list is empty, false otherwise
bool isEmpty(LinkedList* list)
{
    return (list->head == NULL);
}

// prints the values of the list
void printList(LinkedList* list)
{
    Node* currentNode = list->head;
    while(currentNode != NULL)
    {
        cout<< currentNode->value;
        currentNode = currentNode->next;
    }
}

// inserts a new node with the given value at the tail of the list
void insertAtTail(LinkedList* list, char value)
{
    Node* newNode = createNewNode(value);

    if(isEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// removes the node from the head of the list   
// returns the value of the removed node
char removeFromHead(LinkedList* list)
{
    if(isEmpty(list))
    {
        return '\0';
    }
    else 
    {
        Node* nodeToDelete = list->head;
        list->head = list->head->next;
        if(list->head == NULL)
        {
            list->tail = NULL;
        }
        char value = nodeToDelete->value;
        delete nodeToDelete;
        return value;
    }
}

// deletes the list and frees the dynamically allocated memory
void deleteList(LinkedList* list)
{
    while(!isEmpty(list))
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

// returns true if the subsequence is a prefix of the DNA sequence
// starting from the given position
bool isPrefix(Node* DNAsequenceNode, Node* subsequenceNode)
{
    while(subsequenceNode != NULL && 
        DNAsequenceNode != NULL &&
        subsequenceNode->value == DNAsequenceNode->value)
    {
        subsequenceNode = subsequenceNode->next;
        DNAsequenceNode = DNAsequenceNode->next;
    }
    // if we get to the end of the subsequence, it is a prefix
    return subsequenceNode == NULL;
}

// find and print all occurrences of the subsequence in the DNA sequence
void findSubsequence(LinkedList* DNAsequence, LinkedList* subsequence)
{
    int occurrenceCount = 0;
    int currDNAposition = 0;
    Node* currentDNAnode = DNAsequence->head;
    while(currentDNAnode != NULL)
    {
        if(isPrefix(currentDNAnode, subsequence->head))
        {
            occurrenceCount++;
            cout << "Occurrence at position " << currDNAposition << endl;
        }
        currentDNAnode = currentDNAnode->next;
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

