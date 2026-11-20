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

struct Treenode
{
    int data;
    Treenode *left, *right;
    Treenode(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

// Approach : DFS with Bounds

// Time Complexity = O(n) =>
/* n is the number of nodes.
 * Each node is visited at most once.
 * Each visit performs constant work: checking bounds and preparing recursive calls.
 * In the worst case, all nodes are checked, so total time is O(n).
 * An invalid node may let us stop early, but the worst-case bound stays O(n).
 */

// Space Complexity = O(h) =>
/* h is the height of the tree.
 * Recursive calls use the call stack.
 * At any moment, the stack holds calls along one root-to-leaf path.
 * Balanced tree: h = O(log n) → space is O(log n).
 * Skewed tree: h = O(n) → space is O(n).
 * The left and right subtrees are processed sequentially, so their stack space does not add together.
 */

bool validate(Treenode *node, long long lower, long long upper)
{
    // Step 1: An empty subtree is a valid BST.
    if (node == NULL)
    {

        return true;
    }

    // Step 2: Check the restrictions imposed by ALL ancestors.
    // Strict bounds also reject duplicate values.
    if (node->data <= lower || node->data >= upper)
    {

        return false;
    }

    // Step 3: Every value in the left subtree must be smaller
    // than this node, while respecting the inherited lower bound.
    if (!validate(node->left, lower, node->data))
    {

        return false;
    }

    // Step 4: Every value in the right subtree must be greater
    // than this node, while respecting the inherited upper bound.
    return validate(node->right, node->data, upper);
}

bool isValidBST(Treenode *root)
{
    // Step 5: Start with bounds beyond all possible int values.
    // long long allows INT_MIN and INT_MAX to be valid node values.
    return validate(root, LLONG_MIN, LLONG_MAX);
}

// Your code here
void Solve()
{
    /*
                10
             /    \
           20      60
          /  \    /  \
        30   90  80   15
          \
           40

    */
    Treenode *root = new Treenode(10);
    root->left = new Treenode(20);
    root->left->left = new Treenode(30);
    root->left->right = new Treenode(90);
    root->left->left->right = new Treenode(40);
    root->right = new Treenode(60);
    root->right->left = new Treenode(80);
    root->right->right = new Treenode(15);

    if (isValidBST(root))
        cout << "The given binary tree is a BST" << endl;
    else
        cout << "The given binary tree is not a BST" << endl;
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