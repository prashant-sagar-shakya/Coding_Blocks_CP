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

// Function to return a list of nodes visible from the top view
// from left to right in Binary Tree.
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    // BFS traversal
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;

        if (mpp.find(line) == mpp.end())
            mpp[line] = node->data;

        // Process left child
        if (node->left != NULL)
            q.push({node->left, line - 1});

        // Process right child
        if (node->right != NULL)
            q.push({node->right, line + 1});
    }

    for (auto it : mpp)
        ans.push_back(it.second);

    return ans;
}

// Your code here
void Solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = topView(root);
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