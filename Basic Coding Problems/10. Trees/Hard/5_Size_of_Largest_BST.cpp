#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Funtion to validate bst
bool isValidBst(Node *root, int minValue, int maxValue)
{
    if (!root)
        return true;
    if (root->data >= maxValue || root->data <= minValue)
        return false;
    return isValidBst(root->left, minValue, root->data) && isValidBst(root->right, root->data, maxValue);
}

// Funtion to calculate size of subtree
int size(Node *root)
{
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Finds the size of the largest BST
int largestBst(Node *root)
{
    if (!root)
        return 0;

    // Check Subtree is valid or not
    if (isValidBst(root, INT_MIN, INT_MAX))
        return size(root);

    // Recursively call for left and right child
    return max(largestBst(root->left), largestBst(root->right));
}

// Your code here
void Solve()
{
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << largestBst(root) << endl;
}

// Driver code
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}