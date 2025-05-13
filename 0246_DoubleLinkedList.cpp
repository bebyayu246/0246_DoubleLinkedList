#include <iostream>
using namespace std;

struct Node
{
    int noMhs;
    string name;

    Node *next;
    Node *prev;
};

Node *START = NULL;

void addNode()
{
    Node *newNode = new Node();
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name off the student: ";
    cin >> newNode->name;

    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        
    }
}