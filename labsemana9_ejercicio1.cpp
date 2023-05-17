#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

void printTreeInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTreeInOrder(root->left);
    cout << root->data << " ";
    printTreeInOrder(root->right);
}
void printTreePreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    printTreePreOrder(root->left);

    printTreePreOrder(root->right);
}
void printTreePostOrder(Node *root)
{
     if (root == NULL)
    {
        return;
    }
    printTreePreOrder(root->left);

    printTreePreOrder(root->right);

    cout << root->data << " ";
}


int main()
{
    Node *root; 
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printTreeInOrder(root);
    
    cout << endl << "--------------------------------"<<endl;
    
    printTreePreOrder(root);


    cout << endl << "--------------------------------"<<endl;
    
    printTreePostOrder(root);   


    return 0;
}

