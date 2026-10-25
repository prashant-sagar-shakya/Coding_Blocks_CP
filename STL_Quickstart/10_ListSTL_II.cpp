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
    list<int> d{1, 2, 3, 10, 14, 7};
    // Different Datatype
    list<string> l2{"Hello", "World", "C++", "Programming"};
    l2.push_back("STL");

    // sort
    d.sort(); // Sort the list in ascending order

    // reverse
    d.reverse(); // Reverse the order of elements in the list

    // pop
    d.pop_back();  // Remove the last element from the list
    d.pop_front(); // Remove the first element from the list

    // add at front of the list
    d.push_front(100);                            // Add 100 at the front of the list
    cout << d.front() << " " << d.back() << endl; // Print the first and last elements of the list
    d.pop_back();                                 // Remove the last element from the list

    // Iterate over the list and print the elements
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    // some more functions in list
    l2.push_back("orange");
    l2.push_back("banana");
    l2.push_back("lemon");

    for (auto &x : l2)
        cout << x << "-->";
    cout << endl;

    // remove a fruit
    string f;
    cin >> f;
    l2.remove(f); // Remove the fruit from the list

    for (auto &x : l2)
        cout << x << "-->";
    cout << endl;

    // erase one or more elements from the list
    auto it = l2.begin();
    advance(it, 2); // Move the iterator to the 3rd element
    l2.erase(it);   // Erase the 3rd element

    for (auto &x : l2)
        cout << x << "-->";
    cout << endl;

    // insert one or more elements in the list
    auto it2 = l2.begin();
    advance(it2, 1);          // Move the iterator to the 2nd element
    l2.insert(it2, "grapes"); // Insert "grapes" at the 2nd position

    for (auto &x : l2)
        cout << x << "-->";
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