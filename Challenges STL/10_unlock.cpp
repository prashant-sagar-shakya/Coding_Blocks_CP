/*
Problem Name: Unlock
Problem Difficulty: 2
Problem Constraints: 1 <= n <= 10^5 1<= K <= 10^9
Problem Description:
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format: First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.
Sample Input: 5 2
3 4 1 2 5
Output Format: The final permutation of the numbers with every number separated by a space with other number.
Sample Output: 5 4 3 2 1
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
    int n, k;
    cin >> n >> k;

    vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i], pos[a[i]] = i; // Store each number's index

    for (int i = 0; i < n && k > 0; i++)
    {
        int x = n - i; // Largest number needed at index i

        if (a[i] == x)
            continue; // Already correct position

        int j = pos[x];   // Find the largest number's current index
        pos[a[i]] = j;    // Update current number's new position
        swap(a[i], a[j]); // Swap to maximize permutation
        pos[x] = i;       // Update largest number's position

        k--; // One swap used
    }

    for (int x : a)
        cout << x << ' '; // Print final permutation
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