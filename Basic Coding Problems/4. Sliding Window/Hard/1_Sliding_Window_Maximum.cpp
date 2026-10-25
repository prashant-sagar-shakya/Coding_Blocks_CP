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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        // Remove indices outside the window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Maintain decreasing order in deque
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Add maximum for the current window
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

// Your code here
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    vector<int> res = maxSlidingWindow(nums, k);
    for (int i : res)
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