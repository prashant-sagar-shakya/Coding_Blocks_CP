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

TreeNode *previousNode = NULL;
TreeNode *last = NULL;
TreeNode *first = NULL;
TreeNode *middle = NULL;

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    if (previousNode != NULL && previousNode->val > root->val)
    {
        if (first == NULL)
        {
            first = previousNode;
            middle = root;
        }
        else
            last = root;
    }

    previousNode = root;

    inorder(root->right);
}

TreeNode *FixBST(TreeNode *root)
{
    previousNode = NULL;
    last = NULL;
    first = NULL;
    middle = NULL;

    inorder(root);

    if (last != NULL && first != NULL)
        swap(last->val, first->val);
    else if (first != NULL && middle != NULL)
        swap(first->val, middle->val);

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

void Solve()
{
    // Your Code Here

    /*
                20
              /    \
            10      35
           /  \    /  \
          5   15  30   42
             /
            13
    */

    TreeNode *root = new TreeNode(20);

    root->left = new TreeNode(10);
    root->right = new TreeNode(35);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);

    root->left->right->left = new TreeNode(13);

    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(42);
    root = FixBST(root);
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