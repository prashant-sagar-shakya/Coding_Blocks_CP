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

bool possible(int n, int m, int mid)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
        if (ans > m)
            return false;
    }
    return ans <= m;
}
int nthRoot(int n, int m)
{
    // Code here
    int lb = 1, rb = m;
    while (lb <= rb)
    {
        int mid = lb + (rb - lb) / 2;
        if (possible(n, m, mid))
        {
            lb = mid + 1;
        }
        else
        {
            rb = mid - 1;
        }
    }

    if (pow(rb, n) == m)
        return rb;
    return -1;
}

// Your code here
void Solve()
{
    int n, m;
    cin >> n >> m;
    cout << nthRoot(n, m) << endl;
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