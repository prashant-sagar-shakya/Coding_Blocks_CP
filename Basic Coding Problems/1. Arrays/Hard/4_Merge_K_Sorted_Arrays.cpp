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

vector<int> mergeArrays(vector<vector<int>> &chunks)
{
    // Code here
    typedef pair<vector<int>::iterator, vector<int>::iterator> it_pair;
    auto comp = [](auto &a, auto &b)
    { return *a.first > *b.first; };
    priority_queue<it_pair, vector<it_pair>, decltype(comp)> q(comp);
    for (auto &v : chunks)
        q.push({v.begin(), v.end()});
    vector<int> res;
    while (q.size())
    {
        auto [it, end] = q.top();
        q.pop();
        res.push_back(*it);
        if (++it != end)
            q.push({it, end});
    }
    return res;
}

// Your code here
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> chunks(k, vector<int>(n / k));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n / k; j++)
            cin >> chunks[i][j];
    vector<int> result = mergeArrays(chunks);
    for (int x : result)
        cout << x << " ";
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