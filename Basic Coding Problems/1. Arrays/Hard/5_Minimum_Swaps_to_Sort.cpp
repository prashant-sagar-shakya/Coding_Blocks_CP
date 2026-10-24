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

int minSwaps(vector<int> &arr)
{
    // Code here
    map<int, int> mp;
    int n = arr.size();
    vector<int> correctOrder = arr;
    std::sort(correctOrder.begin(), correctOrder.end());
    for (int i = 0; i < n; i++)
        mp[arr[i]] = i;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (correctOrder[i] != arr[i])
        {
            int correctIndex = mp[correctOrder[i]];
            int wrongIndex = mp[arr[i]];
            mp[arr[i]] = correctIndex;
            mp[correctOrder[i]] = wrongIndex;
            swap(arr[i], arr[correctIndex]);
            count++;
        }
    }
    return count;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minSwaps(arr) << endl;
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