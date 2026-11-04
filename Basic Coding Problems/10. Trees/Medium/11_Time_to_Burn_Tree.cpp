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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *findTarget(Node *root, int target)
{
    if (root == NULL)
        return NULL;

    if (root->data == target)
        return root;

    Node *leftAns = findTarget(root->left, target);
    if (leftAns != NULL)
        return leftAns;

    return findTarget(root->right, target);
}

void makeParent(Node *root, unordered_map<Node *, Node *> &parent)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if (cur->left)
        {
            q.push(cur->left);
            parent[cur->left] = cur;
        }
        if (cur->right)
        {
            q.push(cur->right);
            parent[cur->right] = cur;
        }
    }
}

int minTime(Node *root, int target)
{
    Node *start = findTarget(root, target);
    unordered_map<Node *, Node *> parent;
    makeParent(root, parent);

    queue<Node *> q;
    q.push(start);
    int time = 0;
    unordered_map<Node *, bool> vis;
    vis[start] = true;
    while (!q.empty())
    {
        int size = q.size();
        bool burned = false;
        for (int i = 0; i < size; i++)
        {
            Node *cur = q.front();
            q.pop();
            if (cur->left && vis[cur->left] == false)
            {
                vis[cur->left] = true;
                q.push(cur->left);
                burned = true;
            }
            if (cur->right && vis[cur->right] == false)
            {
                vis[cur->right] = true;
                q.push(cur->right);
                burned = true;
            }
            if (parent[cur] && vis[parent[cur]] == false)
            {
                vis[parent[cur]] = true;
                q.push(parent[cur]);
                burned = true;
            }
        }
        if (burned)
            time++;
    }
    return time;
}

// Your code here
void Solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;
    int result = minTime(root, target);
    cout << result << endl;
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