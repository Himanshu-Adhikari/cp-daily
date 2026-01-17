# 📅 Daily CP Solutions — 2026-01-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Expression Contrain Redundant Brackets Or Not
**Platform:** GeeksforGeeks

Problem Insight:
This solution aims to identify redundant parentheses in an arithmetic expression, where redundancy means a subexpression is enclosed in parentheses but doesn't strictly need them. Examples include `(a)` or `((a+b))`.

Approach:
The solution uses a stack to keep track of opening parentheses and operators. When a closing parenthesis is encountered, it checks if the top of the stack is an opening parenthesis, which signals redundancy. Otherwise, it pops operators until the matching opening parenthesis is found and then pops the opening parenthesis.

Time Complexity:
O(N)
The solution iterates through the string once, and each character is pushed and popped from the stack at most once.

Space Complexity:
O(N)
In the worst case (e.g., deeply nested parentheses), the stack may store up to N/2 elements, where N is the length of the string.

Optimization Notes:
The solution is optimal in terms of time complexity as it requires a single pass through the expression. The space complexity is also optimal because the stack may need to store a significant portion of the input for deeply nested expressions. No significant improvements are apparent.

### 💻 Implementation
```py
class Solution():
    def checkRedundancy(self, s):
        st,aux=[],"+-/*"
        i,n=0,len(s)
        while(i<n):
            if(s[i]=='(' or s[i] in aux):
                st.append(s[i])
            elif(s[i]==')'):
                if(st[-1]=='('):
                    return True
                while(st and st[-1]!='('):
                    st.pop()
                st.pop()
            i+=1
        return False
```

## 🔹 Leetcode 3047 Find The Largest Area Of Square Inside Two Rectangles
**Platform:** LeetCode

Problem Insight:
The problem requires finding the largest possible square that can be formed by the intersecting region of any two distinct rectangles from a given set. This means identifying overlaps and their effective dimensions.

Approach:
The solution systematically checks every unique pair of rectangles. For each pair, it calculates the width and height of their intersection. The maximum side length of a square that fits within this intersection is then determined, and its area is used to update the overall maximum found so far.

Time Complexity: O(N^2)
The solution uses nested loops to iterate through all N*(N-1)/2 unique pairs of rectangles, with each pair's intersection calculation taking constant time.

Space Complexity: O(1)
The solution uses a fixed number of variables to store results and temporary calculations, independent of the input size N.

Optimization Notes:
The solution is optimal for the given general problem. For arbitrary rectangle configurations, it is necessary to check all possible pairs to guarantee finding the maximum intersecting square, as there are no obvious geometric properties that would allow skipping pairs without potentially missing the optimal answer.

### 💻 Implementation
```cpp
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        #define ll long long
        ll res=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wdth=min(topRight[i][0],topRight[j][0])-
                max(bottomLeft[i][0],bottomLeft[j][0]);
                int hgth=min(topRight[i][1],topRight[j][1])-
                max(bottomLeft[i][1],bottomLeft[j][1]);
                int sd=min(wdth,hgth);
                res=max(res,sd>0?1ll*sd*sd:0);
            }
        }
        return res;
    }
};
```
