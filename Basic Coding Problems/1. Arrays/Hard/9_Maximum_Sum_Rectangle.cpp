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

int maxSumRectangle(vector<vector<int>> &arr, int n, int m)
{
    int res = INT_MIN;
    for (int c1 = 0; c1 < m; c1++)
    {
        vector<int> temp(n, 0);
        for (int c2 = c1; c2 < m; c2++)
        {
            int maxi = INT_MIN;
            int s = 0;
            for (int row = 0; row < n; row++)
            {
                temp[row] += arr[row][c2];
                s += temp[row];
                maxi = max(maxi, s);
                s = max(s, 0);
            }
            res = max(maxi, res);
        }
    }
    return res;
}

// Your code here
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << maxSumRectangle(arr, n, m);
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