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
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl;              // Print the front element (10)
    q.pop();                                // Remove the front element (10)
    cout << q.front() << endl;              // Print the new front element (20)
    q.back() = 40;                          // Change the back element to 40
    cout << q.back() << endl;               // Print the back element (40)
    cout << boolalpha << q.empty() << endl; // Check if the queue is empty (returns false)
    cout << q.size() << endl;               // Print the size of the queue (1)
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