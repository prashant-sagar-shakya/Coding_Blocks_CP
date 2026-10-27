/*
Problem Name: Subarrays with distinct elements
Problem Difficulty: None
Problem Constraints: 1<=N<=10^5
Problem Description:
Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct

Input Format: An integer n denoting size of array followed by n integers
Sample Input: 3
1 2 3
Output Format: The answer mod 10^9+7
Sample Output: 10
*/

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    unordered_map<int, int> mp; // Last index of each element
    ll ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        if (mp.count(a[r]) && mp[a[r]] >= l)
            l = mp[a[r]] + 1; // Move left past duplicate
        mp[a[r]] = r;         // Update last occurrence
        ans = (ans + (ll)(r - l + 1) * (r - l + 2) / 2) % MOD;
    }
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