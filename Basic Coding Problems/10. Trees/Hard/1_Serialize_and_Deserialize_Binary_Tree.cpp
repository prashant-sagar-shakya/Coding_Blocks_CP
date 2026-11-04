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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode *root)
{
    if (!root)
        return "null";
    queue<TreeNode *> q;
    q.push(root);
    string res;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            res += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            res += "null,";
        }
    }
    return res;
}

TreeNode *deserialize(string data)
{
    if (data == "null")
        return nullptr;
    stringstream ss(data);
    string token;
    getline(ss, token, ',');
    TreeNode *root = new TreeNode(stoi(token));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (!getline(ss, token, ','))
            break;
        if (token != "null")
        {
            node->left = new TreeNode(stoi(token));
            q.push(node->left);
        }
        if (!getline(ss, token, ','))
            break;
        if (token != "null")
        {
            node->right = new TreeNode(stoi(token));
            q.push(node->right);
        }
    }
    return root;
}

// Your code here
void Solve()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;
    TreeNode *deserializedRoot = deserialize(serialized);
    string reserialized = serialize(deserializedRoot);
    cout << "Reserialized: " << reserialized << endl;
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