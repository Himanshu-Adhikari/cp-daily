# 📅 Daily CP Solutions — 2026-04-01

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Consecutive 1S Not Allowed
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to count binary strings of length N that do not contain consecutive 1s. This specific counting problem follows a recurrence relation similar to the Fibonacci sequence.

Approach:
The solution uses an iterative dynamic programming approach. It recognizes that the number of valid strings for length N can be derived from the counts for lengths N-1 and N-2, effectively computing the N-th term of a modified Fibonacci sequence with appropriate base cases.

Time Complexity:
O(N)
The solution iterates N-2 times in the worst case, performing constant time operations in each step.

Space Complexity:
O(1)
Only a constant number of variables are used to store the previous two sequence values, independent of N.

Optimization Notes:
It is optimal. The solution calculates the N-th term of the recurrence relation iteratively in linear time and constant space, which is the most efficient method for typical N without resorting to matrix exponentiation (which has higher constant factors).

### 💻 Implementation
```py
class Solution:
	def countStrings(self,n):
    	if n == 1:
            return 2
        if n == 2:
            return 3
        a, b = 2, 3
        for _ in range(3, n + 1):
            a, b = b, a + b
            
        return b

```

## 🔹 Leetcode Robot Collisions
**Platform:** LeetCode

Problem Insight:
Collisions only occur between right-moving and left-moving robots. Processing robots in order of their initial positions is crucial to correctly simulate interactions.

Approach:
Robots are processed in increasing order of their initial positions. A stack tracks right-moving robots awaiting potential collisions. When a left-moving robot is encountered, it battles robots on the stack until it is destroyed or the stack is empty.

Time Complexity:
O(N log N)
Sorting the robot indices by position takes O(N log N), and the subsequent stack-based simulation processes each robot and collision in amortized O(N) time.

Space Complexity:
O(N)
An auxiliary vector stores sorted indices, the stack stores active robots, and the result vector stores surviving robots, all requiring O(N) space.

Optimization Notes:
Optimal. Sorting by position is a necessary step, setting an O(N log N) lower bound. The stack-based simulation efficiently handles collisions in O(N) amortized time, making the overall approach optimal.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& ps, vector<int>& h,
                                      string d) {
        stack<int> st;
        int n = ps.size();
        vector<int> v(n), res;
        iota(begin(v), end(v), 0);
        sort(begin(v), end(v), [&](int a, int b) { return ps[a] < ps[b]; });
        for (int i : v) {
            if (d[i] != 'L')
                st.push(i);
            else {
                while (!st.empty() && h[i]) {
                    if (h[st.top()] > h[i])
                        h[i] = 0, h[st.top()]--;
                    else if (h[st.top()] < h[i])
                        h[i]--, h[st.top()] = 0, st.pop();
                    else
                        h[i] = h[st.top()] = 0,st.pop();
                }
            }
        }
        for (auto c : h)
            if (c)
                res.push_back(c);
        return res;
    }
};
```
