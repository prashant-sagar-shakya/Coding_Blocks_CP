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

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    vector<int> v;

    inorder(root, v);

    int s = 0;
    int e = v.size() - 1;
    int mid;

    while (s <= e)
    {
        if (v[0] == key)
            return make_pair(-1, v[1]);

        if (v[0] > key)
            return make_pair(-1, v[0]);

        if (v[e] == key)
            return make_pair(v[e - 1], -1);

        if (v[e] < key)
            return make_pair(v[e], -1);

        mid = s + (e - s) / 2;

        if (v[mid] == key)
            return make_pair(v[mid - 1], v[mid + 1]);

        if (v[mid] < key)
            s = mid + 1;

        if (v[mid] < key && v[mid + 1] > key)
            return make_pair(v[mid], v[mid + 1]);

        if (v[mid] > key)
            e = mid - 1;

        if (v[mid] > key && v[mid - 1] < key)
            return make_pair(v[mid - 1], v[mid]);
    }
}

// Your code here
void Solve()
{
    /*
            15
          /    \
        10      20
       /  \    /  \
      8   12  16   25
*/

    TreeNode *root = new TreeNode(15);

    root->left = new TreeNode(10);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(12);

    root->right->left = new TreeNode(16);
    root->right->right = new TreeNode(25);

    int key = 12;
    pair<int, int> result = predecessorSuccessor(root, key);
    cout << "Predecessor of " << key << " is: " << result.first << endl;
    cout << "Successor of " << key << " is: " << result.second << endl;
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}