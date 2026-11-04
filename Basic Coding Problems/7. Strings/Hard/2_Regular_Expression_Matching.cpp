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

bool isMatch(int i, int j, string &s, string &p)
{
    int n = s.length(), m = p.length();
    if (j == m)
        return i == n;
    bool match = (i < n && (s[i] == p[j] || p[j] == '.'));

    if (j + 1 < m && p[j + 1] == '*')
        return isMatch(i, j + 2, s, p) || (match && isMatch(i + 1, j, s, p));

    return match && isMatch(i + 1, j + 1, s, p);
}

// Your code here
void Solve()
{
    string s, p;
    cin >> s >> p;
    cout << (isMatch(0, 0, s, p) ? "true" : "false") << endl;
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