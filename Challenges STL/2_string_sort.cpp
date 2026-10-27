/*
Problem Name: String Sort
Problem Difficulty: 2
Problem Constraints: N<=1000
Problem Description:
Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

Input Format: N(integer) followed by N strings.
Sample Input: 3
bat
apple
batman
Output Format: N lines each containing one string.
Sample Output: apple
batman
bat
*/

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

bool StrComp(const string &a, const string &b)
{
    if (a.find(b) != string::npos || b.find(a) != string::npos)
        return a.length() > b.length();
    return a < b;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end(), StrComp);
    for (auto i : v)
        cout << i << endl;
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