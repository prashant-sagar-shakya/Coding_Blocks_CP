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

void countingSort(vector<int> &arr)
{
    int n = arr.size();

    if (n <= 1)
        return;

    // Find minimum and maximum elements
    int minNum = *min_element(arr.begin(), arr.end());
    int maxNum = *max_element(arr.begin(), arr.end());

    // Create frequency array
    int range = maxNum - minNum + 1;
    vector<int> count(range, 0);

    // Count frequency of each element
    for (int num : arr)
        count[num - minNum]++;

    // Reconstruct sorted array
    int idx = 0;

    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[idx++] = i + minNum;
            count[i]--;
        }
    }
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    countingSort(arr);
    for (const auto &i : arr)
        cout << i << " ";
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