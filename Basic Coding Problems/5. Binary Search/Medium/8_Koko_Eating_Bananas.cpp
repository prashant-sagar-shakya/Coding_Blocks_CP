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

int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = INT_MIN;

    for (int i = 0; i < piles.size(); i++)
        maxi = max(maxi, piles[i]);

    int low = 1, high = maxi, ans = -1;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            if (piles[i] % mid == 0)
                time += piles[i] / mid;
            else
                time += (piles[i] / mid) + 1;
        }
        if (time <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// Your code here
void Solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
        cin >> piles[i];
    cout << minEatingSpeed(piles, h) << endl;
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