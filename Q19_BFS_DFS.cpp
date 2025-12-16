#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Create a sample tree for testing
Node *dummyTree()
{
    Node *n3 = new Node(6);
    n3->left = new Node(5);
    n3->right = new Node(7);

    Node *n2 = new Node(2);
    n2->left = new Node(1);
    n2->right = new Node(3);

    Node *n1 = new Node(4);
    n1->left = n2;
    n1->right = n3;

    return n1;
}

// BFS / Level-Order Traversal
void BFS(Node *root)
{
    if (!root)
    {
        cout << "Empty Tree!" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    cout << "Level-Order Traversal: ";
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << endl;
}

// DFS Traversals
void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = dummyTree();

    // BFS
    BFS(root);

    // DFS
    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}