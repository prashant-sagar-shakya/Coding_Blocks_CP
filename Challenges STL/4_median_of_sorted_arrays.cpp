/*
Problem Name: Median of Sorted Arrays
Problem Difficulty: None
Problem Constraints: N < 1000
Problem Description:
We are given two sorted arrays of same size n. Find the median of an array formed after merging these two sorted arrays.

Input Format: First line contains the input n. Second and Third line contains n space separated integers.
Sample Input: 5
1 3 5 7 9
2 4 6 8 10
Output Format: Print the median in a single line.
Sample Output: 5
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
    vector<int> b(n);

    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    vector<int> c(2 * n);

    // Merge two sorted arrays
    merge(a.begin(), a.end(),
          b.begin(), b.end(),
          c.begin());

    // Calculate median
    cout << (c[n - 1] + c[n]) / 2 << '\n';
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