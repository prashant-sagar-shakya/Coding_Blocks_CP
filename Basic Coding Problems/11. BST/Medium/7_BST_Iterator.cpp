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

class BSTIterator
{
public:
    stack<TreeNode *> st;
    void pushLeft(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }
    int next()
    {
        TreeNode *curr = st.top();
        st.pop();
        if (curr->right)
            pushLeft(curr->right);
        return curr->val;
    }
    bool hasNext()
    {
        return !st.empty();
    }
};

void output(BSTIterator *obj)
{
    while (obj->hasNext())
    {
        cout << obj->next() << " ";
    }
    cout << endl;
}

// Your code here
void Solve()
{
    /*
            7
          /   \
         3     15
              /  \
             9    20
*/

    TreeNode *root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator *obj = new BSTIterator(root);
    output(obj);
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