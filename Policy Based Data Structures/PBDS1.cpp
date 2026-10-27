#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Your code here
void Solve()
{
    // Policy based data structures works like a set
    // find_by_order(k) - It returns iterator to the kth largest element (Start from 0th place)
    // order_of_key(k) -> It returns the number of elements in the set which are strictly less than k
    // These both functions works in O(logN) time
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}