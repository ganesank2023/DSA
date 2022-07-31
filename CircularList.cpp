#include <iostream>
using namespace std;

struct node *head = NULL;
int length = 0;

// Node creation
struct node
{
    int data;
    struct node *link;
};

// Insert at the end
void insertAtEnd(int data)
{
    struct node *ptr = head, *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        head->link = head;
    }
    else
    {
        while (ptr->link != head)
            ptr = ptr->link;
        ptr->link = newnode;
        newnode->link = head;
    }
    length++;
    cout << "\n"
         << data << " inserted successfully" << endl;
}

// Traversal function
void traversal()
{
    struct node *ptr = head;
    if (head == NULL)
        cout << "\nLIST IS EMPTY :(" << endl;
    else
    {
        cout << "\nThe list contains " << length << " elements" << endl;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->link;
        } while (ptr != head);
    }
}

// Insertion at the begining

void insertAtBegining(int data)
{
    struct node *ptr = head->link, *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        head->link = head;
    }
    else
    {
        while (ptr->link != head)
            ptr = ptr->link;
        newnode->link = head;
        ptr->link = newnode;
        head = newnode;
    }
    cout << "\n"
         << data << " inserted succesfully";
    length++;
}

// Insert at a position
void insertAtPos(int data, int pos)
{
    struct node *ptr = head, *newnode = (struct node *)malloc(sizeof(struct node));
    if (pos == 1)
        insertAtBegining(data);
    else if (pos == length + 1)
        insertAtEnd(data);
    else if (pos > 1 && pos <= length)
    {
        int count = 2;
        newnode->data = data;
        while (ptr->link != head)
        {
            if (pos == count)
            {
                newnode->link = ptr->link;
                ptr->link = newnode;
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
        cout << "\nNot enough values :|" << endl;
}

// Delete at the end
void deleteAtEnd()
{
    node *ptr = head;
    if (ptr->link == head)
    {
        cout << "\n"
             << ptr->data << " deleted successfully" << endl;
        head = NULL;
    }
    else
    {
        while (ptr->link->link != head)
            ptr = ptr->link;
        cout << "\n"
             << ptr->link->data << " delete successfully" << endl;
        ptr->link = head;
    }
    length--;
}

// Delete at the begining
void deleteAtBegining()
{
    node *ptr = head;
    if (head->link == head)
        deleteAtEnd();
    else
    {
        struct node *ptr = head;
        while (ptr->link != head)
            ptr = ptr->link;
        cout << "\n"
             << head->data << " delted succesfully" << endl;
        head = head->link;
        ptr->link = head;
        length--;
    }
}

// Delte at a pos
void deleteAtPos(int pos)
{
    int count = 2;
    node *ptr = head;
    if (pos == 1)
        deleteAtBegining();
    else if (pos == length)
        deleteAtEnd();
    else if (pos > 1 && pos < length)
    {
        while (ptr->link != head)
        {
            if (count == pos)
            {
                cout << "\n"
                     << ptr->link->data << " deleted successfully" << endl;
                ptr->link = ptr->link->link;
                length--;
                break;
            }
            else
            {
                count++;
                ptr = ptr->link;
            }
        }
    }
}

// Main function
int main()
{
    int choice, data, pos;
choose:
    cout << "\n1. Insert at the end"
         << "\n2. Insert at the begining"
         << "\n3. Insert at a pos"
         << "\n4. Delete at the end"
         << "\n5. Delete at the begining"
         << "\n6. Delete at a pos"
         << "\n7. Traversal"
         << " \n8. Exit";
    cout << "\nProvide a choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter a data: ";
        cin >> data;
        insertAtEnd(data);
        traversal();
        goto choose;
        break;
    case 2:
        cout << "\nEnter a data: ";
        cin >> data;
        insertAtBegining(data);
        traversal();
        goto choose;
        break;
    case 3:
        cout << "\nEnter a position: ";
        cin >> pos;
        cout << "\nEnter the data: ";
        cin >> data;
        insertAtPos(data, pos);
        traversal();
        goto choose;
        break;
    case 4:
        if (head != NULL)
            deleteAtEnd();
        traversal();
        goto choose;
        break;
    case 5:
        if (head != NULL)
            deleteAtBegining();
        traversal();
        goto choose;
        break;
    case 6:
        cout << "\nEnter a position: ";
        cin >> pos;
        if (head != NULL)
            deleteAtPos(pos);
        traversal();
        goto choose;
        break;
    case 7:
        traversal();
        goto choose;
        break;
    case 8:
        cout << "\nBYE BUDDY :)...." << endl;
        break;
    default:
        cout << "\nPlease provide a valid choice" << endl;
        goto choose;
        break;
    }
}
