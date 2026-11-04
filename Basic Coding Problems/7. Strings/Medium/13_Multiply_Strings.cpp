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

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    // Reverse num1 and num2.
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // Initialize ans as a string of zeros of length N.
    int N = num1.size() + num2.size();
    string ans(N, '0');

    for (int place2 = 0; place2 < num2.size(); place2++)
    {
        int digit2 = num2[place2] - '0';
        // For each digit in num2 multiply the digit by all digits in num1.
        for (int place1 = 0; place1 < num1.size(); place1++)
        {
            int digit1 = num1[place1] - '0';

            // The number of zeros from multiplying to digits depends on the
            // place of digit2 in num2 and the place of the digit1 in num1.
            int numZeros = place1 + place2;

            // The digit currently at position numZeros in the ans string
            // is carried over and summed with the current result.
            int carry = ans[numZeros] - '0';
            int multiplication = digit1 * digit2 + carry;

            // Set the ones place of the multiplication result.
            ans[numZeros] = (multiplication % 10) + '0';

            // Carry the tens place of the multiplication result by
            // adding it to the next position in the ans array.
            ans[numZeros + 1] += (multiplication / 10);
        }
    }

    if (ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

// Your code here
void Solve()
{
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2) << endl;
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