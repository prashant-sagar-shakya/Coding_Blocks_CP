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

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int prefixMod = 0, result = 0;

    // There are k mod groups 0...k-1.
    vector<int> modGroups(k);
    modGroups[0] = 1;

    for (int num : nums)
    {
        // Take modulo twice to avoid negative remainders.
        prefixMod = (prefixMod + num % k + k) % k;
        // Add the count of subarrays that have the same remainder as the current
        // one to cancel out the remainders.
        result += modGroups[prefixMod];
        modGroups[prefixMod]++;
    }

    return result;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    cout << subarraysDivByK(nums, k) << endl;
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