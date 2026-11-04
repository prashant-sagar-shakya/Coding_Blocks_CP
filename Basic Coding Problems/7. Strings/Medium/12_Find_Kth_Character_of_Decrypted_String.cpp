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

char kThCharaterOfDecryptedString(string s, ll k)
{
    //  Write your code here.
    string str = "";
    ll i = 0, n = s.size();

    while (i < n)
    {
        string a, b;
        while (isalpha(s[i]) and i < n)
        {
            a += s[i];
            i++;
        }

        while (isdigit(s[i]) and i < n)
        {
            b += s[i];
            i++;
        }
        ll d = stoll(b), seglen = a.size() * d;

        if (k <= seglen)
            return a[(k - 1) % a.size()];
        else
            k -= seglen;
    }
    return '\0';
}

// Your code here
void Solve()
{
    string s;
    long long k;
    cin >> s >> k;
    cout << kThCharaterOfDecryptedString(s, k) << endl;
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