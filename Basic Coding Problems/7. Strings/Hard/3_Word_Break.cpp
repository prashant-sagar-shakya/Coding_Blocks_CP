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

bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, 0);
    dp[0] = true;
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && set.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++)
        cin >> wordDict[i];
    cout << (wordBreak(s, wordDict) ? "true" : "false") << endl;
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