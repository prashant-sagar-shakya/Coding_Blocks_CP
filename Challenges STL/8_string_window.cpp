/*
Problem Name: String Window
Problem Difficulty: 3
Problem Constraints: Length of both the strings can be at max 10^4
Problem Description:
Ravi has been given two strings named string1 and string 2. He is supposed to find the minimum length substring of the string1 which contains all the characters of string2. Help him to find the substring

Input Format: The first line of the input contains string1. String1 can be a string containing spaces also.
The second line of the input contains string2. String2 can be a string containing spaces also.
Sample Input: qwerty asdfgh qazxsw
qas
Output Format: Output the substring in a single line. If no such substring exist then output "No String" without quotes
Sample Output: qazxs
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

// Your code here
void Solve()
{
    string s, t;
    getline(cin, s); // Input main string
    getline(cin, t); // Input target string

    unordered_map<char, int> m;
    for (char c : t)
        m[c]++; // Store frequency of required characters

    int l = 0, cnt = t.size(), st = 0, mn = INT_MAX; // Left pointer, missing chars, start index, minimum length

    for (int r = 0; r < s.size(); r++)
    { // Expand window using right pointer
        if (m[s[r]]-- > 0)
            cnt--; // If character is needed, decrease missing count

        while (cnt == 0)
        { // Window contains all required characters
            if (r - l + 1 < mn)
                mn = r - l + 1, st = l; // Update smallest valid window

            if (++m[s[l++]] > 0)
                cnt++; // Remove left char; if now missing, shrink stops
        }
    }

    cout << (mn == INT_MAX ? "No String" : s.substr(st, mn)); // Print minimum window or No String
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