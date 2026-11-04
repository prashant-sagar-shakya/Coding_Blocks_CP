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

/*
    APPROACH: EXTERNAL MERGE SORT

    External Merge Sort is used when the complete dataset
    cannot fit into available RAM.

    PHASE 1: CREATE INITIAL SORTED RUNS
    1. Read runSize elements from input.txt into RAM.
    2. Sort them using Internal Merge Sort.
    3. Store the sorted chunk in a temporary file.
    4. Repeat until the complete input file is processed.

    PHASE 2: MULTI-PASS K-WAY MERGING
    1. Divide sorted runs into groups of at most K files.
    2. Read the first element from every file.
    3. Insert them into a Min Heap.
    4. Extract the minimum and write it to a new file.
    5. Read the next element from the same file.
    6. Repeat until all files in the group are exhausted.
    7. Continue merging passes until one sorted file remains.

    WHEN TO USE:
    1. Dataset is larger than available RAM.
    2. Sorting huge CSV/TXT files.
    3. Processing billions of records.
    4. Large database ORDER BY operations.
    5. Big Data processing and data engineering.

    COMPLEXITY:
    N = Total elements
    M = Elements fitting into RAM
    K = Merge fan-in

    Initial Sorting: O(N log M)
    Each Merge Pass: O(N log K)
    Number of Passes: O(log_K(N/M))
    RAM: O(M + K)

    Disk I/O is the major performance bottleneck.
*/

// --------------------------------------------------
// INTERNAL MERGE SORT
// --------------------------------------------------

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i = 0, j = 0, k = low;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < left.size())
        arr[k++] = left[i++];

    while (j < right.size())
        arr[k++] = right[j++];
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

// --------------------------------------------------
// MIN HEAP NODE
// --------------------------------------------------

struct MinHeapNode
{
    int element;
    int fileIndex;
};

// --------------------------------------------------
// MIN HEAP
// --------------------------------------------------

class MinHeap
{
    vector<MinHeapNode> harr;

    void heapify(int i)
    {
        int n = harr.size();
        int smallest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n &&
            harr[left].element < harr[smallest].element)
            smallest = left;

        if (right < n &&
            harr[right].element < harr[smallest].element)
            smallest = right;

        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(vector<MinHeapNode> &nodes) : harr(nodes)
    {
        for (int i = (int)harr.size() / 2 - 1; i >= 0; i--)
            heapify(i);
    }

    bool empty() const
    {
        return harr.empty();
    }

    MinHeapNode getMin() const
    {
        return harr[0];
    }

    void replaceMin(MinHeapNode node)
    {
        harr[0] = node;
        heapify(0);
    }

    void deleteMin()
    {
        harr[0] = harr.back();
        harr.pop_back();

        if (!harr.empty())
            heapify(0);
    }
};

// --------------------------------------------------
// PHASE 1: CREATE INITIAL SORTED RUNS
// --------------------------------------------------

vector<string> createInitialRuns(const string &inputFile, int runSize)
{
    ifstream in(inputFile);

    if (!in)
        throw runtime_error("Cannot open input.txt");

    vector<string> runs;
    vector<int> arr(runSize);

    int runId = 0;

    while (true)
    {
        int count = 0;

        while (count < runSize && in >> arr[count])
            count++;

        if (count == 0)
            break;

        // Sort current chunk
        mergeSort(arr, 0, count - 1);

        // Create temporary sorted run
        string fileName = "run_" + to_string(runId++) + ".txt";

        ofstream out(fileName);

        if (!out)
            throw runtime_error("Cannot create temporary file");

        for (int i = 0; i < count; i++)
            out << arr[i] << '\n';

        out.close();

        runs.push_back(fileName);
    }

    return runs;
}

// --------------------------------------------------
// K-WAY MERGE USING MIN HEAP
// --------------------------------------------------

void mergeKFiles(const vector<string> &inputFiles, const string &outputFile)
{
    vector<ifstream> files(inputFiles.size());
    vector<MinHeapNode> nodes;

    // Read first element from every sorted file
    for (int i = 0; i < inputFiles.size(); i++)
    {
        files[i].open(inputFiles[i]);

        if (!files[i])
            throw runtime_error("Cannot open temporary run");

        int value;

        if (files[i] >> value)
            nodes.push_back({value, i});
    }

    // Build Min Heap
    MinHeap hp(nodes);

    ofstream out(outputFile);

    if (!out)
        throw runtime_error("Cannot create merged file");

    // Extract minimum and replace with next element
    while (!hp.empty())
    {
        MinHeapNode root = hp.getMin();

        out << root.element << '\n';

        int nextValue;

        if (files[root.fileIndex] >> nextValue)
        {
            hp.replaceMin({nextValue, root.fileIndex});
        }
        else
        {
            hp.deleteMin();
        }
    }

    out.close();

    for (auto &file : files)
        file.close();
}

// --------------------------------------------------
// PHASE 2: MULTI-PASS K-WAY MERGING
// --------------------------------------------------

string mergePasses(vector<string> runs, int k)
{
    int pass = 0;

    while (runs.size() > 1)
    {
        vector<string> nextRuns;

        for (int i = 0; i < runs.size(); i += k)
        {
            vector<string> group;

            // Select at most K sorted files
            for (int j = i; j < min(i + k, (int)runs.size()); j++)
                group.push_back(runs[j]);

            string outputFile =
                "pass_" + to_string(pass) +
                "_run_" + to_string(nextRuns.size()) + ".txt";

            // Merge current group
            mergeKFiles(group, outputFile);

            nextRuns.push_back(outputFile);

            // Delete consumed temporary files
            for (const string &file : group)
                remove(file.c_str());
        }

        runs = move(nextRuns);
        pass++;
    }

    return runs.empty() ? "" : runs[0];
}

// --------------------------------------------------
// COMPLETE EXTERNAL MERGE SORT
// --------------------------------------------------

void externalMergeSort(const string &inputFile, const string &outputFile, int runSize, int k)
{
    if (runSize <= 0 || k < 2)
        throw invalid_argument("Invalid run size or merge fan-in");

    // Step 1: Create initial sorted runs
    vector<string> runs = createInitialRuns(inputFile, runSize);

    // Handle empty input
    if (runs.empty())
    {
        ofstream out(outputFile);
        return;
    }

    // Step 2: Perform multiple K-way merge passes
    string finalRun = mergePasses(runs, k);

    // Step 3: Move final sorted run to output.txt
    if (rename(finalRun.c_str(), outputFile.c_str()) != 0)
    {
        ifstream in(finalRun, ios::binary);
        ofstream out(outputFile, ios::binary);

        if (!in || !out)
            throw runtime_error("Final output operation failed");

        out << in.rdbuf();

        in.close();
        out.close();

        remove(finalRun.c_str());
    }
}

// Your code here
void Solve()
{
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    int runSize = 1000;
    int k = 10;

    try
    {
        externalMergeSort(
            inputFile,
            outputFile,
            runSize,
            k);

        cout << "External Merge Sort Completed!" << endl;
        cout << "Sorted output written to: " << outputFile << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
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