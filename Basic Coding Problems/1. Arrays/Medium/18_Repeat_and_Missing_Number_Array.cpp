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

vector<int> findRepeatAndMissing(vector<int> &arr)
{
    int n = arr.size();
    ll s = 0, sn = 0, s2 = 0, s2n = 0;
    sn = (ll)n * (n + 1) / 2;
    s2n = (ll)n * (n + 1) * (2 * n + 1) / 6;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        s2 += (ll)arr[i] * (ll)arr[i];
    }
    ll val1 = s - sn;
    ll val2 = s2 - s2n;
    val2 = val2 / val1;
    ll x = (val1 + val2) / 2;
    ll y = x - val1;
    return {(int)x, (int)y};
}

// Your code here
void Solve()
{
    vector<int> arr = {3, 1, 2, 5, 3};
    vector<int> result = findRepeatAndMissing(arr);
    for (int x : result)
        cout << x << " ";
    cout << endl;
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