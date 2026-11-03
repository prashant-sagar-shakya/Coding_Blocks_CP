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

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int required = (n * m) / 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        if (count <= required)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Your code here
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    cout << getMedian(matrix) << endl;
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