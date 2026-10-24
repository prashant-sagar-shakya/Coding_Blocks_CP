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

int subarraySum(vector<int> &nums, int k)
{
    int cnt = 0, sum = 0;
    unordered_map<int, int> mpp;
    mpp[sum] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int complement = sum - k;
        if (mpp.find(complement) != mpp.end())
            cnt += mpp[complement];
        mpp[sum]++;
    }
    return cnt;
}

// Your code here
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << subarraySum(arr, k) << endl;
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