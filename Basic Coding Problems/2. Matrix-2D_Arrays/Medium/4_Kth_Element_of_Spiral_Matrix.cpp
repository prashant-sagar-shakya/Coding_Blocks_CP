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

int findKthElement(vector<vector<int>> matrix, int k)
{
    int n = matrix.size(), m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int count = 0;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            count++;
            if (count == k)
                return matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            count++;
            if (count == k)
                return matrix[i][right];
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                count++;
                if (count == k)
                    return matrix[bottom][i];
            }
            bottom--;
        }
        if (left <= right)
            for (int i = bottom; i >= top; i--)
            {
                count++;
                if (count == k)
                    return matrix[i][left];
            }
        left++;
    }
    return -1;
}

// Your code here
void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    cout << findKthElement(matrix, k) << endl;
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