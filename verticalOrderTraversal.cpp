// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node *root;

struct node
{
    int data;
    node *left, *right;
};

void getVerticalOrder(node *root, int hd, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;
    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}
void printVerticalOrder(node *root)
{
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
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
         << "\n2. vertical order" << endl;
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
        cout << "\nVertical order of the tree is: " << endl;
        printVerticalOrder(root);
        break;
    default:
        cout << "\nProvide a valid choice";
        goto choose;
    }
}
