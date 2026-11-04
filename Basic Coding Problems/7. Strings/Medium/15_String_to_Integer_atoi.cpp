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

int myAtoi(string s)
{
    if (s.empty())
        return 0;

    int i = 0, n = s.length();

    // Step 1: Skip leading whitespace
    while (i < n && s[i] == ' ')
        i++;

    // Check if we've reached the end
    if (i == n)
        return 0;

    // Step 2: Check for sign
    int sign = 1;
    if (s[i] == '+')
        i++;
    else if (s[i] == '-')
    {
        sign = -1;
        i++;
    }

    // Step 3: Read digits and convert
    long long res = 0;
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        res = res * 10 + digit;

        if (sign * res <= INT_MIN)
            return INT_MIN;
        if (sign * res >= INT_MAX)
            return INT_MAX;
        i++;
    }

    // Step 4: Apply sign and return
    return static_cast<int>(res * sign);
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    cout << myAtoi(s) << endl;
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