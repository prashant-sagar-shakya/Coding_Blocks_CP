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

#include <bits/stdc++.h>
using namespace std;

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    long long tot = 0;
    for (auto x : arr)
        tot += x;

    // 1. Kadane's algorithm for single array
    long long sum = 0, best = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max((long long)arr[i], sum + arr[i]);
        best = max(best, sum);
    }
    long long ans = best;

    // 2. Prefix max
    long long prefix = 0, maxPrefix = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        maxPrefix = max(maxPrefix, prefix);
    }

    // 3. Suffix max
    long long suffix = 0, maxSuffix = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        suffix += arr[i];
        maxSuffix = max(maxSuffix, suffix);
    }

    // 4. If k >= 2, check across multiple concatenations
    if (k >= 2)
    {
        ans = max(ans, maxSuffix + maxPrefix);
        ans = max(ans, maxSuffix + tot * (k - 2) + maxPrefix);
    }

    return ans % MOD;
}

// Your code here
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << kConcatenationMaxSum(arr, k) << endl;
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