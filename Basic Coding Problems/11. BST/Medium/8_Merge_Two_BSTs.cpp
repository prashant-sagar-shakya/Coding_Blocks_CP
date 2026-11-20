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

vector<int> merge(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans;

    TreeNode *curr1 = root1;
    TreeNode *curr2 = root2;

    stack<TreeNode *> st1;
    stack<TreeNode *> st2;

    while (curr1 || curr2 || !st1.empty() || !st2.empty())
    {
        while (curr1)
        {
            st1.push(curr1);
            curr1 = curr1->left;
        }

        while (curr2)
        {
            st2.push(curr2);
            curr2 = curr2->left;
        }

        int v1 = (st1.empty() ? INT_MAX : st1.top()->val);
        int v2 = (st2.empty() ? INT_MAX : st2.top()->val);

        if (v1 < v2)
        {
            curr1 = st1.top();
            st1.pop();

            ans.push_back(v1);
            curr1 = curr1->right;
        }
        else if (v1 > v2)
        {
            curr2 = st2.top();
            st2.pop();

            ans.push_back(v2);
            curr2 = curr2->right;
        }
        else
        {
            curr1 = st1.top();
            curr2 = st2.top();

            st1.pop();
            st2.pop();

            ans.push_back(v1);
            ans.push_back(v2);

            curr1 = curr1->right;
            curr2 = curr2->right;
        }
    }

    return ans;
}

void output(const vector<int> &arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

// Your code here
void Solve()
{
    /*
    First BST:          Second BST:

         3                   4
        / \                 / \
       1   5               2   6
*/

    TreeNode *root1 = new TreeNode(3);

    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(4);

    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    vector<int> merged = merge(root1, root2);
    cout << "Merged elements from both BSTs: ";
    output(merged);
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