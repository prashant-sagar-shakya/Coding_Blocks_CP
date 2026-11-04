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

int minOperations(const string &s1, const string &s2, int x)
{
    const int n = static_cast<int>(s1.size());

    // We don't even need a vector<int> diffs! We only need the previous mismatch index.
    int prev_mismatch_idx = -1;
    int mismatch_count = 0;

    // Doubling all costs to avoid x / 2.0 floating point:
    // prev2 = dp[k - 2] (doubled cost)
    // prev1 = dp[k - 1] (doubled cost)
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s1[i] != s2[i])
        {
            ++mismatch_count;
            if (mismatch_count == 1) // First mismatch: only option so far is paying x/2 (doubled = x)
                prev1 = x;
            else
            {
                // Choice 1: Pay x/2 (doubled = x) for current mismatch
                int cost_op1 = prev1 + x;
                // Choice 2: Pair current mismatch with prev_mismatch_idx for cost (i - prev_mismatch_idx)
                // (doubled = 2 * (i - prev_mismatch_idx))
                int cost_op2 = prev2 + 2 * (i - prev_mismatch_idx);

                int curr = min(cost_op1, cost_op2);
                prev2 = prev1;
                prev1 = curr;
            }
            prev_mismatch_idx = i;
        }
    }

    if (mismatch_count % 2 != 0)
        return -1;
    return prev1 / 2;
}

// Your code here
void Solve()
{
    string s1, s2;
    int x;
    cin >> s1 >> s2 >> x;
    cout << minOperations(s1, s2, x) << endl;
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