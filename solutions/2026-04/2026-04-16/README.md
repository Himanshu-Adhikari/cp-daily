# 📅 Daily CP Solutions — 2026-04-16

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Implement Atoi
**Platform:** GeeksforGeeks

Problem Insight:
The problem tests careful parsing of a string to an integer, requiring precise handling of leading whitespace, signs, non-digit characters, and most importantly, integer overflow.

Approach:
The solution sequentially processes the string: skipping whitespace, determining the sign, then iteratively building the numeric result from digits. It includes critical overflow checks after each digit is processed, returning INT_MAX or INT_MIN immediately if the current result exceeds integer limits.

Time Complexity:
O(N)
The solution iterates through the input string at most once, where N is the length of the string.

Space Complexity:
O(1)
Only a fixed number of variables are used regardless of the input string's length.

Optimization Notes:
The solution is optimal. It achieves O(N) time complexity by making a single pass through the string and O(1) space complexity by using only a few constant variables, which is the best possible for this problem.

### 💻 Implementation
```cpp
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // 4. Handle overflow
            if (sign * res >= INT_MAX) return INT_MAX;
            if (sign * res <= INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};
```

## 🔹 Leetcode Closest-Equal-Element-Queries
**Platform:** LeetCode

Problem Insight:
For each queried index, the task is to find the minimum cyclic distance to another element in the array that has the exact same value.

Approach:
The solution preprocesses the array by storing all indices for each unique number in a map, where keys are numbers and values are sorted lists of their occurrences. For each query, it locates the query index within its corresponding sorted list using binary search. It then calculates the minimum cyclic distance to the two adjacent elements (left and right) in that sorted list.

Time Complexity:
O(N + Q log N)
Preprocessing takes O(N) to populate the map of vectors. Each query involves a map lookup (O(log U), U unique numbers) and a binary search on a vector (O(log K), K occurrences), resulting in O(log N) per query for Q queries.

Space Complexity:
O(N + Q)
The map stores all N indices across its value vectors (O(N)), and the answer vector stores Q results (O(Q)).

Optimization Notes:
The solution is largely optimal for this problem. The preprocessing allows for efficient logarithmic time queries. Using an unordered_map instead of a map could reduce the average time for map lookups to O(1), making queries O(log N) on average, but worst-case performance might suffer. The current cyclic distance calculation and neighbor retrieval are robust and efficient.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
     vector<int>ans;
     map<int,vector<int>>m;
     int n=nums.size();
     for(int i=0;i<n;i++)m[nums[i]].push_back(i);
     for(int &i:queries){
        int vl=nums[i];
        if(int(m[vl].size())==1)ans.push_back(-1);
        else {
            auto it = lower_bound(m[vl].begin(), m[vl].end(), i);
            int idx = it - m[vl].begin();
            int res = INT_MAX;
            int left = (idx - 1 + m[vl].size()) % m[vl].size();
            int leftDist = abs(i - m[vl][left]);
            leftDist = min(leftDist, n - leftDist);
             int right = (idx + 1) % m[vl].size();
            int rightDist = abs(m[vl][right] - i);
            rightDist = min(rightDist, n - rightDist);
            res = min(leftDist, rightDist);
            ans.push_back(res);
        }
     }
     return ans;   
    }
};
```
