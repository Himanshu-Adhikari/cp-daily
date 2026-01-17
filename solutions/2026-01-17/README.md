# 📅 Daily CP Solutions — 2026-01-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Expression Contrain Redundant Brackets Or Not
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to detect if an arithmetic expression contains any redundant parentheses, where a redundant pair encloses an expression that would be valid without them. This occurs when a pair of parentheses encloses nothing or only another parenthesized subexpression.

Approach:
The solution utilizes a stack to process the expression. It pushes opening parentheses and operators onto the stack. Upon encountering a closing parenthesis, it checks if the top of the stack is an opening parenthesis; if true, it immediately signifies redundancy. Otherwise, it pops operators until the matching opening parenthesis is found, indicating a non-redundant subexpression.

Time Complexity:
O(N) where N is the length of the input string. Each character is processed once, and stack operations are amortized O(1).

Space Complexity:
O(N) in the worst case. The stack can hold up to N characters, for example, in a deeply nested expression like "((((a+b))))".

Optimization Notes:
The solution is optimal in both time and space complexity. A linear scan is necessary to check all characters, and a stack-based approach typically uses linear space in the worst case for nested structures. No further asymptotic improvements are generally possible for this type of problem.

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

## 🔹 Leetcode 3047 Find The Largest Area Of Square Inside Two Rectangles
**Platform:** LeetCode

Problem Insight:
The goal is to find the largest area of a square that can be fully contained within the intersection of any two given rectangles. The side length of such a square is limited by the minimum of the intersection's width and height.

Approach:
The solution iterates through all unique pairs of rectangles. For each pair, it calculates the width and height of their overlapping region. The side length of the largest square within this overlap is the minimum of its width and height, and this is used to update the maximum square area found so far.

Time Complexity:
O(N^2)
The algorithm involves nested loops iterating through N rectangles to check all N*(N-1)/2 unique pairs, with each pair processed in constant time.

Space Complexity:
O(1)
The solution uses a constant amount of auxiliary space for variables regardless of the input size.

Optimization Notes:
This approach is optimal for the given problem. Since we need to consider all possible pairs of rectangles to find their intersections, an O(N^2) complexity is generally required, and there isn't a faster general geometric algorithm for this specific problem without additional constraints.

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
