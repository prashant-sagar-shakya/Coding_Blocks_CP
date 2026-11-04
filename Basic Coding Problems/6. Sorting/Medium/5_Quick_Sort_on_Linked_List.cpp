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

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

pair<Node *, Node *> quickSort(Node *head)
{
    if (!head || !head->next)
        return {head, head};

    Node *ptr = head->next;

    Node *ptr1 = new Node(0); // Less than pivot
    Node *ptr2 = new Node(0); // Greater than pivot

    Node *prev = ptr1;
    Node *curr = ptr2;

    Node *tail = head; // Equal to pivot

    while (ptr)
    {
        if (ptr->data < head->data)
        {
            prev->next = ptr;
            prev = prev->next;
        }
        else if (ptr->data > head->data)
        {
            curr->next = ptr;
            curr = curr->next;
        }
        else
        {
            tail->next = ptr;
            tail = tail->next;
        }

        ptr = ptr->next;
    }

    prev->next = NULL;
    curr->next = NULL;

    auto left = quickSort(ptr1->next);
    auto right = quickSort(ptr2->next);

    if (left.second)
        left.second->next = head;

    tail->next = right.first;

    Node *sortedHead = left.first ? left.first : head;
    Node *sortedTail = right.second ? right.second : tail;

    delete ptr1;
    delete ptr2;

    return {sortedHead, sortedTail};
}

Node *sortList(Node *head)
{
    return quickSort(head).first;
}

// Your code here
void Solve()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = sortList(head);

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
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