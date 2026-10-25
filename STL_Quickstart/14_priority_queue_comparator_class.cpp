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

// supose you want to make a priotity queue of persons and they are standing on a bank line and you want to give priority according to their ages

class Person
{
public:
    string name;
    int age;

    Person() {} // Default constructor but it is not necessary to write it because if we don't write it then the compiler will automatically create a default constructor for us

    Person(string name, int age) // Parameterized constructor to initialize the name and age of the person
    {
        this->name = name;
        this->age = age;
    }
};

// Comparator class to compare the ages of the persons
class PersonCompare
{
public:
    bool operator()(Person const &p1, Person const &p2) // Overloading the () operator to compare the ages of the persons
    {
        cout<<"Comparing " << p1.age << " with " << p2.age << endl; // Print the ages of the persons being compared
        return p1.age < p2.age; // Return true if p1 is younger than p2, so that the person with the highest age will be at the top of the priority queue
    }
};

// Your code here
void Solve()
{
    int n;
    cin >> n;

    priority_queue<Person, vector<Person>, PersonCompare> pq; // A priority queue of persons, max heap by default, but we want to make a max heap according to the ages of the persons, so we need to make a comparator class and pass it to the priority queue

    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        Person p(name, age);
        // Now we want to make a priority queue of persons according to their ages
        // We can do this by making a comparator class and passing it to the priority queue
        // We will make a max-heap of persons according to their ages
        // So the person with the highest age will be at the top of the priority queue
        pq.push(p); // Insert the person into the priority queue O(logN)
    }
    // Printing top 3 oldest persons from the priority queue
    int k = 3;
    for (int i = 0; i < k; i++)
    {
        Person p = pq.top();
        cout << p.name << " " << p.age << endl; // Print the name and age of the person
        pq.pop();                               // Remove the person from the priority queue O(logN)
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