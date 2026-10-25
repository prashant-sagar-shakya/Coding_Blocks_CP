#include <bits/stdc++.h>
#include <queue>
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
    priority_queue<int> pq; // Max-Heap by default
    // We can make a priotity queue a Min-Heap by passing an underlying vector with greater<int> as the comparator function
    // priority_queue<int, vector<int>, greater<int>> pq_min; // Min-Heap
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x); // Insert elements into the priority queue O(logN)
    }

    // Remove the elements from the priority queue and print them in sorted order
    while (!pq.empty())
    {
        cout << pq.top() << " "; // Print the maximum element
        pq.pop();                // Remove the maximum element
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