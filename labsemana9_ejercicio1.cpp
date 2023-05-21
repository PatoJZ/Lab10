#include <iostream>
#include <queue>

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
Node *DepthSearch(Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
    Node *result = NULL;

    // Buscar en el subárbol izquierdo
    result = DepthSearch(root->left, value);

    if (result != NULL)
    {
        return result;
    }

    // Buscar en el subárbol derecho
    result = DepthSearch(root->right, value);

    if (result != NULL)
    {
        return result;
    }

    return NULL;
}

bool breadthFirstSearch(Node *root, int target)
{
    if (root == nullptr)
    {
        return false;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        if (current->data == target)
        {
            return true;
        }

        if (current->left != nullptr)
        {
            q.push(current->left);
        }

        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }

    return false;
}
int main()
{
    Node *root = NULL;

    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    // ejercicio 1 Y 3, la funcion de impresion in order está hecha
    cout << "- Ejercicio 1 y 3" << endl;
    printTreeInOrder(root);

    cout << endl
         << "- Ejercicio 2 --------------------------------" << endl;

    printTreePreOrder(root);

    cout << endl
         << "- Ejercicio 4 --------------------------------" << endl;

    printTreePostOrder(root);

    cout << endl
         << "- Ejercicio 5 --------------------------------" << endl;

    // ejercicio 5
    Node *root1 = createNode(21);
    int arr[] = {18, 6, 9, 10, 7, 19, 15, 12, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        insertNode(root1, arr[i]);
    }

    printTreeInOrder(root1);

    // ejercicio 6

    cout << endl
         << "- Ejercicio 6 --------------------------------" << endl;
    Node *result = DepthSearch(root1, 9);
    if (result != NULL)
    {
        cout << "Se encontro el valor " << 9 << " en el arbol binario." << endl;
    }
    else
    {
        cout << "No se encontro el valor " << 9 << " en el arbol binario." << endl;
    }
    Node *result2 = DepthSearch(root1, 23);
    if (result2 != NULL)
    {
        cout << "Se encontro el valor " << 23 << " en el arbol binario." << endl;
    }
    else
    {
        cout << "No se encontro el valor " << 23 << " en el arbol binario." << endl;
    }

    // ejercicio 7

    cout << "- Ejercicio 7--------------------------------" << endl;
    bool found = breadthFirstSearch(root, 7);

    if (found)
    {
        cout << "El valor " << 7 << " fue encontrado en el arbol." << endl;
    }
    else
    {
        cout << "El valor " << 7 << " no fue encontrado en el arbol." << endl;
    }

    bool found2 = breadthFirstSearch(root, 11);

    if (found2)
    {
        cout << "El valor " << 11 << " fue encontrado en el arbol." << endl;
    }
    else
    {
        cout << "El valor " << 11 << " no fue encontrado en el arbol." << endl;
    }
    return 0;
}
