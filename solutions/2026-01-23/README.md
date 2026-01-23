# 📅 Daily CP Solutions — 2026-01-23

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximum-People-Visible-In-A-Line
**Platform:** GeeksforGeeks

Problem Insight:
The solution employs a monotonic stack to determine specific relative indices for each element in an input array. It calculates indices for the next greater or equal element to the right and, through an array reversal and subsequent transformation, derives another set of indices, likely related to elements on the left.

Approach:
1. A helper function `rec` uses a monotonic stack to find, for each element `arr[i]`, the index `j` of the first element to its right such that `arr[j] >= arr[i]`. If none exists, `j` is set to `n` (array length).
2. This `rec` function is used to compute `f` (forward indices) on the original array and `s_raw` on the reversed array.
3. `s_raw` is then transformed using `[n-x for x in s_raw][::-1]` to produce the final `s` array.
4. The solution then finds the maximum difference `i-j` by pairing elements from the `f` and `s` arrays.

Time Complexity:
O(N)
Each call to `rec` is O(N) because elements are pushed and popped from the stack at most once. Array reversal and the final zip/max operation are also O(N).

Space Complexity:
O(N)
The stack `st` can store up to N elements. The `f`, `s_raw`, and `s` arrays each store N elements, and array reversal creates a temporary copy of N elements.

Optimization Notes:
The monotonic stack technique is optimal for efficiently finding next greater or equal elements. The specific transformation applied to `s` (derived from the reversed array) is unconventional for directly computing a standard "next greater or equal to the left" array. If the underlying problem "maxPeople" relies on a standard definition for left-side nearest greater elements, this calculation might be a point of review for correctness. However, given the code's structure, the overall time and space complexities are optimal.

### 💻 Implementation
```py
class Solution:
    def maxPeople(self, arr):
        n=len(arr)
        def rec(arr):
            st=[]
            fw=[n]*n
            for i in range(n):
                while(st and arr[st[-1]]<=arr[i]):
                    fw[st[-1]]=i
                    st.pop()
                st.append(i)
            return fw
        f,s=rec(arr),rec(arr[::-1])
        s=[n-x for x in s][::-1]
        return max(i-j for i,j in zip(f,s))
        
```

## 🔹 Leetcode Minimum-Pair-Removal-To-Sort-Array-Ii
**Platform:** LeetCode

Problem Insight:
The goal is to sort an array non-decreasingly by repeatedly merging adjacent elements, replacing them with their sum. The task is to find the minimum number of merge operations required.

Approach:
The solution uses a greedy strategy: it repeatedly merges the adjacent pair with the smallest sum until the array becomes sorted (contains no inversions). A min-priority queue stores sums of adjacent pairs, and a doubly linked list structure efficiently handles updates to neighbors after a merge.

Time Complexity:
O(N log N) because there are O(N) merges in the worst case, and each merge involves O(log N) priority queue operations.

Space Complexity:
O(N) for storing the array, doubly linked list pointers, element status, and the priority queue.

Optimization Notes:
The solution is optimal. The greedy approach of merging minimum sum pairs is well-suited for this problem, and the use of a priority queue with a doubly linked list provides efficient O(N log N) performance, which is a typical lower bound for dynamic sorting-related problems.

### 💻 Implementation
```cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> a(nums.begin(), nums.end());
        vector<int> left(n), right(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        right[n - 1] = -1;

        // Min heap: {sum, index}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({a[i] + a[i + 1], i});
        }

        // Count inversions
        int inv = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) inv++;
        }

        int ops = 0;

        while (inv > 0) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = right[i];
            if (j == -1 || !alive[i] || !alive[j] || a[i] + a[j] != sum)
                continue;

            int L = left[i], R = right[j];

            // Remove old inversions
            if (L != -1 && a[L] > a[i]) inv--;
            if (a[i] > a[j]) inv--;
            if (R != -1 && a[j] > a[R]) inv--;

            // Merge
            a[i] = sum;
            alive[j] = false;
            right[i] = R;
            if (R != -1) left[R] = i;

            // Add new inversions
            if (L != -1 && a[L] > a[i]) inv++;
            if (R != -1 && a[i] > a[R]) inv++;

            // Push new adjacent sums
            if (L != -1) pq.push({a[L] + a[i], L});
            if (R != -1) pq.push({a[i] + a[R], i});

            ops++;
        }

        return ops;
    }
};
```
