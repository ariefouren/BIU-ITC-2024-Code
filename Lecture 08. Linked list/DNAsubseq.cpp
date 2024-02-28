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
        
    }
}

// deletes the list and frees the dynamically allocated memory
void deleteList(LinkedList* list);

// returns true if the given character is a correct nucleotide (A, C, G, or T)
// and false otherwise
bool isCorrectNucleotide(char ch);

// gets the DNA sequence from the user and stores it in the list DNAsequence
void getDNAsequence(LinkedList* DNAsequence);

// find and print all occurrences of the subsequence in the DNA sequence
void findSubsequence(LinkedList* DNAsequence, LinkedList* subsequence);

// main function
// get the DNA sequence and the subsequence from the user
// and find all occurrences of the subsequence in the DNA sequence
int main()


