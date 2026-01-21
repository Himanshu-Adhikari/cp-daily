# 📅 Daily CP Solutions — 2026-01-21

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Stock Span Problem
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the maximum number of consecutive preceding days (including the current day) for which the stock price was less than or equal to the current day's price. This can be rephrased as finding the index of the first element to the left that is strictly greater than the current element.

Approach:
The solution uses a monotonic stack to store indices. It iterates through the array from right to left. When processing an element, it pops indices from the stack whose corresponding array values are smaller than the current element, calculating their span (distance to the current element's index). Elements remaining in the stack after the main loop are those for which no greater element was found to their left, and their span is calculated based on their index from the start.

Time Complexity:
O(N)
Each element is pushed onto the stack once and popped from the stack at most once.

Space Complexity:
O(N)
In the worst case (e.g., a strictly decreasing array), the stack can store up to N indices.

Optimization Notes:
The solution is optimal. It processes each element of the input array in constant amortized time, leading to overall linear time complexity. The space complexity is also optimal as the stack might need to store all elements in certain worst-case scenarios.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        vector<int>res(n,1);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]<arr[i]){
                res[s.top()]=s.top()-i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){res[s.top()]+=s.top();s.pop();}
        return res;
    }
};
```

## 🔹 Leetcode 3315 Construct-The-Minimum-Bitwise-Array-Ii
**Platform:** LeetCode

Problem Insight:
For each odd input number n, the task is to compute a transformed value x by identifying the rightmost zero-bit at index i in n, then clearing the (i-1)-th bit of n. Even numbers are mapped to -1.

Approach:
The solution iterates through each number in the input array. If a number is odd, it calculates z using the expression ((n + 1) & ~n) >> 1, which effectively isolates the (i-1)-th bit, where i is the index of the rightmost zero-bit of n. This bit is then cleared from n via n & ~z. If a number is even, -1 is stored in the result.

Time Complexity:
O(N) because the solution iterates through N numbers and performs constant-time bitwise operations for each.

Space Complexity:
O(N) to store the resultant vector, which has the same size as the input vector.

Optimization Notes:
The solution is optimal. It processes each input number once with constant-time bitwise operations, which is the most efficient way to compute the required transformation for each element.

### 💻 Implementation
```py
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (auto& n : nums) {
            if (n & 1) {
                auto z = ((n + 1) & ~n) >> 1;
                res.push_back(n & ~z);
            } else
                res.push_back(-1);
        }
        return res;
    }
};
```
