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

bool isPossible(vector<int> &boards, int k, int maxTime)
{
    int boardSum = 0, painterCount = 1;

    for (int i = 0; i < boards.size(); i++)
    {
        if (boardSum + boards[i] <= maxTime)
            boardSum += boards[i];
        else
        {
            painterCount++;

            if (painterCount > k || boardSum > maxTime)
                return false;

            boardSum = boards[i];
        }
    }

    return true;
}

int minTime(vector<int> &boards, int k)
{
    if (k > boards.size())
        return -1;

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int minTime = -1;

    while (low <= high)
    {
        int maxTime = low + (high - low) / 2;

        if (isPossible(boards, k, maxTime))
        {
            minTime = maxTime;
            high = maxTime - 1;
        }
        else
            low = maxTime + 1;
    }
    return minTime;
}

// Your code here
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> boards(n);
    for (int i = 0; i < n; i++)
        cin >> boards[i];
    cout << minTime(boards, k) << endl;
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