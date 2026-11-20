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

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};

TreeNode *removekeys(TreeNode *root, int l, int r)
{
    // code here
    if (!root)
        return NULL;
    root->left = removekeys(root->left, l, r);
    root->right = removekeys(root->right, l, r);
    if (root->val > r)
        return root->left;
    if (root->val < l)
        return root->right;
    return root;
}

void output(TreeNode *root)
{
    if (root == NULL)
        return;
    output(root->left);
    cout << root->val << " ";
    output(root->right);
}

// Your code here
void Solve()
{
    /*
            6
          /   \
       -13     14
          \   /  \
          -8 13   15
             /
            7
*/

    TreeNode *root = new TreeNode(6);

    root->left = new TreeNode(-13);
    root->right = new TreeNode(14);

    root->left->right = new TreeNode(-8);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(15);

    root->right->left->left = new TreeNode(7);

    int l = -10, r = 13;
    TreeNode *newRoot = removekeys(root, l, r);
    output(newRoot);
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