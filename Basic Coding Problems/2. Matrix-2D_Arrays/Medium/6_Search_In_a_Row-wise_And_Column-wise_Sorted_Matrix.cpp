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

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n = matrix.size();
    int start = 0, end = n * n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / n][mid % n];

        if (element == x)
            return {mid / n, mid % n};
        else if (element < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return {-1, -1};
}

// Your code here
void Solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    pair<int, int> ans = search(matrix, x);
    cout << ans.first << " " << ans.second << endl;
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