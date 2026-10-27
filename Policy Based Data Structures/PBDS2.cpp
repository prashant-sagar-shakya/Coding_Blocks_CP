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
    ordered_set<int> st;
    st.insert(15);
    st.insert(3);
    st.insert(10);
    st.insert(4);
    st.insert(1);
    st.insert(1);

    for (int i = 0; i < st.size(); i++)
        cout << i << " " << *st.find_by_order(i) << endl;

    // if the element is not present in the set then also it will decide where the element will go at which index
    cout << st.order_of_key(5) << endl;

    // Inserting a pair
    ordered_set<pair<int, int>> s;
    // A pair is {value, index}
    s.insert({15, 0});
    s.insert({3, 1});
    s.insert({10, 2});
    s.insert({10, 6});
    s.insert({10, 7});
    s.insert({4, 3});
    s.insert({1, 4});
    s.insert({1, 5});

    for (int i = 0; i < s.size(); i++)
        cout << i << " " << s.find_by_order(i)->first << " " << s.find_by_order(i)->second << endl;
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