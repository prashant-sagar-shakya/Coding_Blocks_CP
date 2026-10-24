// =======================THIS PROBLEM IS ALSO KNOWN AS N/3 REPEATED ELEMENTS IN ARRAY=========================

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

vector<int> majorityElement(vector<int> &nums)
{
    int count1 = 0, count2 = 0;
    int candidate1 = 0, candidate2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count1 == 0 && nums[i] != candidate2)
            count1 = 1, candidate1 = nums[i];
        else if (count2 == 0 && nums[i] != candidate1)
            count2 = 1, candidate2 = nums[i];
        else if (candidate1 == nums[i])
            count1++;
        else if (candidate2 == nums[i])
            count2++;
        else
            count1--, count2--;
    }

    vector<int> result;
    int threshold = nums.size() / 3;

    count1 = 0, count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (candidate1 == nums[i])
            count1++;
        else if (candidate2 == nums[i])
            count2++;
    }

    if (count1 > threshold)
        result.push_back(candidate1);

    if (count2 > threshold)
        result.push_back(candidate2);

    return result;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> result = majorityElement(arr);
    for (int &i : result)
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