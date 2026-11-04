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

int index = 0;
unordered_map<int, int> mpp;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    for (int i = 0; i < inorder.size(); ++i)
        mpp[inorder[i]] = i;
    return helper(preorder, 0, inorder.size() - 1);
}

TreeNode *helper(vector<int> &preorder, int start, int end)
{
    if (start > end)
        return nullptr;

    int rootVal = preorder[index++];
    TreeNode *root = new TreeNode(rootVal);
    int mid = mpp[rootVal];

    root->left = helper(preorder, start, mid - 1);
    root->right = helper(preorder, mid + 1, end);
    return root;
}

// Your code here
void Solve()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTree(preorder, inorder);

    // Print the tree in-order to verify
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
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