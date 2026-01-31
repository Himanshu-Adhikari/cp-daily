# 📅 Daily CP Solutions — 2026-01-31

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Implement-K-Queues-In-A-Single-Array
**Platform:** GeeksforGeeks

Problem Insight:
This code implements k separate queues that share a single underlying total capacity 'n'. It allows elements to be enqueued and dequeued from specific queues while respecting the global limit.

Approach:
The solution uses a map to store k distinct standard library queue objects, indexed by their ID. A global counter tracks the total elements across all queues to enforce the shared capacity constraint.

Time Complexity:
O(log k)
Enqueue and dequeue operations involve map lookups (O(log k)) and standard queue operations (O(1) amortized).

Space Complexity:
O(n + k)
The map stores k entries, and a total of 'n' elements can be stored across all k queues.

Optimization Notes:
The solution is not optimal for the classic k queues in a single array problem, which typically achieves O(1) time complexity. Using std::map results in O(log k) for enqueue/dequeue due to map lookup. If 'k' is small and fixed, an array of std::queue objects could provide O(1) operations. For a strict "single array" constraint, a custom implementation with index management would be needed.

### 💻 Implementation
```cpp
class kQueues {

  public:
    int sz;
    int k,curr;
    map<int,queue<int>>m;
    kQueues(int n, int k) {
        sz=n;
        this->k=k;
        curr=0;
    }
    void enqueue(int x, int i) {
        if(curr<sz){m[i].push(x);curr+=1;}
    }

    int dequeue(int i) {
        if(m[i].empty())return -1;
        int res=m[i].front();m[i].pop();
        curr-=1;
        return res;
    }

    bool isEmpty(int i) {
        return m[i].empty();
    }

    bool isFull() {
        return curr==sz;
    }
};

```

## 🔹 Leetcode 744 Find-Smallest-Letter-Greater-Than-Target
**Platform:** LeetCode

Problem Insight:
The problem requires finding the smallest character in a sorted list that is strictly greater than a given target. If no such character exists, the first character of the list should be returned.

Approach:
The solution iterates through the list of characters sequentially. It keeps track of the smallest character found so far that is greater than the target, initializing the result to the first character of the list.

Time Complexity:
O(N)
The algorithm iterates through all N characters in the input list in the worst case.

Space Complexity:
O(1)
Only a fixed number of variables are used for storage regardless of the input size.

Optimization Notes:
The solution is not optimal. Since the input list is sorted, binary search could be used to find the next greatest letter in O(log N) time. The current linear scan approach has an O(N) time complexity.

### 💻 Implementation
```py
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        mn,res=float('inf'),letters[0]
        for i in letters:
            cst=(ord(i)-ord(target))
            if(i>target and mn>cst):
                res,mn=i,cst
        return res
```
