#include <iostream>
using namespace std;

// Node creation
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// Global variables

int length = 0;
struct node *head = NULL;

// Traverse forward
void traverse()
{
    if (head == NULL)
        cout << "\nLIST IS EMPTY :(" << endl;
    else
    {
        cout << "\nThe list has " << length << " elements" << endl;
        struct node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}

// Insert at end
void insertAtEnd(int data)
{
    node *newnode = (struct node *)malloc(sizeof(struct node)), *ptr = head;
    newnode->data = data;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        newnode->prev = ptr;
        newnode->next = NULL;
        ptr->next = newnode;
    }
    cout << "\n"
         << data << " inserted succesfully" << endl;
    length++;
}

// Insert at the begining
void insertAtBegining(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        newnode->prev = NULL;
        head = newnode;
    }
    cout << "\n"
         << data << " inserted succesfully" << endl;
    length++;
}

// Insert at a pos

void insertAtPos(int pos, int data)
{
    if (pos == 1)
        insertAtBegining(data);
    else if (pos == length + 1)
        insertAtEnd(data);
    else if (pos > 1 && pos <= length)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node)), *ptr = head;
        int count = 2;
        newnode->data = data;
        while (ptr->next != NULL)
        {
            if (count == pos)
            {
                newnode->next = ptr->next;
                newnode->prev = ptr;
                ptr->next = newnode;
                ptr->next->prev = newnode;
                break;
            }
            else
            {
                count++;
                ptr = ptr->next;
            }
        }
        length++;
        cout << "\n"
             << data << " inserted succesfully" << endl;
    }
    else
        cout << "\nNOT ENOUGH VALUES" << endl;
}

// Delete at begining

void deleteAtBegining()
{
    if (head == NULL)
        traverse();
    else if (head->next == NULL)
    {
        cout << "\n"
             << head->data << " deleted succesfully" << endl;
        head = NULL;
        length--;
    }
    else
    {
        struct node *ptr = head->next;
        cout << "\n"
             << head->data << " deleted succesfully" << endl;
        ptr->prev = NULL;
        head = ptr;
        length--;
    }
}

// Delete at end

void deleteAtEnd()
{
    if (head == NULL)
        traverse();
    else if (head->next == NULL)
        deleteAtBegining();
    else
    {
        struct node *ptr = head;
        while (ptr->next->next != NULL)
            ptr = ptr->next;
        cout << "\n"
             << ptr->next->data << " deleted succesfully" << endl;
        ptr->next->prev = NULL;
        ptr->next = NULL;
        length--;
    }
}

// Delete at a pos

void deleteAtPos(int pos)
{
    if (pos == 1)
        deleteAtBegining();
    else if (pos == length)
        deleteAtEnd();
    else if (pos > 1 && pos < length)
    {
        struct node *ptr = head;
        int count = 2;
        while (ptr->next != NULL)
        {
            if (count == pos)
            {
                cout << "\n"
                     << ptr->next->data << " deleted succesfully" << endl;
                ptr->next->prev = ptr;
                ptr->next = ptr->next->next;
                break;
            }
            else
            {
                count++;
                ptr = ptr->next;
            }
        }
        length--;
    }
    else
        cout << "\nNOT ENOUGH VALUES" << endl;
}

// Main function
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
        insertAtPos(pos, data);
        traverse();
        goto choose;
    case 4:
        deleteAtEnd();
        traverse();
        goto choose;
        break;
    case 5:
        deleteAtBegining();
        traverse();
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
        cout << "\nBYE BUDYYY...! :(" << endl;
        break;
    default:
        cout << "\nProvide a valid choice" << endl;
        goto choose;
        break;
    }
}