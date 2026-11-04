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

void constructLPS(string &pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.length())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> search(string &pat, string &txt)
{
    // code here
    int n = txt.length();
    int m = pat.length();
    vector<int> lps(m);
    vector<int> res;
    constructLPS(pat, lps);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;

            if (j == m)
            {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

// Your code here
void Solve()
{
    string txt, pat;
    cin >> txt >> pat;
    vector<int> res = search(pat, txt);
    if (res.empty())
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
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