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
    vector<int> a;
    vector<int> b(5, 10);         // vector of size 5 with all elements initialized to 10
    vector<int> c{1, 2, 3, 4, 5}; // vector initialized with a list of values

    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }

    cout << endl;

    for (auto &x : b)
    {
        cout << x << " ";
    }

    cout << endl;

    for (auto it = c.begin(); it != c.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    vector<int> d;
    int n;
    cin >> n; // Input the number of elements to be added to vector d
    for (int i = 0; i < n; i++)
    {
        d.push_back(i * 2);
    }
    cout << d.size() << endl;     // Output the size of vector d
    cout << d.capacity() << endl; // Output the capacity of vector d
    cout << d.max_size() << endl; // Output the maximum size of vector d that memory can hold in worst case
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