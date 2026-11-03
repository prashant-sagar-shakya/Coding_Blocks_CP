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

vector<vector<int>> sumOfKxKMatrices(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    int m = arr[0].size();

    if (k == 1)
        return arr;
    if (k > n || k > m)
        return {};

    vector<vector<long long>> colSum(n, vector<long long>(m, 0));

    // Calculate vertical sliding window sums
    for (int j = 0; j < m; j++)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i][j];
            if (i >= k)
                sum -= arr[i - k][j];
            if (i >= k - 1)
                colSum[i - k + 1][j] = sum;
        }
    }

    vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
    // Calculate horizontal sliding window sums
    for (int i = 0; i < n - k + 1; i++)
    {
        long long sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += colSum[i][j];
            if (j >= k)
                sum -= colSum[i][j - k];
            if (j >= k - 1)
                ans[i][j - k + 1] = (int)sum;
        }
    }
    return ans;
}

// Your code here
void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector<vector<int>> result = sumOfKxKMatrices(arr, k);
    for (const auto &row : result)
    {
        for (const auto &val : row)
            cout << val << " ";
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