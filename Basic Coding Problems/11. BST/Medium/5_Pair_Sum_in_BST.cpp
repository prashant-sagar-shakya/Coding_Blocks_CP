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

void f(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    arr.push_back(root->val);
    f(root->left, arr);
    f(root->right, arr);
}
bool findTarget(TreeNode *root, int target)
{

    vector<int> arr;
    f(root, arr);
    set<int> st;
    for (int x : arr)
    {
        int diff = target - x;
        if (st.find(diff) != st.end())
        {
            return true;
        }
        st.insert(x);
    }
    return false;
}

// Your code here
void Solve()
{
    /*
            7
          /   \
         3     8
        / \     \
       2   4     9
*/

    TreeNode *root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(9);

    int target = 6;
    if (findTarget(root, target))
        cout << "Found a pair with the given target sum: " << target << endl;
    else
        cout << "No pair found with the given target sum: " << target << endl;
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