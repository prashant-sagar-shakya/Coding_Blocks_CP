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

// Your code here
void Solve()
{
    // In maps every key must be unique but in multimap multiple elements can have same key
    multimap<char, string> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        string s;
        cin >> ch >> s;
        m.insert(make_pair(ch, s));
    }

    // a angry
    // b batman
    // b boat
    // c cat
    // d dog
    // e elephant

    // Erasing the first element from multimap
    auto it1 = m.begin();
    m.erase(it1);

    // Lower bound will return an iterator pointing to the first element which is greater than or equal to the key
    auto it2 = m.lower_bound('b');
    cout << it2->first << " " << it2->second << endl;

    // Upper bound will return an iterator pointing to the first element which is strictly greater than the key
    auto it3 = m.upper_bound('d');
    cout << it3->first << " " << it3->second << endl;

    // search for cat
    auto f = m.find('c');
    if (f->second == "cat")
        m.erase(f);

    // Try to print the entire map
    cout << "====================================================\n";
    for (auto p : m)
        cout << p.first << " " << p.second << endl;
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