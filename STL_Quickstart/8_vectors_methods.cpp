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
    vector<int> d{1, 2, 3, 10, 14};
    // push_back() method adds an element to the end of the vector
    d.push_back(20);

    for (auto &x : d)
    {
        cout << x << " ";
    }
    cout << endl;

    // pop_back() method removes the last element from the vector
    d.pop_back();

    for (auto &x : d)
    {
        cout << x << " ";
    }
    cout << endl;

    // insert() method inserts an element at a specific position in the vector
    d.insert(d.begin() + 2, 100); // Insert 100 at index

    for (auto &x : d)
    {
        cout << x << " ";
    }
    cout << endl;

    // erase() method removes an element from a specific position in the vector
    d.erase(d.begin() + 1); // Remove element at index 1

    for (auto &x : d)
    {
        cout << x << " ";
    }
    cout << endl;

    // clear() method removes all elements from the vector
    d.clear();

    cout << d.size() << endl;     // Output the size of vector d
    cout << d.capacity() << endl; // Output the capacity of vector d
    cout << endl;

    // resize() method changes the size of the vector but the capacity remains the same, if the size is increrased then more memory is allocated to the vector and if the size is decreased then the extra elements are removed from the vector but the capacity remains the same
    d.resize(5); // Change size to 5
    cout << d.size() << endl;     // Output the size of vector d
    cout << d.capacity() << endl; // Output the capacity of vector d

    cout<<boolalpha<<d.empty()<<endl; // Output whether vector d is empty or not

    // frontmost element of the vector can be accessed using front() method and the lastmost element of the vector can be accessed using back() method
    cout<<d.front()<<endl; // Output the frontmost element of vector d

    // back() method returns the lastmost element of the vector
    cout<<d.back()<<endl; // Output the lastmost element of vector d

    // Reserve() method increases the capacity of the vector to a specified value but does not change the size of the vector
    d.reserve(10); // Increase capacity to 10
    cout << d.capacity() << endl; // Output the updated capacity of vector d
    cout << endl;
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}