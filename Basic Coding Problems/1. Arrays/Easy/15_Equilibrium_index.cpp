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

int EquilibriumIndex(vector<int> &nums)
{
    int n = nums.size(), sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        if (curr - nums[i] == sum - curr)
            return i;
    }
    return -1;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    cout << EquilibriumIndex(nums);
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