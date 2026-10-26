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

class Student
{
public:
    string firstname, lastname, rollno;

    Student(string f, string l, string no)
    {
        this->firstname = f;
        this->lastname = l;
        this->rollno = no;
    }

    bool operator==(const Student &s) const
    {
        return rollno == s.rollno;
    }
};

class HashFn
{
public:
    size_t operator()(const Student &s) const
    {
        return s.firstname.length() + s.lastname.length();
    }
};

// Your code here
void Solve()
{
    // In this map key is of a custom class, i.e, key is of user defined datatype
    // In this case what we've to do is:
    // 1. define our own hash function for the custom class
    // 2. overload the == operator because for better comparision

    unordered_map<Student, int, HashFn> student_mp;
    Student s1("Prashant", "Shakya", "2127984");
    Student s2("Sonu", "Kumar", "2127992");
    Student s3("Prashant", "Maurya", "2127987");
    Student s4("Vansh", "Bhandari", "2127997");

    // Add student marks to hashmap
    student_mp[s1] = 100;
    student_mp[s2] = 120;
    student_mp[s3] = 11;
    student_mp[s4] = 45;

    // Finding marks of a particular student (Student s3)
    cout << student_mp[s3] << endl;

    // Iterate over all students
    for (auto s : student_mp)
        cout << s.first.firstname << " " << s.first.lastname << " " << s.first.rollno << " " << s.second << " Marks\n";
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