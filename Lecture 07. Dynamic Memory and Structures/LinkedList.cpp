#include <iostream>
#include <iomanip>      // for setw(), setpricision()
#include <stdlib.h>     // for srand(), rand(), RAND_MAX
#include <time.h>       // for time()


#define WIDTH 10
using namespace std; 

// define a node of the list
struct Node
{
    int value;   
    Node* next;
};

// creates a new node with the given value using dynamic memory allocation
// returns a pointer to the new node
Node* createNewNode(int val)
{
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
};

bool isEmpty(Node* head)
{
    return head == NULL;
}

void printList(Node* head)
{
    Node* currentNode = head;     // start from the head of the list
    while(currentNode != NULL)    // while the current node is not NULL
    {
        cout << setw(WIDTH)  << currentNode->value;
        currentNode = currentNode->next;
    }
    cout << endl;
}

// inserts a new node with the given value at the head of the list
// note that the pointer to the head is passed by reference
void insertAtHead(Node* &head, int value)
{
    // create a new node with the given value
    Node* newNode = createNewNode(value);
    // insert the new node at the head of the list
    newNode->next = head;
    head = newNode;
}

// removes the node from the head of the list
// and returns the value of the removed node
// note that the pointer to the head is passed by reference
int removeFromHead(Node* &head)
{
    if(isEmpty(head))  return NULL; // the list is empty
    else    // the list is not empty
    {
        Node* nodeToRemove = head;
        int value = nodeToRemove->value;
        head = nodeToRemove->next;
        delete nodeToRemove;
        return value;
    }
}

void deleteList(Node* &head)
{
    while(!isEmpty(head)) // while the list is not empty
    {
        // remove the node from the head of the list
        removeFromHead(head);
    }
}

void printTwoLists(Node* list1, Node* list2)
{
    cout << "The list of the values: ";
    printList(list1);
    cout << "The reversed list of the values: ";
    printList(list2);
}

int main()
{
    Node* list = NULL; // the head of the list
    Node* reversedList = NULL; // the head of the list

    int numValues;
    cout << "Enter the number of values : ";
    cin >> numValues;
    
    // generate random values and insert them into the linked list
    srand (time(NULL));
    for(int i = 1; i<=numValues; i++)
    {
        // create a new node with a random value 
        // and insert it into the linked list
        int newValue = rand();
        insertAtHead(list, newValue);
    }

    // print both lists 
    printTwoLists(list, reversedList);

    // remove the nodes from the first list 
    // and insert them into the second list in reverse order
    while(!isEmpty(list)) // the list is not empty
    {
        // remove a node from the head of the first list 
        int nextValue = removeFromHead(list);
        // insert the removed value into the head of the reversed list
        insertAtHead(reversedList, nextValue);
    }

    cout << "The values from the first list are removed and inserted into the second list in reverse order." << endl;
    // print both lists 
    printTwoLists(list, reversedList);

    deleteList(list);
    deleteList(reversedList);
    cout << "Both lists are deleted." << endl;
    // print both lists 
    printTwoLists(list, reversedList);

    system("pause");
    return 0;
}    
