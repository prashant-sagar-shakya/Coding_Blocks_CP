#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

void solve(TreeNode *root, int &cnt, int &ans, int k)
{
    if (root == NULL)
        return;
    // left, root, right
    solve(root->left, cnt, ans, k);
    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    solve(root->right, cnt, ans, k);
}

int kthSmallest(TreeNode *root, int k)
{

    int cnt = 0;
    int ans;
    solve(root, cnt, ans, k);
    return ans;
}

// Your code here
void Solve()
{
    /*
            3
         /     \
        1       4
         \
          2
*/

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root->left->right = new TreeNode(2);

    int k = 1;
    int result = kthSmallest(root, k);
    cout << "The " << k << "th smallest element in the BST is: " << result << endl;
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}