#include <iostream>
using namespace std;

// Global variable
struct node *head = NULL;
int length = 0;

// Node creation
struct node
{
    int data;
    struct node *next, *prev;
};

// Traverse forward
void traverse()
{
    if (head == NULL)
        cout << "\nLIST IS EMPTY :(" << endl;
    else
    {
        cout << "\nThe list after removing dulicates " << endl;
        struct node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
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

// Delete at end

void deleteAtEnd()
{
    if (head == NULL)
        traverse();
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

    if (pos == length)
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

// Remove dupicate

void removeDuplicate()
{
    int count = 0, pos = 1;
    struct node *ptr = head, *temp = ptr->next;
    while (ptr != NULL)
    {
        while (temp != NULL)
        {
            pos++;
            if (ptr->data == temp->data)
            {
                count++;
                deleteAtPos(pos);
            }
            temp = temp->next;
        }
        ptr = ptr->next;
    }
    if (count == 0)
        cout << "\nNO DUPLICATES FOUND" << endl;
    else
        traverse();
}
// Main function
int main()
{
    int choice, data;
choose: // List of options to perform operations
    cout << "\n";
    cout << "\n1. Insert element in the list"
         << "\n2. Remove duplicates" << endl;
    cout << "Provide a choice :";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter a data: ";
        cin >> data;
        insertAtEnd(data);
        goto choose;
        break;
    case 2:
        removeDuplicate();
        break;
    default:
        cout << "\nPlease provide a valid choice" << endl;
        goto choose;
        break;
    }
}