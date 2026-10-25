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

vector<ll> maxProductCount(vector<int> &arr, int n)
{
    if (n < 4)
        return {0};

    vector<ll> ans;
    unordered_map<ll, ll> mp;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ll res = (ll)arr[i] * (ll)arr[j];
            mp[res]++;
        }

    ll mx = -1e12;
    for (auto v : mp)
        mx = max(mx, v.second);
    if (mx == 1)
        return {0};

    ll mi = 1e12;
    for (auto v : mp)
    {
        if (v.second == mx)
            mi = min(mi, v.first);
    }
    long long a = mx * (mx - 1) / 2;
    ans.push_back(mi);
    ans.push_back(a);
    return ans;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<ll> res = maxProductCount(arr, n);
    for (ll i : res)
        cout << i << " ";
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