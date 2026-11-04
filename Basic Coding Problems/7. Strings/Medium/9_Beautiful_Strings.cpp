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
void Solve(string str, string s, int index, int &cnt)
{
    if (index >= str.length())
        return;
    if (str[index] != s[index])
        cnt++;
    if (s[index] == '0')
        Solve(str, s + "1", index + 1, cnt);
    else
        Solve(str, s + "0", index + 1, cnt);
}

int makeBeautiful(string str)
{
    string s = "";
    int cnt1 = 0, cnt2 = 0;
    Solve(str, s + "0", 0, cnt1);
    Solve(str, s + "1", 0, cnt2);
    return min(cnt1, cnt2);
}

// Driver code
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << makeBeautiful(s) << endl;
    }
    return 0;
}