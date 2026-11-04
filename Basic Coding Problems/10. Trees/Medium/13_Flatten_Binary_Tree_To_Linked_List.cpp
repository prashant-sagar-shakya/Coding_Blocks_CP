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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *rightmost(TreeNode *root)
{
    if (root->right == NULL)
        return root;
    return rightmost(root->right);
}

void flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    TreeNode *nextright;
    TreeNode *rightMOST;

    while (root)
    {

        if (root->left)
        {
            rightMOST = rightmost(root->left);
            nextright = root->right;
            root->right = root->left;
            root->left = NULL;
            rightMOST->right = nextright;
        }
        root = root->right;
    }
}

// Your code here
void Solve()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    // Print the flattened tree
    TreeNode *curr = root;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->right;
    }
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