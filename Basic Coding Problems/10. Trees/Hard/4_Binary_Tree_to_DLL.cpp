
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void convertToDLL(Node *root, Node *&head, Node *&prev)
{
    if (root == nullptr)
        return;

    // Convert left subtree
    convertToDLL(root->left, head, prev);

    // Link current node
    if (prev == nullptr)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    // Convert right subtree
    convertToDLL(root->right, head, prev);
}

Node *treeToDLL(Node *root)
{
    Node *head = nullptr;
    Node *prev = nullptr;

    convertToDLL(root, head, prev);

    // Last node should point to nullptr
    if (prev != nullptr)
        prev->right = nullptr;

    return head;
}

// Your code here
void Solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node *head = treeToDLL(root);

    // Print the DLL
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}
