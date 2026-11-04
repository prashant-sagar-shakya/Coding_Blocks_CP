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

vector<int> nextPalindrome(vector<int> &num)
{
    int n = num.size();
    vector<int> temp = num;

    // Step 1: Make palindrome by copying left to right
    for (int i = 0; i < n / 2; i++)
        temp[n - i - 1] = temp[i];

    // Step 2: If palindrome is already greater, return it
    if (temp > num)
        return temp;

    // Step 3: Increment the middle digit (handle carry)
    int i = (n - 1) / 2;
    while (i >= 0)
    {
        if (temp[i] < 9)
        {
            temp[i]++;
            break;
        }
        else
        {
            temp[i] = 0;
            i--;
        }
    }

    // Step 4: If all digits were 9 (e.g., 999 → 1001)
    if (i < 0)
    {
        vector<int> res(n + 1, 0);
        res[0] = res[n] = 1;
        return res;
    }

    // Step 5: Re-make palindrome after increment
    for (int i = 0; i < n / 2; i++)
        temp[n - i - 1] = temp[i];

    return temp;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    vector<int> result = nextPalindrome(num);
    for (int digit : result)
        cout << digit;
    cout << endl;
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