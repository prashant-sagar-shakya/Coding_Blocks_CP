<div align="center">

# ⚡ Data Structures & Algorithms Problem Vault
### 🎯 *Curated, Pattern-Oriented Problem Solving & Interview Handbook in C++*

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%2F20-blue.svg?style=for-the-badge&logo=c%2B%2B)](https://en.cppreference.com/)
[![Curriculum](https://img.shields.io/badge/Curriculum-11%20Core%20Domains-orange.svg?style=for-the-badge)](./)
[![Difficulty](https://img.shields.io/badge/Difficulty-Easy%20%7C%20Medium%20%7C%20Hard-purple.svg?style=for-the-badge)](./)
[![Complexity](https://img.shields.io/badge/Complexity-Optimal%20Time%20%26%20Space-brightgreen.svg?style=for-the-badge)](./)
[![Architecture](https://img.shields.io/badge/Design-Pattern--Based-yellow.svg?style=for-the-badge)](./)

<p align="center">
  <b>A comprehensive, self-contained reference repository designed to build deep algorithmic intuition, understand core interview patterns, and master time & space complexities.</b>
</p>

[📌 Topic Index](#-topic-index--quick-navigation) • [🗺️ Learning Flow](#%EF%B8%8F-learning-roadmap) • [📚 Problem Directory](#-curated-problem-directory) • [🧠 Pattern Playbook](#-essential-algorithmic-patterns--templates) • [⏱️ Complexity Guide](#%EF%B8%8F-time--space-complexity-cheat-sheet) • [🚀 How to Run](#-how-to-compile--run)

---
</div>

## 📌 Topic Index & Quick Navigation

| # | Topic Domain | Category | Core Algorithmic Patterns | Quick Link |
| :-: | :--- | :--- | :--- | :---: |
| **01** | **Arrays** | Linear Data Structure | Prefix Sum, Kadane's, Dutch National Flag, Two Pointers | [View Module](#1-arrays) |
| **02** | **Matrix / 2D Arrays** | Multi-dimensional Arrays | Spiral Order, In-place 90° Rotation, Matrix Binary Search | [View Module](#2-matrix--2d-arrays) |
| **03** | **Two Pointers** | Algorithmic Paradigm | Opposite Direction, Slow & Fast (Floyd's Cycle), Squeezing | [View Module](#3-two-pointers--slow--fast-pointers) |
| **04** | **Sliding Window** | Subarray / Substring Pattern | Fixed Size Window, Dynamic Window, Frequency Map Window | [View Module](#4-sliding-window) |
| **05** | **Binary Search** | Divide & Conquer / Search Space | Lower/Upper Bound, Rotated Array Search, Binary Search on Answer | [View Module](#5-binary-search) |
| **06** | **Sorting** | Ordering & Partitioning | Divide & Conquer, Partition Schemes, Min/Max Heap, Counting Sort | [View Module](#6-sorting) |
| **07** | **Strings** | Sequence Processing | Palindrome Expansion, Character Hashing, Anagram Matching, KMP | [View Module](#7-strings) |
| **08** | **Stack & Queue** | Linear Abstract Data Types | Monotonic Stack, Next Greater Element, Dual-Stack Queue | [View Module](#8-stack--queue) |
| **09** | **Linked List** | Pointer-based Structures | In-place Reversal, Tortoise & Hare, Merge Sort on LL | [View Module](#9-linked-list) |
| **10** | **Binary Trees** | Hierarchical Tree Structure | DFS (Pre/In/Postorder), BFS (Level Order), Diameter, LCA, Views | [View Module](#10-binary-trees) |
| **11** | **Binary Search Tree (BST)** | Ordered Search Trees | BST Invariant, LCA in BST, BST Deletion & Range Operations | [View Module](#11-binary-search-tree-bst) |

---

## 📚 Curated Problem Directory

### 1. Arrays

> **Intuition:** Arrays provide $O(1)$ random access by index. Optimizing brute-force array algorithms from $O(N^2) \to O(N)$ relies on prefix sums, frequency hashing, sliding markers, and Kadane's dynamic programming.

<details open>
<summary><b>Click to expand / collapse Arrays Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Largest & Smallest Element in Array | 🟢 Easy | Single Pass Linear Scan | $O(N)$ | $O(1)$ |
| 02 | Second Largest Element | 🟢 Easy | Two Variables Single Pass | $O(N)$ | $O(1)$ |
| 03 | Sum Between Indices i and j | 🟢 Easy | Prefix Sum Array | $O(1)$ query | $O(N)$ |
| 04 | Rotate Array by K Elements | 🟢 Easy | Reversal Algorithm | $O(N)$ | $O(1)$ |
| 05 | Sort 0s, 1s, and 2s | 🟢 Easy | Dutch National Flag (3-Way) | $O(N)$ | $O(1)$ |
| 06 | Check Non-Decreasing Array | 🟢 Easy | Greedy / Boundary Check | $O(N)$ | $O(1)$ |
| 07 | Equilibrium Index of an Array | 🟢 Easy | Total Sum - Running Sum | $O(N)$ | $O(1)$ |
| 08 | Remove Duplicates from Sorted Array | 🟢 Easy | Two Pointers (In-place) | $O(N)$ | $O(1)$ |
| 09 | Remove Duplicates from Unsorted Array | 🟢 Easy | Hash Set Tracking | $O(N)$ | $O(N)$ |
| 10 | Two Sum (Target Sum Pair) | 🟢 Easy | Unordered Hash Map | $O(N)$ | $O(N)$ |
| 11 | Pair Sum With Closest Value | 🟢 Easy | Sorting + Two Pointers | $O(N \log N)$ | $O(1)$ |
| 12 | Check if Array is Palindrome | 🟢 Easy | Two Pointers Squeeze | $O(N)$ | $O(1)$ |
| 13 | Reverse Array In-Place | 🟢 Easy | Two Pointers Swapping | $O(N)$ | $O(1)$ |
| 14 | Find Missing Number ($1$ to $N$) | 🟢 Easy | Gauss Sum Formula / XOR | $O(N)$ | $O(1)$ |
| 15 | Count Frequency of Elements | 🟢 Easy | Unordered Map Counting | $O(N)$ | $O(N)$ |
| 16 | Move Zeroes to End | 🟢 Easy | Read/Write Pointers | $O(N)$ | $O(1)$ |
| 17 | Move Negative Numbers to Start | 🟢 Easy | Partition Scheme | $O(N)$ | $O(1)$ |
| 18 | Make Unique Array | 🟢 Easy | Sorting + Greedy Increment | $O(N \log N)$ | $O(1)$ |
| 19 | Check if Array is Subset of Another | 🟢 Easy | Frequency Map / Hashing | $O(N + M)$ | $O(N)$ |
| 20 | Subarray Sum Equals K | 🟡 Medium | Prefix Sum + Hash Map | $O(N)$ | $O(N)$ |
| 21 | Longest Subarray With Sum K | 🟡 Medium | Prefix Sum + Earliest Index | $O(N)$ | $O(N)$ |
| 22 | Count All Subarrays With Given Sum | 🟡 Medium | Prefix Map Accumulator | $O(N)$ | $O(N)$ |
| 23 | Longest Subarray With Zero Sum | 🟡 Medium | Prefix Sum Map | $O(N)$ | $O(N)$ |
| 24 | Subarrays Having Sum Divisible by K | 🟡 Medium | Modulo Prefix Remainder | $O(N)$ | $O(K)$ |
| 25 | Maximum Subarray Sum (Kadane's) | 🟡 Medium | Dynamic Programming / Kadane | $O(N)$ | $O(1)$ |
| 26 | Merge Overlapping Intervals | 🟡 Medium | Interval Sorting + Sweep | $O(N \log N)$ | $O(N)$ |
| 27 | Rearrange Positives & Negatives | 🟡 Medium | Alternate Index Placement | $O(N)$ | $O(N)$ |
| 28 | Next Permutation | 🟡 Medium | Pivot Detection & Swap | $O(N)$ | $O(1)$ |
| 29 | Stock Buy and Sell (Multi Transaction) | 🟡 Medium | Peak Valley / Greedy Sum | $O(N)$ | $O(1)$ |
| 30 | Stock Buy and Sell (Single Transaction) | 🟡 Medium | Running Minimum Tracking | $O(N)$ | $O(1)$ |
| 31 | Leaders in an Array | 🟡 Medium | Right-to-Left Traversal | $O(N)$ | $O(1)$ |
| 32 | Trapping Rainwater (1D) | 🟡 Medium | Prefix Max / Suffix Max | $O(N)$ | $O(1)$ |
| 33 | Product of Array Except Self | 🟡 Medium | Prefix & Suffix Products | $O(N)$ | $O(1)$ |
| 34 | Majority Element (Moore's Voting) | 🟡 Medium | Boyer-Moore Cancellation | $O(N)$ | $O(1)$ |
| 35 | Majority Element II ($N/3$ Repeated) | 🟡 Medium | Boyer-Moore (2 Candidates) | $O(N)$ | $O(1)$ |
| 36 | Maximum Sum Circular Subarray | 🟡 Medium | Total - MinSubarray Kadane | $O(N)$ | $O(1)$ |
| 37 | Max Subarray Sum After K Concatenations | 🟡 Medium | Extended Kadane Analysis | $O(N)$ | $O(1)$ |
| 38 | Repeat and Missing Number | 🟡 Medium | Math Formula / XOR Partition | $O(N)$ | $O(1)$ |
| 39 | Sum of Two Elements Equals Third | 🟡 Medium | Sort + Two Pointers | $O(N^2)$ | $O(1)$ |
| 40 | Closest Distance Pair | 🟡 Medium | Sorting & Neighbor Diff | $O(N \log N)$ | $O(1)$ |
| 41 | 4Sum Problem | 🟡 Medium | Sort + 2 Loops + 2 Pointers | $O(N^3)$ | $O(1)$ |
| 42 | Find the Duplicate Number | 🟡 Medium | Floyd's Cycle Detection | $O(N)$ | $O(1)$ |
| 43 | Maximum Product Subarray | 🔴 Hard | Min/Max DP State Swap | $O(N)$ | $O(1)$ |
| 44 | Longest Consecutive Sequence | 🔴 Hard | Hash Set Lookup ($O(1)$) | $O(N)$ | $O(N)$ |
| 45 | Median of Two Sorted Arrays | 🔴 Hard | Binary Search on Partitions | $O(\log(\min(N, M)))$ | $O(1)$ |
| 46 | Merge K Sorted Arrays | 🔴 Hard | Min-Heap Priority Queue | $O(N \cdot K \log K)$ | $O(K)$ |
| 47 | Count Inversions in Array | 🔴 Hard | Modified Merge Sort | $O(N \log N)$ | $O(N)$ |
| 48 | Minimum Swaps to Sort | 🔴 Hard | Graph Cycles Decomposition | $O(N \log N)$ | $O(N)$ |
| 49 | Maximum Sum Rectangle in 2D Matrix | 🔴 Hard | 2D Kadane Algorithm | $O(C^2 \cdot R)$ | $O(R)$ |

</details>

---

### 2. Matrix / 2D Arrays

> **Intuition:** 2D grid operations require coordinate mapping `(row, col)`, in-place index transformation without extra space, and boundary-bounded traversals.

<details>
<summary><b>Click to expand / collapse Matrix Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Check if Matrix is Symmetric | 🟢 Easy | $A[i][j] == A[j][i]$ Check | $O(N^2)$ | $O(1)$ |
| 02 | Spiral Order Traversal | 🟢 Easy | 4-Wall Boundary Squeeze | $O(M \cdot N)$ | $O(1)$ |
| 03 | Inplace Rotate Matrix by 90° Clockwise | 🟡 Medium | Transpose + Reverse Rows | $O(N^2)$ | $O(1)$ |
| 04 | Rotate Matrix to Right by K Steps | 🟡 Medium | Layer-by-layer Shift | $O(M \cdot N)$ | $O(M \cdot N)$ |
| 05 | Set Matrix Zeroes | 🟡 Medium | In-place Row/Col Marker Flags | $O(M \cdot N)$ | $O(1)$ |
| 06 | Nth Element of Spiral Matrix | 🟡 Medium | Mathematical Simulation | $O(M \cdot N)$ | $O(1)$ |
| 07 | Find All Subsquares of Size K | 🟡 Medium | 2D Prefix Sum Matrix | $O(M \cdot N)$ | $O(M \cdot N)$ |
| 08 | Search in Row & Col Sorted Matrix | 🟡 Medium | Staircase Search (Top-Right) | $O(M + N)$ | $O(1)$ |
| 09 | Matrix Median | 🔴 Hard | Binary Search on Value Range | $O(R \log(\text{range}) \log C)$ | $O(1)$ |

</details>

---

### 3. Two Pointers / Slow & Fast Pointers

> **Intuition:** Highly effective on sorted collections. By maintaining two pointers moving toward each other or at different speeds, redundant checks are eliminated to achieve linear time $O(N)$.

<details open>
<summary><b>Click to expand / collapse Two Pointers Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Reverse An Array | 🟢 Easy | Two Pointers Swap | $O(N)$ | $O(1)$ |
| 02 | Check Palindromic Array | 🟢 Easy | Outer-to-Inner Matching | $O(N)$ | $O(1)$ |
| 03 | Check Palindromic String | 🟢 Easy | Character Convergence | $O(N)$ | $O(1)$ |
| 04 | Two Sum in Sorted Array | 🟡 Medium | Squeeze Pointers Left/Right | $O(N)$ | $O(1)$ |
| 05 | Remove Duplicates from Sorted Array | 🟡 Medium | Slow & Fast Reader/Writer | $O(N)$ | $O(1)$ |
| 06 | Container With Most Water | 🟡 Medium | Greedy Shrinking Bound | $O(N)$ | $O(1)$ |
| 07 | Intersection of Two Sorted Arrays | 🟡 Medium | Parallel Pointer Traversal | $O(N + M)$ | $O(1)$ |
| 08 | 3Sum / 4Sum Problem | 🔴 Hard | Sorting + Fixed Outer + 2 Pointers | $O(N^2)$ | $O(1)$ |
| 09 | Linked List Cycle Detection | 🔴 Hard | Floyd's Tortoise & Hare | $O(N)$ | $O(1)$ |

</details>

---

### 4. Sliding Window

> **Intuition:** Converts nested subarray/substring lookups from $O(N \cdot K)$ to $O(N)$ by maintaining a dynamic or fixed window state (adding incoming elements on the right and shrinking invalid elements from the left).

<details open>
<summary><b>Click to expand / collapse Sliding Window Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Maximum Sum Subarray of Size K | 🟢 Easy | Fixed Window of Size K | $O(N)$ | $O(1)$ |
| 02 | Count Occurrence of Anagrams | 🟢 Easy | Frequency Map + Fixed Window | $O(N)$ | $O(26)$ |
| 03 | Longest Substring Without Repeating Chars | 🟡 Medium | Dynamic Window + Last Seen Map | $O(N)$ | $O(\min(N, \Sigma))$ |
| 04 | Minimum Size Subarray Sum ($\ge S$) | 🟡 Medium | Dynamic Window Shrink Condition | $O(N)$ | $O(1)$ |
| 05 | Longest Repeating Character Replacement | 🟡 Medium | Max Frequency in Window | $O(N)$ | $O(26)$ |
| 06 | Longest Substring with K Distinct Chars | 🟡 Medium | Hash Map Window Contraction | $O(N)$ | $O(K)$ |
| 07 | Minimum Window Substring | 🔴 Hard | Target Freq Counter + Shrinking | $O(N + M)$ | $O(\Sigma)$ |
| 08 | Sliding Window Maximum | 🔴 Hard | Monotonic Decreasing Deque | $O(N)$ | $O(K)$ |

</details>

---

### 5. Binary Search

> **Intuition:** Applicable beyond sorted arrays to any monotonic search space $f(x) \in \{\text{True}, \text{False}\}$. Binary Search on Answers enables solving complex optimization problems in logarithmic iterations.

<details open>
<summary><b>Click to expand / collapse Binary Search Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Binary Search (Iterative) | 🟢 Easy | Mid Calculation `l + (r-l)/2` | $O(\log N)$ | $O(1)$ |
| 02 | Binary Search (Recursive) | 🟢 Easy | Divide & Conquer Recursion | $O(\log N)$ | $O(\log N)$ |
| 03 | Lower Bound in Sorted Array | 🟢 Easy | First index $\ge \text{target}$ | $O(\log N)$ | $O(1)$ |
| 04 | Upper Bound in Sorted Array | 🟢 Easy | First index $> \text{target}$ | $O(\log N)$ | $O(1)$ |
| 05 | First Occurrence of Element | 🟢 Easy | Binary Search Left Shift | $O(\log N)$ | $O(1)$ |
| 06 | Last Occurrence of Element | 🟢 Easy | Binary Search Right Shift | $O(\log N)$ | $O(1)$ |
| 07 | Search in Rotated Sorted Array | 🟡 Medium | Half-Sorted Subarray Property | $O(\log N)$ | $O(1)$ |
| 08 | Find Peak Element | 🟡 Medium | Local Slope Condition | $O(\log N)$ | $O(1)$ |
| 09 | Square Root of Integer Using BS | 🟡 Medium | Monotonic Domain $[1, N]$ | $O(\log N)$ | $O(1)$ |
| 10 | Allocate Books (Painter's Partition) | 🟡 Medium | BS on Answer + Feasibility Check | $O(N \log(\sum A))$ | $O(1)$ |
| 11 | Aggressive Cows | 🟡 Medium | BS on Answer (Distance Space) | $O(N \log(\max - \min))$ | $O(1)$ |
| 12 | Nth Root of an Integer | 🟡 Medium | Power Check via Multiplication | $O(M \log N)$ | $O(1)$ |
| 13 | Find Minimum in Rotated Sorted Array | 🟡 Medium | Unsorted Boundary Search | $O(\log N)$ | $O(1)$ |
| 14 | Koko Eating Bananas | 🟡 Medium | Monotonic Speed Search | $O(N \log(\max A))$ | $O(1)$ |
| 15 | Find Kth Element in Two Sorted Arrays | 🔴 Hard | Subarray Boundary Partitioning | $O(\log(\min(N, M)))$ | $O(1)$ |

</details>

---

### 6. Sorting

> **Intuition:** Understanding the trade-offs between comparison sorts ($O(N \log N)$) and non-comparison distribution sorts ($O(N + K)$), as well as stability and in-place memory guarantees, is vital for algorithm design.

<details open>
<summary><b>Click to expand / collapse Sorting Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Bubble Sort | 🟢 Easy | Adjacent Swapping with Early Stop | $O(N^2)$ | $O(1)$ |
| 02 | Insertion Sort | 🟢 Easy | In-place Subarray Insertion | $O(N^2)$ | $O(1)$ |
| 03 | Selection Sort | 🟢 Easy | Minimum Element Selection | $O(N^2)$ | $O(1)$ |
| 04 | Merge Sort | 🟡 Medium | Divide & Conquer (Stable) | $O(N \log N)$ | $O(N)$ |
| 05 | Quick Sort | 🟡 Medium | Lomuto / Hoare Partition | $O(N \log N)$ avg | $O(\log N)$ |
| 06 | Heap Sort | 🟡 Medium | Binary Max-Heap Heapify | $O(N \log N)$ | $O(1)$ |
| 07 | Insertion Sort on Linked List | 🟡 Medium | Node Pointer Relinking | $O(N^2)$ | $O(1)$ |
| 08 | Quick Sort on Linked List | 🟡 Medium | Partitioning with Tail Pointers | $O(N \log N)$ | $O(\log N)$ |
| 09 | Counting Sort | 🔴 Hard | Non-Comparison Frequency Array | $O(N + K)$ | $O(K)$ |
| 10 | Bucket Sort | 🔴 Hard | Uniform Value Distribution | $O(N + K)$ avg | $O(N + K)$ |
| 11 | Radix Sort | 🔴 Hard | Digit-by-Digit Stable Sort | $O(D \cdot (N + B))$ | $O(N + B)$ |
| 12 | External Merge Sort | 🔴 Hard | K-Way File Stream Merging | $O(N \log(N/M))$ | $O(M)$ |

</details>

---

### 7. Strings

> **Intuition:** String problems frequently feature anagram verification, palindrome symmetry, substring search, and parsing. Optimal performance relies on character frequency tables (`int freq[26]`) and prefix matching (KMP).

<details open>
<summary><b>Click to expand / collapse Strings Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Check Palindrome String | 🟢 Easy | Two Pointers Squeeze | $O(N)$ | $O(1)$ |
| 02 | Remove Vowels & Spaces | 🟢 Easy | Character Filter Iteration | $O(N)$ | $O(1)$ |
| 03 | Find ASCII Value of Character | 🟢 Easy | Type Casting Inspection | $O(1)$ | $O(1)$ |
| 04 | Capitalize First & Last Character | 🟢 Easy | Token Boundary Detection | $O(N)$ | $O(1)$ |
| 05 | Find Frequency of Characters | 🟢 Easy | Hash Map / Table Count | $O(N)$ | $O(26)$ |
| 06 | Reverse Words and Characters | 🟢 Easy | In-place Word Reversals | $O(N)$ | $O(1)$ |
| 07 | Splitting String into Words | 🟢 Easy | Stringstream / Space Tokenizer | $O(N)$ | $O(N)$ |
| 08 | Reverse String Word Wise | 🟢 Easy | Two-Pass Reverse Strategy | $O(N)$ | $O(1)$ |
| 09 | First Non-Repeating Character | 🟢 Easy | Frequency Count + First Scan | $O(N)$ | $O(26)$ |
| 10 | Check Permutation (Anagram) | 🟢 Easy | Balance Array Counting | $O(N)$ | $O(26)$ |
| 11 | Longest Common Prefix | 🟡 Medium | Vertical Scan / Trie | $O(N \cdot M)$ | $O(1)$ |
| 12 | Longest Substring Without Repeating | 🟡 Medium | Sliding Window + Last Seen Map | $O(N)$ | $O(256)$ |
| 13 | Valid Anagram | 🟡 Medium | Character Balance Array | $O(N)$ | $O(26)$ |
| 14 | Group Anagrams | 🟡 Medium | Sorted Key Hash Map Grouping | $O(N \cdot K \log K)$ | $O(N \cdot K)$ |
| 15 | Reverse Words in a Sentence | 🟡 Medium | Clean In-place Double Reverse | $O(N)$ | $O(1)$ |
| 16 | Longest Palindromic Substring | 🟡 Medium | Expand Around Center | $O(N^2)$ | $O(1)$ |
| 17 | Count and Say Sequence | 🟡 Medium | Run-Length Recursive Expansion | $O(2^N)$ | $O(2^N)$ |
| 18 | String Encoding (Run-Length) | 🟡 Medium | Adjacent Match Counter | $O(N)$ | $O(1)$ |
| 19 | Beautiful Strings (Alternate 0/1) | 🟡 Medium | Parity Matching Count | $O(N)$ | $O(1)$ |
| 20 | Minimum Parentheses to Make Valid | 🟡 Medium | Balance Stack / Open-Close Count | $O(N)$ | $O(1)$ |
| 21 | Next Smallest Palindrome | 🟡 Medium | Mirror & Middle Increment | $O(N)$ | $O(1)$ |
| 22 | Find Kth Character in Decrypted String | 🟡 Medium | Cumulative Length Calculation | $O(N)$ | $O(1)$ |
| 23 | Multiply Strings (BigInt Arithmetic) | 🟡 Medium | Elementary Grade-School Math | $O(N \cdot M)$ | $O(N + M)$ |
| 24 | Check Subsequence | 🟡 Medium | Greedy Two Pointers | $O(N)$ | $O(1)$ |
| 25 | Sum of Zeroes in Binary Matrix | 🟡 Medium | 4-Directional Neighbor Check | $O(M \cdot N)$ | $O(1)$ |
| 26 | String to Integer (myAtoi) | 🟡 Medium | Clamping & Overflow Detection | $O(N)$ | $O(1)$ |
| 27 | Minimum Window Substring | 🔴 Hard | Dynamic Sliding Window + Map | $O(N + M)$ | $O(\Sigma)$ |
| 28 | KMP String Matching Algorithm | 🔴 Hard | Longest Prefix Suffix (LPS) Array | $O(N + M)$ | $O(M)$ |
| 29 | Regular Expression Matching | 🔴 Hard | 2D Dynamic Programming | $O(M \cdot N)$ | $O(M \cdot N)$ |
| 30 | Word Break Problem | 🔴 Hard | DP Substring Trie Verification | $O(N^2)$ | $O(N)$ |
| 31 | Edit Distance (Levenshtein) | 🔴 Hard | 2D Dynamic Programming (Insert/Del) | $O(M \cdot N)$ | $O(M \cdot N)$ |
| 32 | Min Operations to Make Strings Equal | 🔴 Hard | LCS / DP Transformation | $O(M \cdot N)$ | $O(M \cdot N)$ |

</details>

---

### 8. Stack & Queue

> **Intuition:** LIFO (Stack) and FIFO (Queue) structures manage evaluation orders. Monotonic stacks excel at finding "next greater/smaller element" in a single linear pass $O(N)$.

<details>
<summary><b>Click to expand / collapse Stack & Queue Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Implement Stack Using Array | 🟢 Easy | Fixed Array + Top Pointer | $O(1)$ per op | $O(N)$ |
| 02 | Implement Stack Using Linked List | 🟢 Easy | Push Front & Pop Front | $O(1)$ per op | $O(N)$ |
| 03 | Implement Queue Using Array/LL | 🟢 Easy | Head & Tail Pointer Updates | $O(1)$ per op | $O(N)$ |
| 04 | Reverse a Queue | 🟢 Easy | Auxiliary Stack / Recursion | $O(N)$ | $O(N)$ |
| 05 | Valid Parentheses Check | 🟢 Easy | Bracket Matching Stack | $O(N)$ | $O(N)$ |
| 06 | Implement Queue Using Two Stacks | 🟡 Medium | Amortized Transfer ($S_1 \to S_2$) | $O(1)$ amortized | $O(N)$ |
| 07 | Implement Stack Using Two Queues | 🟡 Medium | Element Rotation in Queue | $O(N)$ push / $O(1)$ pop | $O(N)$ |
| 08 | Min Stack (Retrieve Minimum in $O(1)$) | 🟡 Medium | Pair Stack / $2x - \text{min}$ Math | $O(1)$ per op | $O(N)$ |
| 09 | Next Greater Element | 🟡 Medium | Monotonic Decreasing Stack | $O(N)$ | $O(N)$ |
| 10 | Stock Span Problem | 🟡 Medium | Monotonic Stack Index Difference | $O(N)$ | $O(N)$ |
| 11 | Sort a Stack Using Recursion | 🟡 Medium | Sorted Insert Recursive Descent | $O(N^2)$ | $O(N)$ stack |
| 12 | Largest Rectangle in Histogram | 🔴 Hard | Monotonic Increasing Stack | $O(N)$ | $O(N)$ |
| 13 | Online Stock Span | 🔴 Hard | Stack of Monotonic Pairs | $O(1)$ amortized | $O(N)$ |

</details>

---

### 9. Linked List

> **Intuition:** Pointer-based linear data structures eliminate resizing overhead but lack direct indexing. Mastering pointer manipulation, dummy heads, and fast/slow pointer techniques is essential.

<details>
<summary><b>Click to expand / collapse Linked List Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Reverse a Singly Linked List | 🟢 Easy | 3-Pointers (`prev`, `curr`, `next`) | $O(N)$ | $O(1)$ |
| 02 | Find Middle Node in Linked List | 🟢 Easy | Tortoise & Hare (Fast/Slow) | $O(N)$ | $O(1)$ |
| 03 | Add Two Numbers Represented by LL | 🟢 Easy | Elementary Carry Addition | $O(\max(N, M))$ | $O(1)$ |
| 04 | Check if Linked List is Palindrome | 🟢 Easy | Find Mid + Reverse Half + Compare | $O(N)$ | $O(1)$ |
| 05 | Merge Two Sorted Linked Lists | 🟢 Easy | Dummy Head + 2 Pointers | $O(N + M)$ | $O(1)$ |
| 06 | Insertion Sort on Linked List | 🟡 Medium | Pointer Splice into Sorted List | $O(N^2)$ | $O(1)$ |
| 07 | Delete K-th Node From End of List | 🟡 Medium | Two Pointers with K-Step Offset | $O(N)$ | $O(1)$ |
| 08 | Detect & Remove Cycle in LL | 🟡 Medium | Floyd's Loop + Origin Reset | $O(N)$ | $O(1)$ |
| 09 | Swap Nodes in Pairs | 🟡 Medium | Pointer Re-linking Recursion | $O(N)$ | $O(1)$ |
| 10 | Append Last N Nodes to Front | 🟡 Medium | Circular Connect & Break | $O(N)$ | $O(1)$ |
| 11 | Segregate Odd and Even Nodes | 🟡 Medium | Separate Odd/Even Heads & Stitch | $O(N)$ | $O(1)$ |
| 12 | Reverse Nodes in K-Group | 🟡 Medium | Sub-list Reversal Iteration | $O(N)$ | $O(1)$ |
| 13 | Reorder List ($L_0 \to L_n \to L_1 \dots$) | 🟡 Medium | Mid Split + Reverse + Weave | $O(N)$ | $O(1)$ |
| 14 | Clone LL with Random & Next Pointer | 🟡 Medium | Interleaving Cloned Nodes | $O(N)$ | $O(1)$ |
| 15 | Quick Sort on Linked List | 🔴 Hard | Lomuto Partition with Tail Tracking | $O(N \log N)$ | $O(\log N)$ |
| 16 | Convert Sorted Linked List to BST | 🔴 Hard | Inorder Simulation with Slow/Fast | $O(N \log N)$ | $O(\log N)$ |

</details>

---

### 10. Binary Trees

> **Intuition:** Non-linear hierarchical representations. DFS (Preorder, Inorder, Postorder) uses the call stack for subproblem decomposition; BFS (Level Order) uses a queue for topological levels and shortest paths.

<details open>
<summary><b>Click to expand / collapse Binary Trees Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Inorder Traversal (L-Root-R) | 🟢 Easy | Recursive DFS | $O(N)$ | $O(H)$ |
| 02 | Preorder Traversal (Root-L-R) | 🟢 Easy | Recursive DFS | $O(N)$ | $O(H)$ |
| 03 | Postorder Traversal (L-R-Root) | 🟢 Easy | Recursive DFS | $O(N)$ | $O(H)$ |
| 04 | Level Order Traversal (BFS) | 🟢 Easy | FIFO Queue Level Iteration | $O(N)$ | $O(W)$ |
| 05 | Inorder Traversal Using Stack | 🟢 Easy | Explicit Call Stack Simulation | $O(N)$ | $O(H)$ |
| 06 | Maximum Height / Depth of Tree | 🟡 Medium | $1 + \max(\text{left}, \text{right})$ | $O(N)$ | $O(H)$ |
| 07 | Diameter of Binary Tree | 🟡 Medium | Bottom-Up Height Accumulator | $O(N)$ | $O(H)$ |
| 08 | Lowest Common Ancestor (LCA) | 🟡 Medium | Postorder Node Propagation | $O(N)$ | $O(H)$ |
| 09 | Mirror / Invert Binary Tree | 🟡 Medium | Recursive Child Node Swap | $O(N)$ | $O(H)$ |
| 10 | Check if Tree is Height-Balanced | 🟡 Medium | Depth-Aware Bottom-Up Check | $O(N)$ | $O(H)$ |
| 11 | ZigZag / Spiral Order Traversal | 🟡 Medium | Double-Ended Deque Alternation | $O(N)$ | $O(W)$ |
| 12 | Left View of Binary Tree | 🟡 Medium | DFS Level Depth Marker | $O(N)$ | $O(H)$ |
| 13 | Top View of Binary Tree | 🟡 Medium | Horizontal Distance + BFS Map | $O(N)$ | $O(N)$ |
| 14 | Bottom View of Binary Tree | 🟡 Medium | Horizontal Distance Overwrite Map | $O(N)$ | $O(N)$ |
| 15 | Lowest Common Ancestor of 3 Nodes | 🟡 Medium | Cascade LCA Decomposition | $O(N)$ | $O(H)$ |
| 16 | Time to Burn Binary Tree | 🟡 Medium | Node-to-Parent Map + BFS Wave | $O(N)$ | $O(N)$ |
| 17 | Merge Two Binary Trees | 🟡 Medium | Overlapping Node Summation | $O(N)$ | $O(H)$ |
| 18 | Flatten Binary Tree to Linked List | 🟡 Medium | Morris Preorder / Reverse Postorder | $O(N)$ | $O(1)$ |
| 19 | Serialize & Deserialize Binary Tree | 🔴 Hard | BFS Level String Serialization | $O(N)$ | $O(N)$ |
| 20 | Construct Tree from Inorder & Preorder | 🔴 Hard | Inorder Range Hash Partitioning | $O(N)$ | $O(N)$ |
| 21 | Boundary Traversal of Binary Tree | 🔴 Hard | Left Boundary + Leaves + Right Bound | $O(N)$ | $O(H)$ |

</details>

---

### 11. Binary Search Tree (BST)

> **Intuition:** A Binary Search Tree enforces the ordering invariant: $\forall x \in \text{Left}, \text{val}(x) < \text{val}(\text{Root})$ and $\forall y \in \text{Right}, \text{val}(y) > \text{val}(\text{Root})$. An Inorder traversal of a BST always yields sorted elements.

<details>
<summary><b>Click to expand / collapse BST Problems</b></summary>
<br/>

| # | Problem Title | Difficulty | Technique / Pattern | Time Complexity | Space Complexity |
| :-: | :--- | :---: | :--- | :---: | :---: |
| 01 | Validate Binary Search Tree | 🟢 Easy | Range Invariant $[\text{min}, \text{max}]$ | $O(N)$ | $O(H)$ |
| 02 | Lowest Common Ancestor in BST | 🟡 Medium | Split-Point Value Divergence | $O(H)$ | $O(1)$ |
| 03 | Delete Node in a BST | 🟡 Medium | Inorder Successor Replacement | $O(H)$ | $O(H)$ |
| 04 | K-th Smallest Element in BST | 🟡 Medium | Inorder Traversal Early Exit | $O(H + K)$ | $O(H)$ |
| 05 | Inorder Predecessor & Successor | 🟡 Medium | Step Down Traversal | $O(H)$ | $O(1)$ |
| 06 | Two Sum in BST (Pair with Target) | 🟡 Medium | Dual BST Iterators (Next & Before) | $O(N)$ | $O(H)$ |
| 07 | Remove Keys Outside Given Range | 🟡 Medium | BST Trimming Property | $O(N)$ | $O(H)$ |
| 08 | BST Iterator (Next & HasNext in $O(1)$) | 🟡 Medium | Controlled Stack Inorder Push | $O(1)$ avg | $O(H)$ |
| 09 | Merge Two Balanced BSTs | 🟡 Medium | Inorder Arrays + Sorted Array to BST | $O(M + N)$ | $O(M + N)$ |
| 10 | Recover BST (Fix Swapped Nodes) | 🟡 Medium | Morris / Inorder Anomaly Detection | $O(N)$ | $O(1)$ |

</details>

---

## 🧠 Essential Algorithmic Patterns & Templates

Mastering patterns enables solving hundreds of interview variations effortlessly.

### 1. Kadane's Algorithm (Maximum Subarray Sum)
```cpp
// Finds the maximum contiguous subarray sum in O(N) time and O(1) space
long long maxSubarraySum(const vector<int>& arr) {
    long long currentMax = 0, globalMax = LLONG_MIN;
    for (int num : arr) {
        currentMax = max((long long)num, currentMax + num);
        globalMax = max(globalMax, currentMax);
    }
    return globalMax;
}
```

### 2. Variable-Sized Sliding Window Pattern
```cpp
// Template for: Longest substring/subarray meeting condition C
int longestSubarrayWithCondition(const vector<int>& arr, int target) {
    int left = 0, maxLength = 0;
    // Window state variables (e.g. sum, count, freq map)
    
    for (int right = 0; right < (int)arr.size(); ++right) {
        // 1. Expand window: add arr[right] to state
        
        // 2. Shrink window while condition is violated
        while (/* window state violates condition */) {
            // remove arr[left] from state
            left++;
        }
        
        // 3. Update answer
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}
```

### 3. Binary Search on Monotonic Answer Space
```cpp
// Template for: Minimum capacity / speed / distance satisfying check()
bool isPossible(long long mid, const vector<int>& arr, int k);

long long binarySearchOnAnswer(const vector<int>& arr, int k) {
    long long low = 1, high = 1e14; // Search space boundaries
    long long ans = high;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(mid, arr, k)) {
            ans = mid;        // Candidate answer recorded
            high = mid - 1;   // Try smaller valid values
        } else {
            low = mid + 1;    // Infeasible, increase lower bound
        }
    }
    return ans;
}
```

### 4. Fast I/O Template for Competitive Programming
```cpp
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fastio();
    // Your solution here
    return 0;
}
```

---

## ⏱️ Time & Space Complexity Cheat Sheet

### C++ Standard Library Containers

| Container | Internal Structure | Access | Search | Insertion | Deletion |
| :--- | :--- | :---: | :---: | :---: | :---: |
| `std::vector` | Dynamic Contiguous Array | $O(1)$ | $O(N)$ | $O(1)$ amortized (back) | $O(1)$ (back) |
| `std::deque` | Chunked Fixed-Size Arrays | $O(1)$ | $O(N)$ | $O(1)$ (front/back) | $O(1)$ (front/back) |
| `std::list` | Doubly Linked List | $O(N)$ | $O(N)$ | $O(1)$ (with iterator) | $O(1)$ (with iterator) |
| `std::set` / `map` | Red-Black Tree (Self-Balancing) | — | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ |
| `std::unordered_map` | Hash Table with Buckets | — | $O(1)$ avg, $O(N)$ worst | $O(1)$ avg, $O(N)$ worst | $O(1)$ avg, $O(N)$ worst |
| `std::priority_queue` | Binary Max/Min Heap | $O(1)$ (top) | — | $O(\log N)$ (push) | $O(\log N)$ (pop) |

### Sorting Algorithms Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable? | Key Mechanism |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Bubble Sort** | $O(N)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | Yes | Adjacent swaps with early termination |
| **Insertion Sort** | $O(N)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | Yes | Insert into sorted prefix |
| **Selection Sort** | $O(N^2)$ | $O(N^2)$ | $O(N^2)$ | $O(1)$ | No | Pick minimum and swap |
| **Merge Sort** | $O(N \log N)$ | $O(N \log N)$ | $O(N \log N)$ | $O(N)$ | Yes | Divide & conquer |
| **Quick Sort** | $O(N \log N)$ | $O(N \log N)$ | $O(N^2)$ | $O(\log N)$ | No | Partition around pivot |
| **Heap Sort** | $O(N \log N)$ | $O(N \log N)$ | $O(N \log N)$ | $O(1)$ | No | Build max-heap & extract root |
| **Counting Sort** | $O(N + K)$ | $O(N + K)$ | $O(N + K)$ | $O(K)$ | Yes | Value frequency prefix sum |

---

## 🎯 High-Impact Interview Edge Cases Checklist

Never submit without verifying against these classic trap scenarios:

1. **Integer Overflow:**
   - Always cast products to `long long`: `1LL * arr[i] * arr[j]` instead of `arr[i] * arr[j]`.
   - In Binary Search, compute midpoint via `low + (high - low) / 2` rather than `(low + high) / 2`.
2. **Empty & Single Element Collections:**
   - Ensure loops handle $N = 0$ and $N = 1$ without out-of-bounds segfaults.
3. **All Identical Elements:**
   - Test cases where array elements are equal (e.g., `[5, 5, 5, 5]`) to prevent infinite two-pointer loops.
4. **All Negative Numbers:**
   - For maximum subarray problems, initialize tracking variables to `INT_MIN` or `LLONG_MIN`, never `0`.
5. **Rotated & Cyclic Offsets:**
   - When shifting by $K$, sanitize with `k = k % N` to avoid redundant loops or buffer overflows.

---

## 🚀 How to Compile & Run

All solutions are written in clean, standard C++17 without external dependencies.

### Command-Line Compilation (GCC / Clang)

```bash
# Compile with optimizations and warnings enabled
g++ -std=c++17 -O2 -Wall "1. Arrays/Easy/1_Largest-Smallest_in_Array.cpp" -o solution

# Execute binary (Linux / macOS)
./solution

# Execute binary (Windows PowerShell)
.\solution.exe
```

---

<div align="center">
  <sub>Curated for focused DSA mastery and algorithmic problem-solving excellence.</sub>
</div>
