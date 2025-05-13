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
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }

        newNode->next = START;
        if (START != NULL)
        {
            START->prev = newNode;
        }
        newNode->prev = NULL;
        START = newNode;
    }
    else
    {
        Node *current = START;
        Node *previous = NULL;

        while (current != NULL && current->noMhs < newNode->noMhs)
        {
            previous = current;
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = previous;

        if (current != NULL)
        {
            current->prev = newNode;
        }
        
        else
        {
            START = newNode;
        }
    }
};

bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = NULL;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted:";
    cin >> rollNo;

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }

    if (current = START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;
}

bool listEmpty()
{
    return (START == NULL);
}

void traverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in ascending order of roll number are: " << endl;
        Node* currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

void revtraverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl
    else
    {
        cout << "\nRecored in ascending order of roll number are: " << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
        
            currentNode = currentNode->next;
        
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << "" << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

void searchData()
{
    if (listEmpty() == true)
    {
        cout << "\nList is empty" << endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
}

int main()
{
    while (true)
    {
        try
        {
        cout << "\nMenu" << endl;
        cout << "1. Menambahkan data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data dalam urutan nomor gulungan yang meningkat" << endl;
        cout << "4. Menampilkan semua data dalam urutan nomor gulungan yang menurun" << endl;
        cout << "5. Mencari data dalam list" << endl;
        cout << "6. Keluar" << endl;
        cout << "\nMasukkan pilihan (1-6): ";
        char ch;
        cin >> ch;
        switch (ch)
            {
            case '1':
                addNode();
                break;
            case '2':
                deleteNode();
                break;
            case '3':
                traverse();
                break;
            case '4':
                revtraverse();
                break;
            case '5':
                searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "\nInvalid option" << endl;
                break;
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}
