#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> separateNegativeAndPositive(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (arr[i] < 0)
            i++;
        else if (arr[j] >= 0)
            j--;
        else
            swap(arr[i], arr[j]);
    }

    return arr;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    vector<int> ans = separateNegativeAndPositive(arr);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}