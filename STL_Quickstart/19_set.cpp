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
    // Set is a container that is used to store unique collection of elements, we can't update elements once inserted but can insert, iterate over them and delete
    // Two types:
    // 1. set -> ordered collection of unique elements (order is maintained via self balancing BST or Red-Black tree in a complete binary tree format)
    // 2. unordered_set -> unordered collection of unique elements

    int arr[] = {10, 20, 11, 9, 8, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    set<int> s;
    // unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    // Removing elements from the set
    s.erase(10); // Remove 10 from the set

    // search and delete
    auto it = s.find(11);
    s.erase(11);

    // Print all elements
    // set has its own iterator
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
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