#include <iostream>
using namespace std;

// Global variables creation
int length = 0;
struct node *head = NULL;

// Node creation
struct node
{
    char data;
    struct node *next, *prev;
};

// Traversal
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
    cout << endl;
}

// Insert function
void insert(char ch)
{
    struct node *ptr = head, *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ch;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->prev = ptr;
    }
    length++;
}

// Find middle
struct node *findMiddle()
{
    struct node *ptr = head;
    int count = 1, mid = (length / 2) + 1;
    while (ptr != NULL)
    {
        if (count == mid)
            return ptr;
        else
        {
            ptr = ptr->next;
            count++;
        }
    }
    return ptr;
}

// check palindrome
bool checkPlaindrome(struct node *mid)
{
    struct node *prePtr = mid->prev, *nPtr = mid->next;
    while (prePtr != NULL && nPtr != NULL)
    {
        if (prePtr->data == nPtr->data)
        {
            prePtr = prePtr->prev;
            nPtr = nPtr->next;
        }
        else
            return false;
    }
    return true;
}

// Main function
int main()
{
    char ch;
    cout << "\nEnter a string character by character (.) at the end to stop" << endl;
    while (true)
    {
        cin >> ch;
        if (ch == '.')
            break;
        else
            insert(ch);
    }
    if (length % 2 == 0)
    {
        cout << "\nTHE GIVEN LIST IS NOT PALINDROME" << endl;
        traverse();
    }
    else if (length == 1)
    {
        cout << "\nIt's a palindrome" << endl;
        traverse();
    }
    else
    {
        struct node *mid = findMiddle();
        if (checkPlaindrome(mid))
        {
            cout << "\nThe given list is palindrome" << endl;
            traverse();
        }
        else
        {
            cout << "\nTHE GIVEN LIST IS NOT PALINDROME" << endl;
            traverse();
        }
    }
}