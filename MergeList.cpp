#include <iostream>
using namespace std;

// Global variable declaration
struct node *head1 = NULL, *head2 = NULL;

// Node creation
struct node
{
    int data;
    struct node *next;
};

// Traverse
void traverse(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

// Insertion in the list
struct node *insert(struct node *head, int data)
{
    struct node *ptr = head, *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        return head;
    }
}

// Main function
int main()
{
    int choice, data;
choose:
    cout << "\n1. Insert data in list1"
         << "\n2. Insert data in list2"
         << "\n3. Merge lists" << endl;
    cout << "\nProvide a choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter a data: ";
        cin >> data;
        head1 = insert(head1, data);
        cout << "\n"
             << data << " inserted in list1 succesfully\nElements in list1 are: " << endl;
        traverse(head1);
        goto choose;
    case 2:
        cout << "\nEnter a data: ";
        cin >> data;
        head2 = insert(head2, data);
        cout << "\n"
             << data << " inserted in list2 succesfully\nElements in list2 are: " << endl;
        traverse(head2);
        goto choose;
    case 3:
        if (head1 == NULL || head2 == NULL)
        {
            cout << "\nNOT ENOUGH VALUES TO MERGE" << endl;
            goto choose;
        }
        else
        {
            struct node *ptr = head1;
            while (ptr->next != NULL)
                ptr = ptr->next;
            cout << "\nLIST AFTER MERGE" << endl;
            ptr->next = head2;
            traverse(head1);
        }
        break;
    default:
        cout << "\nProvide a valid choice" << endl;
        goto choose;
        break;
    }
}