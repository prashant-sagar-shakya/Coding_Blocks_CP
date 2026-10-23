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

// char *strtok(char *s, const char *delimeters)
// returns a token on each subsequent call
// on the first call function should be passed with string argument for 's'
// on subsequent calls we should pass the string argument as NULL

// Your code here
void Solve()
{
    char s[100]= "Hello, World! Welcome to C++ programming.";
    char *ptr = strtok(s, " "); // Tokenize the string based on the delimiters
    while(ptr != NULL) // Continue until there are no more tokens
    {
        cout<< ptr << endl; // Print the token
        ptr = strtok(NULL, " "); // Get the next token
    }
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}