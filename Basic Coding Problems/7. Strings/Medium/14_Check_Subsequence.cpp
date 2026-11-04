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

bool isSubsequence(string s, string t)
{
    int n = s.length(), m = t.length();
    int j = 0;
    for (int i = 0; i < m and j < n; i++)
        if (s[j] == t[i])
            j++;
    return (j == n);
}

// Your code here
void Solve()
{
    string s, t;
    cin >> s >> t;
    cout << (isSubsequence(s, t) ? "true" : "false") << endl;
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