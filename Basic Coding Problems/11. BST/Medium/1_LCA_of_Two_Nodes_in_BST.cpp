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

// Approach : Iterative BST Traversal

// Time Complexity = O(h) => h = height of the tree
/* Each iteration moves down one level.
 * We follow a single path, visiting at most h nodes.
 * Balanced BST: h = O(log n) → O(log n) time.
 * Skewed BST: h = O(n) → O(n) time.
 */

// Space Complexity = O(1) =>
/* Only one extra pointer, current, is stored.
 * No additional arrays, stacks, or queues are used.
 * The traversal is iterative, so there is no recursion stack.
 */

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    // Step 1: Start at the root.
    TreeNode *curr = root;

    // Step 2: Follow the subtree containing both target nodes.
    while (curr != NULL)
    {

        if (p->val < curr->val && q->val < curr->val)
        {
            // Step 3: Both targets are smaller, so move left.
            curr = curr->left;
        }

        else if (p->val > curr->val && q->val > curr->val)
        {
            // Step 4: Both targets are larger, so move right.
            curr = curr->right;
        }
        else
        {
            // Step 5: Targets split here, or current equals p or q.
            // No deeper node can be an ancestor of both.
            return curr;
        }
    }

    // Both targets exist, so valid inputs always return inside the loop.
    return NULL;
}

// Your code here
void Solve()
{
    /*
            6
         /     \
        2       8
       / \     / \
      0   4   7   9
         / \
        3   5
*/

    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode *p = root->left;       // Node with value 2
    TreeNode *q = root->left->right; // Node with value 4
    TreeNode *lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << endl;
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