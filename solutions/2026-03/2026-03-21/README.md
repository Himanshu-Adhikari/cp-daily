# 📅 Daily CP Solutions — 2026-03-21

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg No Of Bst From Array
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to calculate the number of unique Binary Search Trees (BSTs) for each element in an array, considering it as the root of a BST formed from the entire array's elements. The count depends on the number of elements smaller and larger than the chosen root.

Approach:
The solution precomputes Catalan numbers, which count BSTs for a given number of nodes. For each element in the input array, it determines its rank (number of smaller elements) by sorting a copy. This rank defines the sizes of the left and right subtrees, whose BST counts are then multiplied using the precomputed Catalan numbers.

Time Complexity:
O(N^2) because sorting takes O(N log N), Catalan number precomputation takes O(N^2), and iterating through elements with lower_bound takes O(N log N).

Space Complexity:
O(N) because it stores a copy of the input array, the precomputed Catalan numbers, and the results vector, all proportional to N.

Optimization Notes:
The current solution is not optimal due to its O(N^2) precomputation of Catalan numbers. This can be improved to O(N) by using the recurrence relation C_n = (2 * (2n - 1) / (n + 1)) * C_(n-1). If optimized, the overall time complexity would be O(N log N) dominated by sorting and lower_bound operations.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
           int n = arr.size();
        vector<int> ans;
        vector<int> vec = arr;
        sort(vec.begin(), vec.end());

        // Precompute Catalan numbers up to n
        vector<long long> cat(n + 1, 0);
        cat[0] = cat[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                cat[i] += cat[j] * cat[i - j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            int left = idx;              // elements smaller than arr[i]
            int right = n - idx - 1;     // elements greater than arr[i]
            
            long long total = cat[left] * cat[right];
            ans.push_back((int)total);
        }
        return ans;
    }
};
```

## 🔹 Leetcode Flip-Square-Submatrix-Vertically
**Platform:** LeetCode

Problem Insight:
The problem describes modifying a kxk submatrix. The provided solution implements a row-wise reversal of this submatrix, effectively swapping its first row with the last, second with second-to-last, and so on.

Approach:
The solution uses two row pointers, one starting at the top (x) and one at the bottom (x+k-1) of the target submatrix. It iteratively swaps the elements of the entire current 'top' row with the corresponding elements of the 'bottom' row, then moves the pointers inwards until they meet.

Time Complexity:
O(k^2)
The outer loop runs k/2 times, and the inner loop performs k swaps, processing all k*k elements within the submatrix.

Space Complexity:
O(1)
The algorithm modifies the grid in-place and uses a constant amount of auxiliary space.

Optimization Notes:
This solution is optimal for the task of reversing the rows within a kxk submatrix. It directly accesses and modifies each of the k*k elements involved, which is the minimum number of operations required to perform this transformation.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size(),m=grid[0].size();
        int ik=x+k-1;
        while(x<ik){
            for(int i=y;i<y+k;i++){
                swap(grid[x][i],grid[ik][i]);
            }
            x++,ik--;
        }
        return grid;
    }
};
```
