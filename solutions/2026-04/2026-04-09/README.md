# 📅 Daily CP Solutions — 2026-04-09

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Intersection-Of-Two-Sorted-Arrays-With-Duplicate-Elements
**Platform:** GeeksforGeeks

Problem Insight:
Finding common elements between two lists is efficiently done by leveraging hash tables (sets) for fast average-case lookups. This avoids O(N*M) comparisons.

Approach:
The solution converts both input lists into hash sets to enable O(1) average-case element lookups. It then iterates through one set, checking for the presence of each element in the other set, collecting common elements into a list. Finally, the collected intersection elements are sorted.

Time Complexity:
O(N + M + K log K) where N and M are lengths of inputs, and K is the size of the intersection. Converting lists to sets takes O(N+M) average, iterating and checking takes O(min(N,M)) average, and sorting K results takes O(K log K).

Space Complexity:
O(N + M) where N and M are lengths of inputs. Two sets are created to store unique elements from input lists, and a list for the result.

Optimization Notes:
This approach is optimal for average-case time performance, particularly when the result needs to be sorted. If sorting the final result is not a strict requirement, the res.sort() call can be removed to reduce the time complexity to O(N + M). Python's built-in set intersection operator (set1 & set2) offers a more concise way to achieve the same core logic.

### 💻 Implementation
```py
class Solution:
    def intersection(self,a, b):
        res=[]
        a1=set(a)
        a2=set(b)
        for i in a1:
            if( i in a2):res.append(i)
        res.sort()
        return res
        
```

## 🔹 Leetcode Xor-After-Range-Multiplication-Queries-Ii
**Platform:** LeetCode

Problem Insight:
The problem requires applying multiplicative updates to arithmetic progressions within an array and then computing the XOR sum of the final array elements. Updates are modulo a prime.

Approach:
The solution uses square root decomposition, splitting queries into two types based on the step size k. Queries with k smaller than sqrt(N) are batched by k, and for each small k, a difference array approach is used to apply all updates efficiently. Queries with k larger than or equal to sqrt(N) are processed directly by iterating through the affected elements.

Time Complexity:
O(N^1.5 + Q * N^0.5)
Processing large k queries takes O(Q * N/sqrt(N)) = O(Q * N^0.5). Processing small k queries involves an O(N) initialization and O(N) propagation for each of the sqrt(N) distinct small k values, leading to O(sqrt(N) * N) = O(N^1.5).

Space Complexity:
O(N + Q)
The solution stores the array nums (O(N)), a temporary difference array dif (O(N)), and the queries in groups (O(Q)).

Optimization Notes:
This square root decomposition approach is generally considered optimal for this type of problem involving range updates on arithmetic progressions, where simpler data structures like segment trees are not directly applicable due to the step parameter. The choice of sqrt(N) as the threshold for k balances the complexity contributions from small and large k queries.

### 💻 Implementation
```py
class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        T = int(n**0.5)

        groups = [[] for _ in range(T)]
        for l, r, k, v in queries:
            if k < T:
                groups[k].append((l, r, v))
            else:
                for i in range(l, r + 1, k):
                    nums[i] = nums[i] * v % mod

        dif = [1] * (n + T)
        for k in range(1, T):
            if not groups[k]:
                continue
            dif[:] = [1] * len(dif)
            for l, r, v in groups[k]:
                dif[l] = dif[l] * v % mod
                R = ((r - l) // k + 1) * k + l
                dif[R] = dif[R] * pow(v, mod - 2, mod) % mod

            for i in range(k, n):
                dif[i] = dif[i] * dif[i - k] % mod
            for i in range(n):
                nums[i] = nums[i] * dif[i] % mod

        res = 0
        for x in nums:
            res ^= x
        return res
```
