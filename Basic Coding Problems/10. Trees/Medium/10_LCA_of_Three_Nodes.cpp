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

int lca3Nodes(Node *root, int p, int q, int r)
{
    while (root != nullptr)
    {
        // If all three values are smaller, go to left subtree
        if (p < root->data && q < root->data && r < root->data)
            root = root->left;
        // If all three values are greater, go to right subtree
        else if (p > root->data && q > root->data && r > root->data)
            root = root->right;
        // Otherwise, we have a split (or match) ⇒ current node is LCA
        else
            return root->data;
    }
    // in case values not found
    return -1;
}

// Your code here
void Solve()
{
    Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(70);
    root->left->left = new Node(31);
    root->left->right = new Node(45);
    int p = 40, q = 70, r = 50;
    int ans = lca3Nodes(root, p, q, r);
    cout << ans << endl;
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