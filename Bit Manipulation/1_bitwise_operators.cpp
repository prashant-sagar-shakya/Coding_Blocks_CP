#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Your code here
void Solve()
{
    // Six type of operators
    // Biwise AND (&): if both bits are set then only it returns a set bit
    // Bitwise OR (|): either any of one bit is set it will return set bit
    // Bitwise NOT (~): ~x = -(x + 1)
    // Bitwise XOR (^): if bboth bits are opposite then it will return a set bit otherwise unset bit
    // Bitwise Left shift (<<): x << p = x * pow(2, p)
    // Bitwise Right Shift (>>): x >> p = x / pow(2, p)
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}