# 📅 Daily CP Solutions — 2026-04-01

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Consecutive 1S Not Allowed
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to count binary strings of length N that do not contain consecutive '1's. This specific constraint leads to a Fibonacci-like recurrence relation.

Approach:
The solution employs an iterative dynamic programming approach. It calculates the count for length N by utilizing the counts for lengths N-1 and N-2, mirroring the Fibonacci sequence where the current term is the sum of the two preceding terms.

Time Complexity:
O(N)
The loop iterates N-2 times to compute the N-th term based on previous terms.

Space Complexity:
O(1)
The solution uses only a constant number of variables (a, b) to store previous counts.

Optimization Notes:
The solution is optimal in both time and space complexity for an iterative approach. It directly implements the linear recurrence relation in linear time and constant space. For extremely large N, matrix exponentiation could compute the N-th term in O(log N) time, but for typical competitive programming constraints where N allows an O(N) solution, this iterative method is efficient and often preferred due to lower constant factors.

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
This problem simulates robot collisions on a 1D line where health determines survival. The key is to process robots by their initial position, handling collisions between robots moving towards each other.

Approach:
Robots are first sorted by their starting positions. A stack tracks robots moving right. When a robot moving left is encountered, it repeatedly collides with the top robot on the stack (moving right) until one or both are destroyed or the stack is empty.

Time Complexity:
O(N log N)
Sorting the robot indices by position takes O(N log N). The subsequent loop and stack operations are O(N) as each robot is pushed and popped at most once.

Space Complexity:
O(N)
An auxiliary vector is used to store sorted indices, and the stack can store up to N robot indices.

Optimization Notes:
The solution is optimal. Sorting by position is a prerequisite, and the stack-based simulation processes collisions efficiently in linear time after sorting. No further asymptotic improvements are possible.

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
