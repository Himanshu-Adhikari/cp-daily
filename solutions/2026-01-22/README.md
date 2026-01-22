# 📅 Daily CP Solutions — 2026-01-22

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Sum-Of-Subarray-Ranges
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the sum of ranges (max - min) over all possible subarrays. This can be decomposed into (sum of maximums over all subarrays) - (sum of minimums over all subarrays).

Approach:
The solution uses a monotonic stack twice. The first pass calculates the sum of minimums by iterating and identifying for each element v[idx] the number of subarrays where it is the minimum. The second pass similarly calculates the sum of maximums. The final answer is the difference.

Time Complexity:
O(N)
Each element is pushed onto the stack and popped from the stack at most once across both passes, making the total operations proportional to N.

Space Complexity:
O(N)
The stack can hold up to N elements in the worst case (e.g., a sorted array).

Optimization Notes:
This solution is optimal. The problem requires examining all elements, and a linear time O(N) solution using O(N) space is generally the best achievable for this class of problems using a monotonic stack.

### 💻 Implementation
```cpp
class Solution {
  public:
    int subarrayRanges(vector<int>& v) {
        int n = v.size();
        long long ans = 0;
        stack<int> st;
        for(int i = 0; i <= n; i++){
            int x;
            if(i == n) x = INT_MIN;
            else x = v[i];
            while(st.size() && v[st.top()] >= x){
                int idx = st.top(), l = -1;
                st.pop();
                if(st.size()) l = st.top();
                ans -= (i-idx)*(idx-l)*v[idx];
            }
            
            if(i < n)
            st.push(i);
        }
        for(int i = 0; i <= n; i++){
            int x;
            if(i == n) x = INT_MAX;
            else x = v[i];
            while(st.size() && v[st.top()] <= x){
                int idx = st.top(), l = -1;
                st.pop();
                if(st.size()) l = st.top();
                ans += (i-idx)*(idx-l)*v[idx];
            }
            
            if(i < n)
            st.push(i);
        }
        return int(ans);
    }
};
```
