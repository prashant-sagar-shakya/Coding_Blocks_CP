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

double findMedianSortedArrays(vector<int> &n1, vector<int> &n2)
{
    double k;
    for (int i = 0; i < n2.size(); i++)
        n1.push_back(n2[i]);
    sort(n1.begin(), n1.end());
    double k1 = n1[n1.size() / 2];
    double k2 = n1[(n1.size() - 1) / 2];
    if (n1.size() % 2 != 0)
        k = k1;
    else
        k = k1 + (k2 - k1) / 2;
    return k;
}

// Your code here
void Solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];
    cout << findMedianSortedArrays(nums1, nums2) << endl;
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