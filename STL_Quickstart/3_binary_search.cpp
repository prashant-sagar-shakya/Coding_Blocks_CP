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
    array<int, 9> arr = {1, 2, 2, 2, 2, 2, 3, 4, 5};
    int n = arr.size();
    int key = 2 ;

    // Using binary_search to check if the key exists in the array
    if (binary_search(arr.begin(), arr.end(), key))
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // Using lower_bound to find the index of the key
    auto it = lower_bound(arr.begin(), arr.end(), key);
    if (it - arr.begin() == n)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << (it - arr.begin()) << endl;

    // lower_bound returns the first position where the key can be inserted to maintain sorted order
    // If the key is present, it returns the index of the first occurrence of the key
    auto lb = lower_bound(arr.begin(), arr.end(), key);
    cout << "Lower bound index of " << key << " is: " << (lb - arr.begin()) << endl;

    // upper_bound returns the first position where the key can be inserted to maintain sorted order
    // If the key is present, it returns the index of the first element greater than the key
    auto ub = upper_bound(arr.begin(), arr.end(), key);
    cout << "Upper bound index of " << key << " is: " << (ub - arr.begin()) << endl;

    // occurrences of the key can be calculated as the difference between upper_bound and lower_bound
    int occurrences = ub - lb;
    cout << "Occurrences of " << key << " is: " << occurrences << endl;
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