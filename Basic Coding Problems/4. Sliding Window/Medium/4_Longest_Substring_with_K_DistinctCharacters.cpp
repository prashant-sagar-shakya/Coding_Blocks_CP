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

int longestKSubstr(string &s, int k)
{
    // your code here
    unordered_map<char, int> mpp;
    int ans = -1, left = 0, right = 0;
    while (right < s.length())
    {
        mpp[s[right]]++;
        if (mpp.size() > k)
        {
            mpp[s[left]]--;

            if (mpp[s[left]] == 0)
                mpp.erase(s[left]);

            left++;
        }
        if (mpp.size() == k)
            ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

// Your code here
void Solve()
{
    string s;
    int k;
    cin >> s >> k;
    cout << longestKSubstr(s, k) << endl;
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