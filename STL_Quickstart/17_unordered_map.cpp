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
    // A unordered map is a associative container that store unordered mapping between key and the value pairs
    // insert() - to insert a key value pair in the unordered map
    // find() - to find a key in the unordered map and return an iterator to the key value pair if found else return end() iterator
    // erase() - to erase a key value pair from the unordered map

    // A unordered map maintains a self balancing BST, ordering is determined by the key type, and the keys are always sorted in ascending order by default. The time complexity of insert(), find() and erase() is O(log n) where n is the number of key value pairs in the unordered map.

    unordered_map<string, int> um; // A unordered map of string and int type to store the name and age of the persons
    // Insert
    um.insert(make_pair("Alice", 25)); // Insert a key value pair in the unordered map
    pair<string, int> p;
    p.first = "Bob"; // Create a pair of string and int type to store the name and age of the person
    p.second = 30;
    um.insert(p);       // Insert the pair in the unordered map
    um["Charlie"] = 35; // Insert a key value pair in the unordered map using the [] operator

    // Search
    string name;
    cin >> name;             // Input the name of the person to search in the unordered map
    auto it = um.find(name); // Find the name in the unordered map and return an iterator
    if (it != um.end())
        cout << "Age of " << name << " is " << it->second << endl;
    else
        cout << "Person not found" << endl;

    // Another way to find a particular unordered map
    // it stores unique keys only once
    if (um.count(name))                                          // Count the number of occurrences of the name in the unordered map and returns the integer
        cout << "Age of " << name << " is " << um[name] << endl; // If found, print the age of the person
    else
        cout << "Person not found" << endl; // If not found, print person not found

    // Erase
    um.erase(name); // Erase the key value pair from the unordered map using the name as the key

    // Updating ages of persons
    // 1. Using [] operator (directly assigns or increments/modifies value)
    um["Alice"] += 5;   // Increment age of Alice by 5
    um["Charlie"] = 40; // Directly assign new age to Charlie

    // 2. Using iterator returned by find() (updates only if key exists)
    auto it_update = um.find("Bob");
    if (it_update != um.end())
    {
        it_update->second = 32; // Update Bob's age using iterator
    }

    for (auto it : um)
        cout << it.first << " " << it.second << endl;
    // or, we can also use iterator to iterate over the unordered map
    for (auto it = um.begin(); it != um.end(); it++)
        cout << it->first << " " << it->second << endl;
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