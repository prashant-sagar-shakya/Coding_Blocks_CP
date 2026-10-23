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

bool cmp(string a, string b) // Sorting based on length of string, if length is bigger then it will come first, if length is equal then it will sort lexicographically
{
    if (a.length() == b.length())
    {
        return a < b; // If lengths are equal, sort lexicographically
    }
    return a.length() > b.length();
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cin.get(); // Consume the newline character after reading n

    string s[100]; // Vector
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]); // Read the entire line including spaces
    }

    sort(s, s + n);      // Sort the array of strings
    sort(s, s + n, cmp); // Sort based on length of string using our own comparator function

    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
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