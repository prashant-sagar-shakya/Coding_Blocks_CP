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

// Your code here
void Solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> res(n);

    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    for (int i = 0; i < n; i++)
        res[i] = a[i] - b[i];

    ordered_set<pair<int, int>> s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = s.size() - s.order_of_key({-res[i], 10000000}); // checking the no. of element which are greater than -ve of the current value in the left side from the current value
        ans += val;
        s.insert({res[i], i});
    }
    cout << endl;
    cout << ans;
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