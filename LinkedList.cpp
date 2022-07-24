#include <iostream>
using namespace std;

// Global variables;
int length = 0;
struct node *head = NULL;

// Node creation
struct node
{
    int data;
    struct node *link;
};

// Insertion at the end

void insertAtEnd(int data)
{
    struct node *ptr = head, *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;
    if (head == NULL)
        head = newnode;
    else
    {
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newnode;
    }
    length++;
    cout << "\n"
         << data << " inserted succesfully" << endl;
}

// Insertion at the begining

void insertAtBegining(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node)), *prt = head;
    newnode->data = data;
    if (head == NULL)
        newnode->link = NULL;
    else
        newnode->link = head;
    head = newnode;
    length++;
    cout << "\n"
         << data << " inserted successfully" << endl;
}

// Insert at a specific pos

void insertAtPos(int data, int pos)
{
    struct node *ptr = head, *newnode = (struct node *)malloc(sizeof(struct node));
    if (pos == 1)
        insertAtBegining(data);
    else if (pos == length + 1)
        insertAtEnd(data);
    else if (pos > 1 && pos <= length)
    {
        int tpos = pos, count = 2;
        while (ptr->link != NULL)
        {
            if (count == tpos)
            {
                newnode->data = data;
                newnode->link = ptr->link;
                ptr->link = newnode;
                break;
            }
            else
            {
                count++;
                ptr = ptr->link;
            }
        }
        length++;
        cout << "\n"
             << data << " inserted successfully" << endl;
    }
    else
        cout << "\nNOT ENOUGH VALUES :(";
}

// Traverse function

void traverse()
{
    if (head == NULL)
        cout << "\nLIST IS EMPTY :(" << endl;
    else
    {
        struct node *ptr = head;
        cout << "\nThe list has " << length << " elements" << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
        cout << "\n";
    }
}

// Delete at the end

void deleteAtEnd()
{
    struct node *ptr = head;
    while (ptr->link->link != NULL)
        ptr = ptr->link;
    cout << "\n"
         << ptr->link->data << " deleted succesfully" << endl;
    ptr->link = NULL;
    length--;
}

// Delete at the begining

void deleteAtBegining()
{
    struct node *ptr = head->link;
    cout << "\n"
         << head->data << " deleted succesfully" << endl;
    head = ptr;
    length--;
}

// Delete at a position

void deleteAtPos(int pos)
{
    struct node *ptr = head, *newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
        traverse();
    else if (pos == 1)
        deleteAtBegining();
    else if (pos == length)
        deleteAtEnd();
    else if (pos > 1 && pos < length)
    {
        int tpos = pos, count = 2;
        while (ptr->link != NULL)
        {
            if (count == tpos)
            {
                cout << "\n"
                     << ptr->link->data << " deleted successfully" << endl;
                ptr->link = ptr->link->link;
                break;
            }
            else
            {
                count++;
                ptr = ptr->link;
            }
        }
        length--;
    }
    else
        cout << "\nNOT ENOUGH VALUES :(";
}

//  Main function
int main()
{
    int choice, data, pos;
choose: // List of options to perform operations
    cout << "\n";
    cout << "\n1. Insert at the end"
         << "\n2. Insert at the begining"
         << "\n3. Insert at a specific position (Index 1)("
         << "\n4. Delete at the end"
         << "\n5. Delete at the begining"
         << "\n6. Delete at the specific pos (Index 2)"
         << "\n7. Traverse the list"
         << "\n8. Exit"
         << "\n";
    cout << "\nProvide a choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nENTER THE DATA: ";
        cin >> data;
        insertAtEnd(data);
        traverse();
        goto choose;
        break;
    case 2:
        cout << "\nENTER THE DATA: ";
        cin >> data;
        insertAtBegining(data);
        traverse();
        goto choose;
        break;
    case 3:
        cout << "\nENTER THE POSITION: ";
        cin >> pos;
        cout << "\nENTER THE DATA: ";
        cin >> data;
        insertAtPos(data, pos);
        traverse();
        goto choose;
    case 4:
        if (head == NULL)
            cout << "\nLIST IS EMPTY :(" << endl;
        else if (head->link == NULL)
        {
            deleteAtBegining();
            traverse();
        }
        else
        {
            deleteAtEnd();
            traverse();
        }
        goto choose;
        break;
    case 5:
        if (head == NULL)
            cout << "\nLIST IS EMPTY :(" << endl;
        else
        {
            deleteAtBegining();
            traverse();
        }
        goto choose;
        break;
    case 6:
        if (head == NULL)
            cout << "\nLIST IS EMPTY :(" << endl;
        else
        {
            cout << "\nENTER THE POSITION: ";
            cin >> pos;
            deleteAtPos(pos);
            traverse();
            goto choose;
        }
    case 7:
        traverse();
        goto choose;
    case 8:
        cout << "\nBYE BUDYYY...!! :(" << endl;
        break;
    default:
        cout << "\nProvide a valid choice" << endl;
        goto choose;
        break;
    }
}