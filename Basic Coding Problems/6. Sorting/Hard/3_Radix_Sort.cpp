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

void radixSort(vector<int> &arr)
{
    int n = arr.size();

    if (n <= 1)
        return;

    int maxNum = *max_element(arr.begin(), arr.end());

    // Sort elements digit by digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
    {

        vector<int> output(n);
        int count[10] = {0};

        // Count frequency of each digit
        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Calculate cumulative frequency
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build output array (stable sorting)
        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }
        // Copy sorted elements back
        arr = output;
    }
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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