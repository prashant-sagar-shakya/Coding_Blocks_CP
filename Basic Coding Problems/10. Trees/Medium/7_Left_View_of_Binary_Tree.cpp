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

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void recLeft(Node *root, int level, vector<int> &v)
{
    if (root == NULL)
        return;
    if (v.size() == level)
        v.push_back(root->data);
    // Swap these below steps for rightView
    recLeft(root->left, level + 1, v);
    recLeft(root->right, level + 1, v);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> v;
    recLeft(root, 0, v);
    return v;
}

// Your code here
void Solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> result = leftView(root);
    for (int val : result)
        cout << val << " ";
    cout << endl;
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