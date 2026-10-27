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
    // Inversion Count
    int inversions = 0;
    int arr[] = {1, 5, 2, 3, 6, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    ordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        inversions += (st.size() - st.order_of_key(arr[i]));
        st.insert(arr[i]);
    }
    cout << inversions;
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