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

/**
 * Approach: Stateful Single-Pass Top-Down Merge Sort
 *           (Cursor-Guided Divide and Conquer)
 *
 * Key Optimizations:
 *
 * 1. Zero-Traversal Splitting:
 *    Instead of using slow/fast pointers to find the middle,
 *    we maintain a global cursor (curr).
 *
 *    The left recursive call consumes exactly 'mid' nodes,
 *    automatically moving curr to the starting node of
 *    the right half.
 *
 * 2. Optimized Merge:
 *    No dummy node allocation is required.
 *    We directly initialize the sorted head and tail.
 *
 * 3. Minimal Recursion Parameters:
 *    Only the number of nodes (n) is passed recursively.
 *
 * Time Complexity:  O(N log N)
 * Space Complexity: O(log N) recursion stack
 */

Node *curr;

// Divide the linked list into two halves and sort recursively
Node *divideAndConquer(int n)
{

    // Base Case: Single node is already sorted
    if (n == 1)
    {
        Node *node = curr;
        curr = curr->next;
        node->next = NULL;
        return node;
    }
    int mid = n >> 1;
    // Sort left half
    Node *left = divideAndConquer(mid);
    // Sort right half
    Node *right = divideAndConquer(n - mid);
    // Merge both sorted halves
    return merge(left, right);
}

// Merge two sorted linked lists
Node *merge(Node *left, Node *right)
{

    Node *root;
    Node *prev;

    // Initialize root and tail using the smaller element
    if (left->data <= right->data)
    {
        root = prev = left;
        left = left->next;
    }
    else
    {
        root = prev = right;
        right = right->next;
    }

    // Merge while both lists have nodes
    while (left && right)
    {
        if (left->data <= right->data)
        {
            prev->next = left;
            prev = left;
            left = left->next;
        }
        else
        {
            prev->next = right;
            prev = right;
            right = right->next;
        }
    }
    // Attach remaining nodes
    prev->next = left ? left : right;

    return root;
}

Node *sortList(Node *head)
{
    // Base Case
    if (!head || !head->next)
        return head;

    // Count total nodes in linked list
    int n = 0;
    for (Node *ptr = head; ptr; ptr = ptr->next)
        n++;
    // Initialize global cursor
    curr = head;
    // Start Divide and Conquer
    return divideAndConquer(n);
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

    // Print sorted linked list
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