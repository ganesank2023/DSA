#include <stdio.h>
#include <iostream>
using namespace std;

// Node creation
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Root
struct node *root;

// Add nodes
int addNodes(struct node *node)
{
    if (node->left == node->right)
        return 0;
    if (node->left == NULL)
        return node->data + addNodes(node->right);
    if (node->right == NULL)
        return node->data + addNodes(node->left);
    else
        addNodes(node->right) + addNodes(node->left);
}

// Insertion
void insert(struct node *node, int data)
{
    struct node *ptr = root, *newnode = (struct node *)malloc(sizeof(struct node)), *current;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
        root = newnode;
    else
    {
        while (ptr)
        {
            current = ptr;
            if (data > ptr->data)
                ptr = ptr->right;
            else if (data < ptr->data)
                ptr = ptr->left;
            else
            {
                cout << "\nNO DUPLICATE ALLOWED.." << endl;
                return;
            }
        }
        if (data > current->data)
            current->right = newnode;
        else
            current->left = newnode;
    }
}

int main()
{
    int data, choice;
choose:
    cout << "\n1. Insert data"
         << "\n2. Find sum" << endl;
    cout << "\nProvide a choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nEnter a data: ";
        cin >> data;
        insert(root, data);
        goto choose;
        cout << endl;
        break;
    case 2:
        int result;
        result = addNodes(root);
        cout << "\nSum of root nodes: " << result << endl;
        break;
    default:
        cout << "\nProvide a valid choice";
        goto choose;
        break;
    }
}
