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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root)
        if (key < root->val)
            root->left = deleteNode(root->left, key); // We frecursively call the function until we find the target node
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left && !root->right)
                return NULL; // No child condition
            if (!root->left || !root->right)
                return root->left ? root->left : root->right; // One child contion -> replace the node with it's child
                                                              // Two child condition
            TreeNode *temp = root->left;                      //(or) TreeNode *temp = root->right;
            while (temp->right != NULL)
                temp = temp->right;                         //      while(temp->left != NULL) temp = temp->left;
            root->val = temp->val;                          //       root->val = temp->val;
            root->left = deleteNode(root->left, temp->val); //        root->right = deleteNode(root->right, temp);
        }
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
            5
         /     \
        3       6
       / \       \
      2   4       7
*/

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    root = deleteNode(root, 3);
    output(root);
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