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

// Insert at end
void insertAtEnd(int data)
{
    node *newnode = (struct node *)malloc(sizeof(struct node)), *ptr = head;
    newnode->data = data;
    if (head = NULL)
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
    if (head = NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
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
                newnode->prev = ptr;
                newnode->next = ptr->next;
                ptr = newnode;
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

// Main function
int main()
{
}