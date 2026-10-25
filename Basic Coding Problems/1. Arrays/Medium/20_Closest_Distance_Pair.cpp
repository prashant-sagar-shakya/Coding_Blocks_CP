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

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
ll closestPair(pair<int, int> *coordinates, int n)
{
    sort(coordinates, coordinates + n);
    ll ans = INT_MAX;
    for (int i = 0; i < n - 1; ++i)
    {
        ll x1 = coordinates[i].first;
        ll x2 = coordinates[i + 1].first;
        ll y1 = coordinates[i].second;
        ll y2 = coordinates[i + 1].second;
        ll anss = (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
        ans = min(anss, ans);
    }
    sort(coordinates, coordinates + n, compare);
    for (int i = 0; i < n - 1; ++i)
    {
        ll x1 = coordinates[i].first;
        ll x2 = coordinates[i + 1].first;
        ll y1 = coordinates[i].second;
        ll y2 = coordinates[i + 1].second;
        ll anss = (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
        ans = min(anss, ans);
    }
    return ans;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    pair<int, int> coordinates[n];
    for (int i = 0; i < n; ++i)
        cin >> coordinates[i].first >> coordinates[i].second;
    cout << closestPair(coordinates, n);
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