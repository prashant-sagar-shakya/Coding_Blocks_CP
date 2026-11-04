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

void bucketSort(vector<float> &arr)
{
    int n = arr.size();

    if (n <= 1)
        return;

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        int idx = n * arr[i];
        buckets[idx].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Merge all buckets into original array
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (float num : buckets[i])
            arr[idx++] = num;
    }
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<float> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bucketSort(arr);

    for (float num : arr)
        cout << num << " ";
    cout << endl;
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