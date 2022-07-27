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
        return node->data;
    if (node->right == NULL)
        return addNodes(node->left);
    if (node->left == NULL)
        return addNodes(node->right);
    return addNodes(node->left) + addNodes(node->right);
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
        insert(root, data);
        goto choose;
        cout << endl;
        break;
    case 2:
        int result = addNodes(root);
        cout << "\nSum of leaf nodes: " << result << endl;
        break;
    default:
        cout << "\nProvide a valid choice";
        goto choose;
    }
}
