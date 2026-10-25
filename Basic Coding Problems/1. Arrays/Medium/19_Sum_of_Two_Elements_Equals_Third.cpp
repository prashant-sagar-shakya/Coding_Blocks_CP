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

#include <bits/stdc++.h>

vector<int> findTriplets(vector<int> &arr, int n)
{
    vector<int> res;
    sort(arr.begin(), arr.end());
    for (int i = n - 1; i >= 0; i--)
    {
        int j = 0, k = i - 1;
        while (j < k)
        {
            if (arr[i] == arr[j] + arr[k])
            {
                res.push_back(arr[i]);
                res.push_back(arr[j]);
                res.push_back(arr[k]);
                return res;
            }
            else if (arr[i] > arr[j] + arr[k])
                j++;
            else
                k--;
        }
    }
    return res;
}

// Your code here
void Solve()
{
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