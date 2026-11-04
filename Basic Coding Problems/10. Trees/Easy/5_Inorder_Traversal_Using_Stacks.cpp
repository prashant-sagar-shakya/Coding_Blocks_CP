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

vector<int> inOrder(Node *root)
{
    vector<int> ans;
    while (root)
    {
        if (!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            Node *curr = root->left;

            // ans.push_back(curr->data);
            while (curr->right && curr->right != root)
            {
                // curr = curr->right;
                curr = curr->right;
            }
            if (curr->right == NULL)
            {
                curr->right = root;
                root = root->left;
            }
            else
            {
                curr->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }
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
    vector<int> result = inOrder(root);
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