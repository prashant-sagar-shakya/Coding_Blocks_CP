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
    string s0;
    string s1("Hello, World!");
    string s2("Hello, C++!");
    string s3(s1); // Copy constructor
    char a[] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};
    string s4(a); // Constructor from char array

    cout << s4 << endl;
    cout << boolalpha << (s0.empty()) << endl; // Check if string is empty
    s1.append(" How are you?");                // Append string
    cout << s1 << endl;
    s2.clear(); // Clear string
    cout << s2 << endl;
    cout << s1.compare(s3) << endl;                // Compare strings
    cout << s1.find("World") << endl;              // Find substring
    cout << s1.erase(s1.find("World"), 7) << endl; // Erase substring

    // Iterate through string
    for (char c : s1)
    {
        cout << c << " ";
    }

    cout << endl;
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
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