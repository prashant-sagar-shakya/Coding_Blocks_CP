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

    int low = 0, high = n;
    while (low <= high)
    {
        int cutA = low + (high - low) / 2;
        int cutB = (2 * n + 1) / 2 - cutA;

        int leftA = (cutA == 0) ? INT_MIN : a[cutA - 1];
        int rightA = (cutA == n) ? INT_MAX : a[cutA];
        int leftB = (cutB == 0) ? INT_MIN : b[cutB - 1];
        int rightB = (cutB == n) ? INT_MAX : b[cutB];

        // Core logic of BS
        if (leftA <= rightB && rightA >= leftB)
        {
            int maxi = max(leftA, leftB);
            int mini = min(rightA, rightB);
            cout << (maxi + mini) / 2;
            return;
        }

        // A's left partition contains a value that's too large
        else if (leftA > rightB)
            high = cutA - 1;

        // A's left partition contains a value that's too small
        else
            low = cutA + 1;
    }
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