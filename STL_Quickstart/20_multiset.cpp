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
    // Multiset is as simmilar as sets but it can store multiple elements that have same elements
    // All elements are stored in a specific order -> sorted according to internal comparision object
    // Once the values are inserted cannot be modified further
    // Associative container -> Elements are reffered by their values not by their indices
    // Underlying implementation is a BST

    int arr[] = {10, 20, 30, 20, 30, 30, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    multiset<int> ms(arr, arr + n);

    // Erase 20
    ms.erase(20);

    // Insert 80
    ms.insert(80);

    // Iterate
    for (auto i : ms)
        cout << i << " ";
    cout << endl;

    // Count - to see how many times a specific number is there in a multiset
    cout << ms.count(10) << endl;

    // Find
    auto it = ms.find(30);
    cout << *it << endl;

    // Get all elements which are equal to 30
    pair<multiset<int>::iterator, multiset<int>::iterator> p = ms.equal_range(30);

    for (auto it = p.first; it != p.second; it++)
        cout << *it << " ";
    cout << endl;

    // Lower bound (greater and equal to) and Upper bound (strictly greater than)
    for (auto it = ms.lower_bound(10); it != ms.upper_bound(77); it++)
        cout << *it << " ";
    cout << endl;
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