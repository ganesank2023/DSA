#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node creation
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

// // Delete node
// void deleteNode(struct node *node, int data)
// {

// }

// Level order traversal
void levelOrder(struct node *node)
{
    if (root == NULL)
        return;
    queue<struct node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        struct node *node = q.front();
        cout << node->data;
        q.pop();

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

// Find height
int findHeight(struct node *node)
{
    if (node == NULL)
        return -1;
    else
    {
        int lheight = findHeight(node->left);
        int rheight = findHeight(node->right);
        return lheight > rheight ? lheight + 1 : rheight + 1;
    }
}

// Find common ancestor
int commonAncestor(struct node *node, int d1, int d2)
{
    if (d1 < node->data && d2 > node->data)
        return node->data;
    else if (d1 > root->data && d2 > node->data)
        commonAncestor(node->right, d1, d2);
    else
        commonAncestor(node->left, d1, d2);
}

// Inorder traversal
void inorder(struct node *node)
{
    struct node *ptr = node;
    if (ptr == NULL)
        return;
    inorder(ptr->left);
    cout << ptr->data << " ";
    inorder(ptr->right);
}

// Preorder traversal
void preorder(struct node *node)
{
    struct node *ptr = node;
    if (ptr == NULL)
        return;
    cout << ptr->data << " ";
    preorder(ptr->left);
    preorder(ptr->right);
}

// Post order traversal
void postorder(struct node *node)
{
    struct node *ptr = node;
    if (ptr == NULL)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    cout << ptr->data << " ";
}

// Insertion
void insertData(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node)), *ptr = root, *current;
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
                cout << "NO DUPLICATES ALLOWED ....";
                return;
            }
        }
        if (data > current->data)
            current->right = newnode;
        else
            current->left = newnode;
    }
    cout << "\n"
         << data << " inserted successfully";
}

// Main function

int main()
{
    int choice, data;
choose:
    cout << "\n1. Insert Data \n2. Inorder traversal \n3. Preorder traversal \n4. Postorder traversal \n5. Level order traversal \n6. Common ancestor of two nodes \n7. Height of the bst \n8. Exit" << endl;
    cout << "\nProvide a choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nEnter a data: ";
        cin >> data;
        insertData(data);
        goto choose;
        break;
    case 2:
        cout << "\nInorder traversal of the tree: " << endl;
        inorder(root);
        goto choose;
        break;
    case 3:
        cout << "\nPreorder traversal of the tree: " << endl;
        preorder(root);
        goto choose;
        break;
    case 4:
        cout << "\nPostorder traversal of the tree: " << endl;
        postorder(root);
        goto choose;
        break;
    case 5:
        cout << "\nLevel order traversal of the tree: " << endl;
        levelOrder(root);
        goto choose;
        break;
    case 6:
        int lchild, rchild;
        cout << "\nEnter the value of left child: ";
        cin >> lchild;
        cout << "\nEnter the value of right child: ";
        cin >> rchild;
        cout << "\nCommom ancestor of " << lchild << " and " << rchild << " is " << commonAncestor(root, lchild, rchild) << endl;
        goto choose;
        break;
    case 7:
        cout << "\nHeight of the tree: " << findHeight(root) << endl;
        goto choose;
        break;
    // case 8:
    //     cout << "\nEnter a data: ";
    //     cin >> data;
    //     deleteNode(root, data);
    //     goto choose;
    //     break;
    case 8:
        cout << "\nBye buddy..." << endl;
        break;
    default:
        cout << "\nPlease provide a valid choice" << endl;
        goto choose;
        break;
    }
}