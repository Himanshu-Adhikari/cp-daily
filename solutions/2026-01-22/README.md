# 📅 Daily CP Solutions — 2026-01-22

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Sum-Of-Subarray-Ranges
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the sum of ranges (maximum - minimum) for all possible subarrays. This can be equivalently calculated as the sum of all maximums minus the sum of all minimums over all subarrays.

Approach:
The solution uses a monotonic stack. It iterates through the array twice. The first pass calculates the sum of (element * count) where 'count' is the number of subarrays in which the element is the minimum. The second pass similarly calculates the sum where the element is the maximum. The final answer is the difference between these two sums.

Time Complexity:
O(N)
Each element is pushed onto the stack and popped from it at most once in each of the two passes, resulting in linear time complexity.

Space Complexity:
O(N)
The monotonic stack can, in the worst case, store all N elements of the input array.

Optimization Notes:
The solution is optimal. It achieves O(N) time complexity, which is the theoretical lower bound since every element must be processed at least once. The O(N) space complexity for the auxiliary stack is also efficient for this problem type.

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

## 🔹 Leetcode Minimum-Pair-Removal-To-Sort-Array-I
**Platform:** LeetCode

Problem Insight:
The problem asks for the minimum number of operations to make an array sorted. An operation consists of finding an adjacent pair with the minimum sum, replacing the pair with their sum, and incrementing an operation counter.

Approach:
The solution employs a greedy iterative approach. In each step, it scans the current array to find the adjacent pair (nums[i], nums[i+1]) that has the smallest sum. It then merges this pair into a single element (their sum) in a new array, effectively reducing the array size by one. This process continues, counting each merge as an operation, until the array becomes sorted.

Time Complexity:
O(N^2)
In each of the N-1 operations (to reduce an array of size N to size 1), the solution performs an O(N) scan to find the minimum sum pair, an O(N) operation to build the new array, and an O(N) operation for is_sorted check.

Space Complexity:
O(N)
A temporary vector 't' of size up to N is created in each iteration to store the modified array, requiring O(N) auxiliary space.

Optimization Notes:
The current solution is not optimal in terms of time complexity for its chosen strategy. Each step of finding the minimum sum pair and rebuilding the array takes O(N). This can be improved to O(logN) per step by using data structures like a segment tree or balanced binary search tree to efficiently find the minimum adjacent sum and update the array. Additionally, a similar data structure could maintain information about sortedness (e.g., count of inversions or a set of indices where nums[i] > nums[i+1]) to check sorted status in O(logN) rather than O(N). This would reduce the overall time complexity to O(N log N). However, if the problem requires finding the absolute minimum number of operations to sort, the greedy strategy of merging the smallest sum pair at each step may not be globally optimal.

### 💻 Implementation
```cpp
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size(),res=0;
        while(!is_sorted(begin(nums),end(nums))){   
            vector<int>t;
            int s=0;
            n=nums.size();
            if(n==1)break;
            for(int i=0;i<n-1;i++){
                if((nums[i]+nums[i+1] )<(nums[s]+nums[s+1]))s=i;
            }
            for(int i=0;i<n;){
                if(i==s){
                    t.push_back(nums[i]+nums[i+1]);i++;
                }
                else t.push_back(nums[i]);
                i++;
            }
            nums=t;
            res+=1;
        }
        return res;
    }
};
```
