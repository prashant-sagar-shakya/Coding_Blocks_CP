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
    // A map is a associative container that store mapping between key and the value pairs
    // insert() - to insert a key value pair in the map
    // find() - to find a key in the map and return an iterator to the key value pair if found else return end() iterator
    // erase() - to erase a key value pair from the map

    // A map maintains a self balancing BST, ordering is determined by the key type, and the keys are always sorted in ascending order by default. The time complexity of insert(), find() and erase() is O(log n) where n is the number of key value pairs in the map.

    map<string, int> mp; // A map of string and int type to store the name and age of the persons
    // Insert
    mp.insert(make_pair("Alice", 25)); // Insert a key value pair in the map
    pair<string, int> p;
    p.first = "Bob"; // Create a pair of string and int type to store the name and age of the person
    p.second = 30;
    mp.insert(p);       // Insert the pair in the map
    mp["Charlie"] = 35; // Insert a key value pair in the map using the [] operator

    // Search
    string name;
    cin >> name;             // Input the name of the person to search in the map
    auto it = mp.find(name); // Find the name in the map and return an iterator
    if (it != mp.end())
        cout << "Age of " << name << " is " << it->second << endl;
    else
        cout << "Person not found" << endl;

    // Another way to find a particular map
    // it stores unique keys only once
    if (mp.count(name))                                          // Count the number of occurrences of the name in the map and returns the integer
        cout << "Age of " << name << " is " << mp[name] << endl; // If found, print the age of the person
    else
        cout << "Person not found" << endl; // If not found, print person not found

    // Erase
    mp.erase(name); // Erase the key value pair from the map using the name as the key

    // Updating ages of persons
    // 1. Using [] operator (directly assigns or increments/modifies value)
    mp["Alice"] += 5;   // Increment age of Alice by 5
    mp["Charlie"] = 40; // Directly assign new age to Charlie

    // 2. Using iterator returned by find() (updates only if key exists)
    auto it_update = mp.find("Bob");
    if (it_update != mp.end())
    {
        it_update->second = 32; // Update Bob's age using iterator
    }

    for (auto it : mp)
        cout << it.first << " " << it.second << endl;
    // or, we can also use iterator to iterate over the map
    for (auto it = mp.begin(); it != mp.end(); it++)
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